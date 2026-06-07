#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t a_hi; // Address high high
    // The union exists purely for expressing intent
    union {
        uint8_t ad_lo; // Address low bits
        uint8_t data; // Treating these bits as data
    };
} AddrDataBus;

typedef struct {
    bool ale;
    bool rd_n; // !RD
    bool wr_n; // !WR
    bool io_m; // IO/!M
    bool s0;
    bool s1;
} ControlBus;

typedef struct {
    AddrDataBus chan;
    ControlBus ctrl;

    // The 74LS373 latch for storing the `chan.ad_lo` on `ctrl.ale = true`
    uint8_t latch_a_lo;
} Bus;

typedef enum {
    BUS_OPCODE_FETCH,
    BUS_MEM_READ,
    BUS_MEM_WRITE,
    BUS_IO_READ,
    BUS_IO_WRITE,
    BUS_INTR_ACK,
    BUS_HALT,
    BUS_UNKNOWN
} BusStatus;

// helper APIs

void bus_reset(Bus *);
uint16_t bus_get_addr(const Bus *);
void bus_latch_addr(Bus *);
BusStatus bus_get_status(const Bus *);
