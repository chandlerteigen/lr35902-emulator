set(sources
    instruction_decoder.c
    registers.c
    alu.c
)

set(headers
    instruction_decoder.h
    registers.h
    alu.h
)

add_library(lr35902_emulator STATIC ${sources} ${headers})