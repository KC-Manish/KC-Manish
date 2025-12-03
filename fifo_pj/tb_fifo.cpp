#include "Vfifo.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vfifo* top = new Vfifo;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("sim.vcd");

    int time = 0;
    auto tick = [&]() {
        top->clk = 0; top->eval(); tfp->dump(time++);
        top->clk = 1; top->eval(); tfp->dump(time++);
    };

    top->rst = 1; tick();
    top->rst = 0; tick();

    // Write some data
    for (int i = 0; i < 5; i++) {
        top->write_en = 1;
        top->data_in = i;
        top->read_en = 0;
        tick();
    }

    // Read data
    for (int i = 0; i < 5; i++) {
        top->write_en = 0;
        top->read_en = 1;
        tick();
    }

    top->final();
    tfp->close();
    delete top;
    return 0;
}

