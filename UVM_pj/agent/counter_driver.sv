class counter_driver extends uvm_driver #(int);
	// Parameterized diver,, Use int for now as our transaction

	`uvm_component_utils(counter_driver)
	// register this component with the uvm factory so we can create it
	// dynamicly
	
	virtual counter_if vif; // Declare a handle to the vif so we can drive signals

	funtion new(string name, uvm_component parent);  // Constructor
	   super.new(name, parent);
	endfunction

	function void build_phase(uvm_phase phase);  // Build phase
	   super.build_phase(phase);
	   if (!uvm_config_db#(virtual counter_if)::get(this, "", "vif". vif))
	      `uvm_fatal("***No vif***", "Virtual interface not set for driver")
        endfunction

        task run_phase(uvm_phase phase);  // Run phase
           super.run_phase(phase);

	   `uvm_info("DRV", "Starting counter_driver run_phase", UVM_MEDIUM)

	   //Reset sequence assuming rst is active high
	   vif.rst <= 1;
	   repeat (2) @(posedge vif.clk);
	   vif.rst <= 0;
	   `uvm_info("DRV", "Deasserted reset", UVM_MEDIUM)
	endtask

endclass
