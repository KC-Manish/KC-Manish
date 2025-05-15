`timescale 1ns/1ps

`include "uvm_macros.svh"
import uvm_pkg::*;

`include "interface.sv"
`include "test_pkg.sv"

module top_tb;

   logic clk = 0;

   //clock generation
   always #5 clk = ~clk; //100mhz clock

   counter_if intf(clk);

   //Instantiate DUT
   counter u_counter (
	   .clk(intf.clk);
	   .rst(intf.rst);
	   .count(intf.count)
   );

   //UVM startup
   initial begin
      //pass the interface handle to UVM using config DB
      uvm_config_db#(virtual counter_if)::set(null, "*", "vif", intf);
      run_test();
   end

endmodule
