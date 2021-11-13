#include <avr/io.h>

.global asm_setup
.global deactivate_siren
.global activate_siren

asm_setup:
    ldi   r18, 0x80
	  out   (DDRD-0x20), r18
    ldi   r18, 0x10
    out   (PORTD-0x20), r18
    sbi   (PORTD-0X20), 7
	  ret

deactivate_siren:
    sbi   (PORTD-0x20), 7
    ret

activate_siren:
    cbi (PORTD-0x20), 7
    ret
