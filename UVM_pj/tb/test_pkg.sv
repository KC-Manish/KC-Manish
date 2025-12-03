`ifndef TEST_PKG_SV
`define TEST_PKG_SV

`include "uvm_macros.svh"
`import uvm_pkg::*;

//Include all environment files
`include "env/env.sv"
`include "agent/counter_driver.sv"
`include "agent/counter_monitor.sv"
`include "agent/counter_sequencer.sv"
`include "seq/counter_seq.sv" 
`include "test/my_test.sv"

`endif
