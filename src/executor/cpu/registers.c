#include "cpu/registers.h"

#define GET(h, l) (((uint16_t) (h) << 8) | (l) )
#define SET(h, l, v)                    \
    do {                                \
        (h) = ((v) >> 8) & 0xFF;        \
        (l) = (v) & 0xFF;               \
    } while (0)

uint16_t get_bc(const Registers *st) {
    return GET(st->b, st->c);
}

uint16_t get_de(const Registers *st) {
    return GET(st->d, st->e);
}

uint16_t get_hl(const Registers *st) {
    return GET(st->h, st->l);
}

void set_bc(Registers *st, uint16_t val) {
    SET(st->b, st->c, val);
}

void set_de(Registers *st, uint16_t val) {
    SET(st->d, st->e, val);
}

void set_hl(Registers *st, uint16_t val) {
    SET(st->h, st->l, val);
}

uint16_t get_psw(const Registers *st) {
    return GET(st->a, st->flags);
}

void set_psw(Registers *st, uint16_t val) {
    SET(st->a, st->flags, val);
}

#undef GET
#undef SET
