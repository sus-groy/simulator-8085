#include <string.h>
#include <stdbool.h>
#include "bus.h"

void bus_reset(Bus *bus) {
    memset(bus, 0x00, sizeof(*bus)); // default to zero
    // the high ones in ctrl pins
    bus->ctrl.rd_n = true;
    bus->ctrl.wr_n = true;
    bus->ctrl.s0 = true;
    bus->ctrl.s1 = true;
}

uint16_t bus_get_addr(const Bus *bus) {
    return ((uint16_t) bus->chan.a_hi << 8) | bus->latch_a_lo;
}

void bus_latch_addr(Bus *bus) {
    if (bus->ctrl.ale)
        bus->latch_a_lo = bus->chan.ad_lo;
}

BusStatus bus_get_status(const Bus *bus) {
    // packed as IO/!M | S1 | S0
    uint8_t status = ((uint8_t) bus->ctrl.io_m  << 2) |
                     ((uint8_t) bus->ctrl.s1    << 1) |
                     ((uint8_t) bus->ctrl.s0    << 0);

    switch (status) {
        case 3: return BUS_OPCODE_FETCH;
        case 2: return BUS_MEM_READ;
        case 1: return BUS_MEM_WRITE;
        case 6: return BUS_IO_READ;
        case 5: return BUS_IO_WRITE;
        case 7: return BUS_INTR_ACK;

        // We don't care about IO/!M when both S0 and S1 are zero
        case 0:
        case 4:
            return BUS_HALT;

        // and ofc we don't know whatever this was
        // this should never hit though
        default:
            return BUS_UNKNOWN;
    }
}
