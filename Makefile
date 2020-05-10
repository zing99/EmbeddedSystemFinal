#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# A Makefile which supports both Host and ARM systems.
# The Host is Linux & ARM is MSP432P40IR
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	 <FILE>.o - Builds <FILE>.o object file
#	 <FILE>.i - Generate the preprocessed output of the <FILE>.i
#	 <FILE>.asm - Generate assembly output of <FILE>.asm	
#	      
#	 compile-all : Compiles all files without linking
#	 build: Compile all object files and link into a executable
#	 clean: removes all generated files.
#
#------------------------------------------------------------------------------
include sources.mk

#MSP432 SPECIFIC FLAGS
ifeq ($(PLATFORM),MSP432)
		CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		LINKER_FILE = msp432p401r.lds
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

		CPU = cortex-m4
		ARCH = thumb
		SPECS = nosys.specs
		FPU = fpv4-sp-d16
		ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU)		
		OBJDUMP = arm-none-eabi-objdump
		SIZE = arm-none-eabi-size 

#HOST SPECIFIC FLAGS
else
		CC = gcc
		LD = ld
		SIZE = size
		LDFLAGS = -Wl,-Map=$(TARGET).map
		OBJDUMP = objdump
endif


VPATH = ./src
 
ifeq ($(VERBOSE),VERBOSE)
		V = -g
endif


 
#COMMON FLAGS
TARGET = c1

CFLAGS = -Wall -Werror $(V) -O0 -std=c99 $(INCLUDEHEADER) $(INCLUDESCR) -D$(PLATFORM) $(ARMFLAGS) $(VERBOSE) $(COURSE1)

CPPFLAGS = -E
MAIN = main

OBJS = $(SOURCES:.c=.o)

PRE = $(SOURCES:.c=.i)

ASM = $(SOURCES:.c=.asm)

DEPS = $(SOURCES:.c=.d)

FILES = *.asm *.i *.o *.d

#GENERATE OBJECT FILES WITHOUT LINKING	
%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o



.PHONY: build
build: $(TARGET).out  #$(TARGET).asm


$(TARGET).out: $(OBJS) #$(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)

.PHONY: clean
clean:
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PRE) $(ASM) $(DEPS) $(OBJS)
