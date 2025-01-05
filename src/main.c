#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

#define LINE_NUM 123

int main(int argc, const char* argv[]) {
    (void)argc;
    (void)argv;

    initVM();

    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, LINE_NUM);
    writeChunk(&chunk, constant, LINE_NUM);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, LINE_NUM);
    writeChunk(&chunk, constant, LINE_NUM);

    writeChunk(&chunk, OP_ADD, LINE_NUM);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, LINE_NUM);
    writeChunk(&chunk, constant, LINE_NUM);

    writeChunk(&chunk, OP_DIVIDE, LINE_NUM);
    writeChunk(&chunk, OP_NEGATE, LINE_NUM);
    writeChunk(&chunk, OP_RETURN, LINE_NUM);
    printf("disassembly:\n");
    disassembleChunk(&chunk, "test chunk");

    printf("running...\n");
    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);

    return 0;
}
