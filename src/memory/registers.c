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
