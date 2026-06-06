#include "../include/memory/registers.h"

#define HELPERS(type_t, suffix) \
typedef struct Reg##suffix { \
    type_t data; \
} Reg##suffix; \
\
type_t get_data_##suffix(Reg##suffix *reg) { \
    return reg->data; \
} \
\
void set_data_##suffix(Reg##suffix *reg, type_t new_data) { \
    reg->data = new_data; \
}

HELPERS(int8_t, 8)
HELPERS(int16_t, 16)

#undef HELPERS

Reg8 reg_A;  
Reg8 reg_F;  
Reg8 reg_B;
Reg8 reg_C;
Reg8 reg_D;
Reg8 reg_E;
Reg8 reg_H;
Reg8 reg_L;

Reg16 reg_SP;    
Reg16 reg_PC;
