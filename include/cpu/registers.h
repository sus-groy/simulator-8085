#pragma once
#include <stdint.h>

// RegisterType Opcodes
typedef enum {
    REG_B = 0,
    REG_C,
    REG_D,
    REG_E,
    REG_H,
    REG_L,
    REG_M,
    REG_A,
    NUM_REGS
} RegisterType;

// The 8085 state
typedef struct {
    // The grouped register array (uint8_t), in order as specified by the RegisterType enum
    // B C D E H L M(unused) A
    // The struct exists for easier access internally
    union {
        uint8_t slots[NUM_REGS];
        struct {
            uint8_t b, c, d, e, h, l, unused_m, a;
        };
    };

    // Flags
    uint8_t flags;

    // SP and PC registers
    uint16_t sp;
    uint16_t pc;
} Registers;

// The 8085 flag masks
// Anonymous enum cuz we don't need the type, just compile time constants
enum {
    FLAG_CY = 1 << 0, // carry
    FLAG_P = 1 << 2, // parity
    FLAG_AC = 1 << 4, // aux carry
    FLAG_Z = 1 << 6, // zero
    FLAG_S = 1 << 7 // sign
};

// For the register pairs, we need a different set of getter setters

uint16_t get_bc(const Registers *);
uint16_t get_de(const Registers *);
uint16_t get_hl(const Registers *);

void set_bc(Registers *, uint16_t);
void set_de(Registers *, uint16_t);
void set_hl(Registers *, uint16_t);

// There's also the PSW, combining A and F

uint16_t get_psw(const Registers *);
void set_psw(Registers *, uint16_t); 
