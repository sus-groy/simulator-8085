#include "../include/memory/registers.h"


typedef struct{
    int8_t data;
}Register_8b;

int get_data_8b(Register_8b *reg){
    // get 8-bit data
    return reg->data;                   
}

void set_data_8b(Register_8b *reg, int8_t new_data_8b){
    // set new 8-bit data in reg
    reg->data = new_data_8b;                                                                        
}


typedef struct{
    int16_t data;
}Register_16b;

int get_data_16b(Register_16b *reg){
    // get 8-bit data
    return reg->data;                   
}

void set_data_16b(Register_16b *reg, int16_t new_data_16b){
    // set new 8-bit data in reg
    reg->data = new_data_16b;                                                                        
}
