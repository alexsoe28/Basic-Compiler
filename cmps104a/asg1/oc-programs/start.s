# $Id: start.s,v 1.2 2018-03-30 10:56:27-07 - - $

.text
.global _start
_start:
        pop     %rbp        # C compiler will push %rbp
        pop     %rdi        # argc
        mov     %rsp, %rsi  # argv
        andq    $-16, %rsp  # align to 16-byte boundary
        call    main
        movq    %rax, %rdi  # exit
        movq    $0, %rax    # syscall exit code
        syscall
