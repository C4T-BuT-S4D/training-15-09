#ifndef VM_H
#define VM_H


#define EXEC_SUCCESS                 0
#define EXEC_INTERRUPTED             1

#define EXEC_ERR_PROGRAM_TOO_LONG   -1
#define EXEC_ERR_EXCEEDED_LIMIT     -2
#define EXEC_ERR_INVALID_OP         -3
#define EXEC_ERR_INVALID_ARG        -4
#define EXEC_ERR_SYS_INVALID_OP     -5
#define EXEC_ERR_SYS_INVALID_ARG    -6
#define EXEC_ERR_STACK_OVERFLOW     -7
#define EXEC_ERR_UNKNOWN            -8

#define PROGRAM_SIZE    1024
#define DATA_SIZE       1024
#define STACK_SIZE      1024


typedef struct vm_reg_t {
    unsigned int IP;
    unsigned int SP;
    unsigned int BP;
    unsigned char FLAGS;
    int AX;
    int BX;
    int CX;
    int DX;
} vm_reg_t;

typedef struct vm_mem_t {
    int program[PROGRAM_SIZE];
    int data[DATA_SIZE];
    int stack[STACK_SIZE];
} vm_mem_t;

typedef struct vm_state_t {
    vm_reg_t vm_reg;
    vm_mem_t vm_mem;
} vm_state_t;


int run_program(int* program, unsigned int length, unsigned int limit);


#endif
