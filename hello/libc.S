#    SPDX-FileCopyrightText: 2025 João Pedro Gomes <joaop.gomes@usp.br>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  João Pedro Gomes <joaop.gomes@usp.br>

	/* Suppose we receive the argument in %cx. */

	.code16gcc
	.global printf

	.section .text
	
printf:	

	mov   %cx, %bx
	
        mov   $0x0e,%ah               
        mov   $0x0, %si               
loop:                                 
        mov   (%bx, %si), %al           
        cmp   $0x0, %al               
        je    end                    
        int   $0x10                   
        add   $0x1, %si               
        jmp   loop                    
end:
        mov %si, %ax
        ret

	.global rtc_read

rtc_read:
        push   %bx
        push   %cx
    
        mov    $0x02, %ah        # Read RTC function
        int    $0x1A             # BIOS RTC service

        mov    %dh, %al          # Seconds in BCD -> lower byte of EAX
        shl    $16, %eax         # Shift seconds to upper half of 

        mov    %ch, %al          # Hours in BCD -> AL
        mov    %cl, %ah          # Minutes in BCD -> AH

        ; mov    %bx, %dx          # Move to DX for return
    
        pop    %cx
        pop    %bx
        ret # Return to caller

	.global __stack_chk_fail
__stack_chk_fail:
        cli                     # Disable interrupts
1:      hlt                    # Halt the CPU
        jmp     1b             # Jump back to halt if NMI occurs




