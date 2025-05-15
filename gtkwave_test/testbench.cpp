#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vcounter *dut = new Vcounter;

    VerilatedVcdC *vcd = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    dut->trace(vcd, 99);
    vcd->open("wave.vcd");

    dut->rst = 1;
    dut->clk = 0;

    for (int i = 0; i < 20; i++) {
        dut->clk = !dut->clk;
        if (i == 2) dut->rst = 0;  // deassert reset
        dut->eval();
        vcd->dump(i * 10);
    }

    vcd->close();
    delete dut;
    return 0;
}
