CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T prime_ls.ld -Wl,-Map=final.map
LDFLAGS_SH = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T prime_ls.ld -Wl,-Map=final.map

.PHONY: all main.o prime.o stm_startup.o syscalls.o final.elf final_sh.elf remove load

all : main.o prime.o stm_startup.o syscalls.o final.elf

remove: 
	rm -rf \*.o \*.elf

main.o : main.c
	$(CC) $(CFLAGS) -o $@ $^

prime.o : prime.c
	$(CC) $(CFLAGS) -o $@ $^

stm_startup.o : stm_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o : syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf : main.o prime.o stm_startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^
	
final_sh.elf : main.o prime.o stm_startup.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

load:
	openocd -f board/stm32f4discovery.cfg 
