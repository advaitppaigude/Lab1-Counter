#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    // initialise top verilog instance
    Vcounter* top = new Vcounter;

    // initialise trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    // initialise simulation inputs
    top->clk = 1;
    top->reset = 1;
    top->enable = 0;

    for (i = 0; i < 300; i++) {

        // dump variables into VCD file and toggle clk
        for (clk = 0; clk < 2; clk++) {
            tfp->dump(2*i + clk); // i is half a cycle. unit is ps
            top->clk = !top->clk; // high+low in 1 period
            top->eval();
        }

        // setting input signals to see how output changes
        top->reset = (i < 2) || (i == 15);
        top->enable = (i > 4);

        if (Verilated::gotFinish()) exit(0);
    }
    tfp->close();
    exit(0);
}