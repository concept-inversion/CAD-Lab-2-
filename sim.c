#include <stdio.h>
#include "shell.h"

typedef struct Rtype
{
    uint32_t rs;
    uint32_t rt;
    uint32_t rd;
    uint32_t func;
    uint32_t shamt;
};

typedef struct Itype
{
    
};
typedef struct Jtype
{
    
};

uint32_t fetch()
{
uint32_t Instr= mem_read_32(CURRENT_STATE.PC);
printf("%u\n",Instr);
    return Instr;
}

void decode(uint32_t instr)
{
    printf("Decode here:%x ",instr);
    uint32_t opcode = instr>>26;
    if (opcode==0)   // R type
    {
        struct Rtype R;
        
        R.rs= (instr>>21) & 0x1F;
        R.rt= (instr>>16) & 0x1F;
        R.rd= (instr>>11) & 0x1F;
        R.func= instr & 0x3F;
        R.shamt= (instr>>6) & 0x1F;
        printf("Function: %u \n",R.func);
    }
    else if (opcode==2 || opcode==3)    // J type
    {
        uint32_t address= instr & 0x1FFFFFF;
    }
    else    // I type
    {
        uint32_t rt = (instr>>21) & 0x1F;
        uint32_t rs = (instr>>16) & 0x1F;
        uint32_t immediate = instr & 0xFFFF;
    }
}

void execute()
{
    // read the opcode
    // switch case for each instr
    // get a way to read registers as address
}
void process_instruction()
{
    /* execute one instruction here. You should use CURRENT_STATE and modify
     * values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     * access memory. */
    uint32_t instr = fetch();
    decode(instr);
    execute();
   
    
}
