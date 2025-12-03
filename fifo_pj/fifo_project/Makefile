# Verilator + GTKWave FIFO project

TOP     = fifo
RTL     = $(TOP).sv
TB      = tb_$(TOP).cpp
OBJDIR  = obj_dir
EXEC    = $(OBJDIR)/V$(TOP)
VCD     = sim.vcd

VFLAGS  = -Wall --trace -cc --timing
CFLAGS  =

.PHONY: all sim run wave clean

all: run

sim: $(RTL) $(TB)
	verilator $(VFLAGS) $(RTL) --exe $(TB)
	$(MAKE) -C $(OBJDIR) -f V$(TOP).mk V$(TOP)

run: sim
	./$(EXEC)

wave: run
	gtkwave $(VCD)

clean:
	rm -rf $(OBJDIR) $(VCD)

