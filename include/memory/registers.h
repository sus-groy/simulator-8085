#pragma once
#include <stdint.h>

typedef struct Reg8 Reg8; // stores 8 bit data word
// only forward declaration so that outside files can't access internal data 

int8_t get_data_8(Reg8 *reg);  // get 8-bit data
void set_data_8(Reg8 *reg, int8_t new_data_8b);  // set new 8-bit data

// start of 8-bit registers file:
Reg8 reg_A;  // accumulator
Reg8 reg_F;  // flags register

Reg8 reg_B;
Reg8 reg_C;

Reg8 reg_D;
Reg8 reg_E;

Reg8 reg_H;
Reg8 reg_L;
// ^ end of 8-bit registers file

typedef struct Reg16 Reg16;  // register that can contain 16-bit data word
// only forward declaration so that outside files can't access internal data 

int16_t get_data_16(Reg16 *reg);
void set_data_16(Reg16 * reg, int16_t new_data_16b);

Reg16 reg_SP;    // stack pointer
Reg16 reg_PC;    // programme counter
// only two 16-bit registers in system
