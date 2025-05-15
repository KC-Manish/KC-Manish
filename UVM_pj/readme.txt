your_project/
├── design/             # Your RTL (already exists)
│   └── counter.sv
├── tb/                 # Testbench files
│   ├── top_tb.sv       # Testbench top
│   ├── interface.sv    # SV interface for DUT connection
│   ├── test_pkg.sv     # Includes UVM classes
│
│   ├── env/            # UVM environment
│   │   └── env.sv
│
│   ├── agent/          # Driver, monitor, sequencer
│   │   ├── counter_driver.sv
│   │   ├── counter_monitor.sv
│   │   └── counter_sequencer.sv
│
│   ├── seq/            # Sequences
│   │   └── counter_seq.sv
│
│   └── test/           # Top-level UVM test classes
│       └── my_test.sv

