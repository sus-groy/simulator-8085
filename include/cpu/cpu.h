#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "cpu/registers.h"

// The 8085 machine cycles
typedef enum {
    MC_OPCODE_FETCH,
    MC_MEM_READ,
    MC_MEM_WRITE,
    MC_IO_READ,
    MC_IO_WRITE,
    MC_INTERRUPT_ACK
} MachineCycle;

// The 8085 T states
typedef enum { T1, T2, T3, T4, T5, T6 } TState;

typedef struct {
    uint8_t m_index; // which phase of machine cycle we are in (impt!)
    MachineCycle cycle;
    TState t_state;
} CPUTiming;

typedef struct {
    uint8_t ir;
    uint8_t temp, act; // temp storage and accumulator
    uint8_t w, z; // often used as WZ pair
} CPUInternal;

typedef struct {
    Registers regs;
    CPUInternal internal;
    CPUTiming timing;

    bool is_halted; // HLT affects this
    bool interrupts_enabled; // DI can toggle this
} CPU;
