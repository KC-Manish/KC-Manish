// Simple synchronous FIFO (single clock)

module fifo #(
    parameter int DATA_WIDTH = 8,
    parameter int DEPTH      = 8
) (
    input  logic                     clk,
    input  logic                     rst,       // async high reset (synced inside)
    input  logic                     write_en,
    input  logic                     read_en,
    input  logic [DATA_WIDTH-1:0]    data_in,
    output logic [DATA_WIDTH-1:0]    data_out,
    output logic                     full,
    output logic                     empty
);

    localparam int PTR_W   = (DEPTH <= 2) ? 1 : $clog2(DEPTH);
    localparam int COUNT_W = $clog2(DEPTH+1);

    //Purpose
    //PTR_W decides how many bits are needed for the read pointer(rd_ptr)
    //and write pointer to index the fifo memory.
    //
    logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];
    logic [PTR_W-1:0]      wr_ptr, rd_ptr;
    logic [COUNT_W-1:0]    count;

    // status (size the RHS to LHS width to avoid WIDTHEXPAND)
    assign full  = (count == COUNT_W'(DEPTH));
    assign empty = (count == '0);

    // write/read
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            wr_ptr   <= '0;
            rd_ptr   <= '0;
            count    <= '0;
            data_out <= '0;
        end else begin
            // write path
            if (write_en && !full) begin
                mem[wr_ptr] <= data_in;
                wr_ptr <= (wr_ptr == PTR_W'(DEPTH-1)) ? '0 : (wr_ptr + 1'b1);
                count  <= count + 1'b1;
            end
            // read path
            if (read_en && !empty) begin
                data_out <= mem[rd_ptr];
                rd_ptr <= (rd_ptr == PTR_W'(DEPTH-1)) ? '0 : (rd_ptr + 1'b1);
                count  <= count - 1'b1;
            end
        end
    end

endmodule
'q!

