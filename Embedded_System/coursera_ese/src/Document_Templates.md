# Document Templates   
- [Header](#Header)   
- [Implementation](#Implementation)   
- [Make File](#Make-File)   
- [Source File](#Source-File)   
- [Register Definition File](#Register-Definition-File)   
# Header
```C
/******************************************************************************
*  Copyright if needed
*
*****************************************************************************/
/**
* @file Simple Statistic Tool
* @brief Statistics tool to print basic information from a data set
*
* Users are able to find a minimum, maximum, mean, and median of a numeric array.
*
* @author Richany Nguon
* @date 05 08 2020
*
*/
#ifndef __STATS_H__
#define __STATS_H__


/**
* @brief Prints a sorted given array from smallest to largest.
*
* Prints a sorted given array from smallest to largest using Binary Insertion Sort.
*
* @param data An unsigned char pointer to an array of unsigned char data types
*
* @return Void, data array values sorted from smallest to largest
*/


void sort_data(unsigned char *data, int size); // this is how you prototype a function with declare parameters

/**
* @brief Prints minimum, maximum, mean and median
*
* A function that prints the statistics of an array including minimum, maximum, mean, and median.
*
* @param data An unsigned char pointer to an array of unsigned char data types
* @param size Int datatype representing the amount of int elements in data array
*
* @return Void value, prints out minimum, maximum, mean, and median. In this case an unsigned float or int.
*/


void print_statistics (unsigned char *data, int size);



#endif /* __STATS_H__ */
```   
# Implementation   
```C
/******************************************************************************
* Copyright (C)
*
*
*****************************************************************************/
/**
* @file Simple Statistic Tool
* @brief Statistics tool to print basic information from a data set
*
* Users are able to find a minimum, maximum, mean, and median of a numeric array.
*
* @author Richany Nguon
* @date 05 08 2020
*
*/

#include <stdio.h>
#include "stats.h"
#define SIZE (40)


int main() {
  unsigned char data[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_statistics(data, SIZE);
  return 0;
};

void print_statistics (unsigned char *data, int size){
    sort_data(data, size);
    unsigned char max = calc_max(data,size);
    unsigned char min = calc_min(data,size);
    double mean = calc_mean(data,size);
    int median = calc_median(data,size);
    printf("%s %d = %c\n %s %d = %c\n %s %f\n %s %d = %c\n", "Max:", max, max, \  // This is how you print stuff
                        "Min:", min, min, "Mean:", mean, "Median:", median, median);
};

void sort_data(unsigned char *data, int size){
    int i;
    unsigned char selected, location; // this how you declare multiple variables of the same time
    signed char end_range;

    signed char *end_range_ptr;
    unsigned char *selected_ptr; // create a pointer
    end_range_ptr = &end_range;
    selected_ptr = &selected; // address pointer to another variables memory
    for(i = 1; i < size; ++i){
        *end_range_ptr= i - 1;
        *selected_ptr = *(data+i); // this is how to access an index of an array through a pointer
        unsigned char start_range = 0;
        location = binary_search(data, selected_ptr, end_range_ptr, start_range);
        
        while(*end_range_ptr >= location){
            *(data+*end_range_ptr+1) = *(data+*end_range_ptr);
            (*end_range_ptr)--;
        }
        *(data+*end_range_ptr+1) = *selected_ptr;
    }
};
```
# Make File  
```
#------------------------------------------------------------------------------
# Generate Map and Executable with Make
#
# Use: make [TARGET] PLATFORM=[PLATFORM-OVERRIDES]
#
# Build Targets:
#      stats.c - Statistics tool to print basic information from a data set
#
# Platform Overrides:
#		DEFAULT - DHOST Current platform
#		MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# Name of output executable
TARGET=statsmachine
LINKER_FILE=msp432p401r.lds

# Initial Creations of Linker Flags and Compiler Flags
LDFLAGS=-Wl,-Map=$(TARGET).map
CFLAGS= -Wall -Werror -g -O0 -std=c99 $(INCLUDES)

# Platform Override
# ifeq = if equipped
ifeq ($(PLATFORM), MSP432)

# Platform Override Specs
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Platform Override Specific Specs Flags
LDFLAGS += -T $(LINKER_FILE)
CPP = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m  -DMSP432 -mfloat-abi=hard -mfpu=fpv4-sp-d16

# Platform Override Compiler and Linker
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld

else
# Default Compiler
CC = gcc
# Default Specs Flag
CPP = -DHOST

endif

ifeq ($(DEBUG), TRUE)
CFLAGS+=-DVERBOSE
endif

# Depending on conditional equipment will add on appropriate flags

CFLAGS+=$(CPP) $(SOURCES)

# Generates list of object variables based of .c files
OBJS:=$(SRC:.c=.o)



# .PHONY explicitly tell Make they're not associated with files but
# would like to execute this specific command
.PHONY: build
build: $(TARGET).out
 
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map

# % Pattern Matcher >> ThisFile.o: ThisFile.c
# C to ASM Files
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@ 

# ASM to executable also generating a map
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS)  -o $(TARGET).out $(OBJS)
```
# Source File  
```C
SOURCES=	\
	src/course1.c \
	src/main.c	\
	src/memory.c \
	src/stats.c	\
	src/data.c \
	src/interrupts_msp432p401r_gcc.c \
	src/startup_msp432p401r_gcc.c \
	src/system_msp432p401r.c 

INCLUDES=	\
	-Iinclude/common	\
	-Iinclude/msp432	\
	-Iinclude/CMSIS	
``` 
# Register Definition File   
