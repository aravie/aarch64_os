.global delay
.global out_word
.global in_word

delay:
    subs x0, x0, #1
    bne delay
    ret

// store 32 bit register to memory location addressed by x0
out_word:
    str w1, [x0]
    ret

// load 32 bit register to w0 from memory location addressed by x0
in_word:
    ldr w0, [x0]
    ret
