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

#ADDING SOURCE FILES

ifeq ($(PLATFORM),MSP432)
	SOURCES =          main.c \
			   memory.c \
			   interrupts_msp432p401r_gcc.c \
			   startup_msp432p401r_gcc.c \
			   system_msp432p401r.c \
			   data.c \
			   stats.c \
			   course1.c
else
	SOURCES = main.c \
		  memory.c \
		  data.c \
		  stats.c \
		  course1.c

endif

#ADDING INCLUDE PATHS

ifeq ($(PLATFORM),MSP432)
  INCLUDEHEADER= 	   -I../include/CMSIS \
			   -I../include/common \
			   -I../include/msp432 \
			   -I../ 
else
    INCLUDEHEADER=         -I../include/common\
		           -I../	   
    INCLUDESRC= 	   -I../src
endif

