#pragma once
#include <stdint.h>
#include "cpu/cpu.h"
#include "bus.h"

#define VM_MEM_SIZE 65535

// Ideally, one must not allocate this on the stack
// Use the helpers from this API to heap allocate it and default the states
typedef struct {
    CPU cpu;
    Bus bus;

    uint8_t mem[VM_MEM_SIZE];
} VM;

// reset the VM to its starting state, while keeping the memory
void vm_reset(VM *);
// same as reset the VM, but clears the memory
void vm_clear(VM *);
// returns back a new virtual machine, with all the states set to idle
VM *vm_create(void); 
// destroys the previously allocated VM
void vm_destroy(VM *);
