module top_tb (
	input logic clk,
	input logic rst,
	output logic [3:0] count
	);

	counter u_counter (
		.clk(clk),
		.rst(rst),
		.count(count)
		);


endmodule
