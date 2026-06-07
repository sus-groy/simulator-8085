#include <stdlib.h>
#include <string.h>
#include "vm.h"
#include "bus.h"
#include "cpu/cpu.h"

void vm_reset(VM *vm) {
    // zero out the CPU state
    // the timing being zero too means its at M1 T1, ready
    memset(&vm->cpu, 0x00, sizeof(vm->cpu));
    bus_reset(&vm->bus); // idle state the BUS
}

void vm_clear(VM *vm) {
    vm_reset(vm);
    memset(vm->mem, 0x00, VM_MEM_SIZE); // plus zero out the memory
}

VM *vm_create(void) {
    VM *vm = malloc(sizeof(*vm));
    if (vm != NULL) // got back a real allocation
        vm_clear(vm);
    return vm;
}

void vm_destroy(VM *vm) {
    if (vm != NULL)
        free(vm);
}
