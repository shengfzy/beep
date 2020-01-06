CROSS_COMPILE   ?= arm-linux-gnueabihf-
TARGET			?= beep

CC         		:= $(CROSS_COMPILE)gcc
LD 				:= $(CROSS_COMPILE)ld
OBJCOPY			:= $(CROSS_COMPILE)objcopy 
OBJDUMP 		:= $(CROSS_COMPILE)objdump 

INCDIRS			:= imx6ull \
				   bsp/clk \
				   bsp/delay \
				   bsp/led \
				   bsp/beep

SRCDIRS         := project \
                   bsp/clk \
				   bsp/delay \
				   bsp/led \
				   bsp/beep


INCLUDE         := $(patsubst %, -I %, $(INCDIRS))

SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.s))
CFILES          := $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENDIR       := $(notdir $(SFILES))
CFILENDIR       := $(notdir $(CFILES))

SOBJS           := $(patsubst %, obj/%, $(SFILENDIR:.s=.o))
COBJS           := $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS            := $(SOBJS) $(COBJS)

#指定编译源文件的搜索目录
VPATH           := $(SRCDIRS)

$(TARGET).bin : $(OBJS)
	$(LD) -Timx6ull.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S -g $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.s
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

.PHONY: clean
clean:
	rm -rf $(TARGET).elf $(TARGET).dis $(TARGET).bin $(OBJS) $(SOBJS)
