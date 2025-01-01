#include "common.h"
#include "chunk.h"

int main(int argc, const char* argv[]) {
    (void)argc;
    (void)argv;
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    freeChunk(&chunk);
    return 0;
}
