set(sources
    instruction_decoder.c
    registers.c
)

set(headers
    instruction_decoder.h
    registers.h
)

add_library(lr35902_emulator STATIC ${sources} ${headers})