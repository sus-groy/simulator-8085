#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdint.h>

typedef struct Register_8b; // stores 8 bit data word
// 1 byte = 8 bits

int get_data_8b(Register_8b *reg);  // get 8-bit data
void set_data_8b(Register_8b *reg, int8_t new_data_8b);  // set new 8-bit data

// start of 8-bit registers file:
Register_8b reg_A;  // accumulator
Register_8b reg_F;  // flags register

Register_8b reg_B;
Register_8b reg_C;

Register_8b reg_D;
Register_8b reg_E;

Register_8b reg_H;
Register_8b reg_L;
// ^ end of 8-bit registers file

typedef struct Register_16b;  // register that can contain 16-bit data word

int get_data_16b(Register_16b *reg);
void set_data_16b(Register_16b * reg, int16_t new_data_16b);

Register_16b reg_SP;    // stack pointer
Register_16b reg_PC;    // programme counter
// only two 16-bit registers in system

#endif