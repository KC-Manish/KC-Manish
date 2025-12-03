#include "Vfifo.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdio>
#include <cstdint>

static vluint64_t main_time = 0; // simulation time

double sc_time_stamp() { return main_time; } // required by Verilator

// 1 cycle = toggle 0->1 with dumps
void tick(Vfifo* top, VerilatedVcdC* tfp) {
    top->clk = 0; top->eval(); tfp->dump(main_time++);
    top->clk = 1; top->eval(); tfp->dump(main_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // DUT
    auto* top = new Vfifo;

    // VCD
    Verilated::traceEverOn(true);
    auto* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sim.vcd");

    // reset
    top->rst = 1;
    top->write_en = 0;
    top->read_en = 0;
    top->data_in = 0;
    for (int i = 0; i < 2; ++i) tick(top, tfp);
    top->rst = 0;

    // -------------------------
    // Phase 1: write 0..7 (DEPTH=8), check full goes high at the end
    // -------------------------
    printf("[WRITE] Pushing 8 values\n");
    for (int i = 0; i < 8; ++i) {
        top->write_en = 1;
        top->read_en  = 0;
        top->data_in  = i;
        tick(top, tfp);
        printf("  wrote %d  full=%d empty=%d\n", i, (int)top->full, (int)top->empty);
    }

    // One extra write attempt (should be ignored because full)
    top->write_en = 1;
    top->data_in  = 99;
    tick(top, tfp);
    printf("  attempted extra write (ignored) full=%d empty=%d\n", (int)top->full, (int)top->empty);

    // -------------------------
    // Phase 2: read back all 8 values
    // -------------------------
    printf("[READ] Popping 8 values\n");
    for (int i = 0; i < 8; ++i) {
        top->write_en = 0;
        top->read_en  = 1;
        tick(top, tfp);
        printf("  read %3d  full=%d empty=%d\n", (int)top->data_out, (int)top->full, (int)top->empty);
    }

    // One extra read attempt (should be ignored because empty)
    top->read_en = 1;
    tick(top, tfp);
    printf("  attempted extra read (ignored) full=%d empty=%d\n", (int)top->full, (int)top->empty);

    // Finish
    top->final();
    tfp->close();
    delete tfp;
    delete top;
    return 0;
}

