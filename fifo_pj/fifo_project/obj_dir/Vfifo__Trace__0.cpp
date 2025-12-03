// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfifo__Syms.h"


void Vfifo___024root__trace_chg_0_sub_0(Vfifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo___024root__trace_chg_0\n"); );
    // Init
    Vfifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfifo___024root*>(voidSelf);
    Vfifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfifo___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vfifo___024root__trace_chg_0_sub_0(Vfifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->fifo__DOT__mem[0]),8);
        bufp->chgCData(oldp+1,(vlSelf->fifo__DOT__mem[1]),8);
        bufp->chgCData(oldp+2,(vlSelf->fifo__DOT__mem[2]),8);
        bufp->chgCData(oldp+3,(vlSelf->fifo__DOT__mem[3]),8);
        bufp->chgCData(oldp+4,(vlSelf->fifo__DOT__mem[4]),8);
        bufp->chgCData(oldp+5,(vlSelf->fifo__DOT__mem[5]),8);
        bufp->chgCData(oldp+6,(vlSelf->fifo__DOT__mem[6]),8);
        bufp->chgCData(oldp+7,(vlSelf->fifo__DOT__mem[7]),8);
        bufp->chgCData(oldp+8,(vlSelf->fifo__DOT__wr_ptr),3);
        bufp->chgCData(oldp+9,(vlSelf->fifo__DOT__rd_ptr),3);
        bufp->chgCData(oldp+10,(vlSelf->fifo__DOT__count),4);
    }
    bufp->chgBit(oldp+11,(vlSelf->clk));
    bufp->chgBit(oldp+12,(vlSelf->rst));
    bufp->chgBit(oldp+13,(vlSelf->write_en));
    bufp->chgBit(oldp+14,(vlSelf->read_en));
    bufp->chgCData(oldp+15,(vlSelf->data_in),8);
    bufp->chgCData(oldp+16,(vlSelf->data_out),8);
    bufp->chgBit(oldp+17,(vlSelf->full));
    bufp->chgBit(oldp+18,(vlSelf->empty));
}

void Vfifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo___024root__trace_cleanup\n"); );
    // Init
    Vfifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfifo___024root*>(voidSelf);
    Vfifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
