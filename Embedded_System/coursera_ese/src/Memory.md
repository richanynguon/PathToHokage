# Memory   
- [Characteristics](#Characteristics)   
    - [Capacity](#Capacity)   
    - [Volatility](#Volatility)   
    - [Access](#Access)   
    - [Power Consumption](#Power-Consumption)   
    - [Latency](#Latency)   
    - [Durability](#Durability)   
    - [Transaction Size](#Transaction-Size)   
- [Hierarchy Descending Latency](#Hierarchy-Descending-Latency)   
    - [Registers](#Registers)   
    - [Cache L1, L2, L3](#Cache-L1,-L2,-L3)   
    - [RAM SRAM DRAM](#RAM-SRAM-DRAM)   
    - [Flash EEPROM](#Flash-EEPROM)   
- [Memory Segements](#Memory-Segements)   
    - [Code Memory](#Code-Memory)   
        - [Intvecs](#Intvecs)   
            - [Vector Tables](#Vector-Tables)   
        - [Text](#Text)   
        - [Const](#Const)   
        - [Initialized segments](#Initialized-segments)   
        - [Dependent bootloader](#Dependent-bootloader)   
    - [Data Memory](#Data-Memory)   
    - [Runtime State of Program](#Runtime-State-of-Program)   
- [Data Segments](#Data-Segments)   
    - [Stack](#Stack)   
        - [Stores](#Stores)   
        - [Frame Size](#Frame-Size)   
        - [Stack Registers](#Stack-Registers)   
        - [Specialized Operations](#Specialized-Operations)   
            - [Push](#Push)   
            - [Pop](#Pop)   
        - [Stack overflow](#Stack-overflow)   
    - [Heap](#Heap)   
        - [Heap Functions](#Heap-Functions)   
        - [Malloc](#Malloc)   
        - [Calloc](#Calloc)   
        - [Realloc](#Realloc)   
        - [Free](#Free)   
        - [Issues](#Issues)   
    - [Data](#Data)   
    - [BSS](#BSS)   
- [Data Allocation](#Data-Allocation)   
    - [Static](#Static)   
    - [Dynamic](#Dynamic)   
- [Busses](#Busses)   
- [Memory Alignment](#Memory-Alignment)   
    - [Packed](#Packed)   
    - [Aligned](#Aligned)
    - [Data Order](#Data-Order)   
    - [Endianness](#Endianness)   
        - [Little Endian](#Little-Endian)   
        - [Big Endian](#Big-Endian)   
- [Registers Details](#Registers-Details)   
    - [Internal Core CPU](#Internal-Core-CPU)   
    - [General Purpose Registers](#General-Purpose-Registers)   
    - [Special Registers](#Special-Registers)   
    - [Program Status Registers](#Program-Status-Registers)   
        - [APSR](#APSR)   
        - [IPSR](#IPSR)   
        - [EPSR](#EPSR)   
    - [Exception Mask Registers](#Exception-Mask-Registers)   
        - [PRIMASK](#PRIMASK)   
        - [FAULTMASK](#FAULTMASK)   
        - [BASEPRI](#BASEPRI)   
    - [Control Registers](#Control-Registers)   
        - [FPCA](#FPCA)   
        - [SPSEL](#SPSEL)   
        - [NPRIV](#NPRIV)   
    - [Private Peripherals](#Private-Peripherals)    
    - [Peripherals](#Peripherals)     
    - [SRAM](#SRAM)   
        - [SRAM Bit Band Alias](#SRAM-Bit-Band-Alias)   
    - [Code](#Code)   
    - [General Peripheral Memory](#General-Peripheral-Memory)   
- [Interacting With Memory](#Interacting-With-Memory)
# Characteristics   
You want to limit the size, power, and cost of systems.
## Capacity  
---   
   
The amount of storage a memory can hold, embedded systems do not need a lot of memory to be optimized for performance. Increasing the capacity increases the complexity of the design and size as well as the connection circuitry.


## Volatility  
---   
The ability to hold data without power  
Volatile memory loses data when power is removed
- SRAM
- DRAM
- SDRAM
- Registers

Non-volatile retains data when power is removed, but has issues with endurance. Non volatile semiconductor memories have limited number of write-erase cycles before failure. 
- ROM/PROM/EPROM/EEPROM
- Flash - Endurance lasting to 10k - 100k write erase cycles
   
## Access  
---   
The type of access that is available for example, random access or security accesss

- Random Access: Allows for access to any part of memory given the address of that location
- Access Security: Require credentials to Read/Write parts of memory
	- Read-only memory - no ability to write extra permissions of process



## Power Consumption  
--- 
The amount of power it is required to make the memory functional.  
   
## Latency  
---   
The time it takes for the memory to respond to a read and write.
Code and data need to be read/written to memory
- Assembly instructions are read
- Instructions operands need to be read
- Instruction results need to written


Any data read/written interacts with CPU, Bus Controller, Bus, memory controller and memory
To improve latency concepts like pipe lining in caches have be introduced.
## Durability  
---   
The endurance of the memory structrure
## Transaction Size  
---   
   
# Hierarchy Descending Latency Memory Types   
## Registers  
---   
Registers are quickly accessed memory that help hardware perform operations.
   
## Cache L1, L2, L3  
---   
Cache is quickly accessed memory during run time. 
## RAM SRAM DRAM  
---   
Randomly Accessed Memory - Static and Dynamic.  
An SRAM usually holds a data segment.
## Flash EEPROM  
---   
Flash ususally hold code segment.

EEPROM are not usually used with embedded systems but can be connect with SPI and controlled by GPIO.
# Memory Segments  
The types of memory of embedded systems are
- Code Memory stored in Flash
- Data Memory stored in SRAM
- Register Memory stored internally in a chip
- External Memory if applicable so maybe an EEPROM
Depending on the type of platform the way memory is mapped out is differnt. 
## Code Memory  
---   
Code memory is read-only data
#### Intvecs  
---  
   
###### Vector Tables  
---   
-  Interrupt: Asynchronous events with an associated software routine
-  Vector Tables contains a platform defined list of function address, used to jump into a routine
-  Typically first part of code memory (address zero)

Interrupt Vector Table
- Interrupts are special events that request the CPU to perfrom a  specific operation
- Interrupt service routine (ISR): function to be called in response to an interrupt request
- placed at address 0x0 in code memory

Vector Table
- Definition requires both linker mapping and C/assembly code
- Vector table is an array of function addresses
	- used to jump into a routine when interrupt occurs


   
#### Text  
---   
-  Text Section
	-  contains all written software
	-  main
	-  user defined functions
	-  interrupt routines
	-  standard code library
	-  usually the largest segment in code
		-  size depends on software implementation


#### Const  
---   
-  Read-Only or const contains constant variable defined data
	-  Very hard to overwrite at runtime
	-  Size depends on software implementations


#### Initialized segments  
---   

-  code used to initialize software or data
	-  either start up or object instantiation
-  Initial values are stored in code memory
	-  Non-zero initialized global and static data .data and variable initial values
-  Routines to set these initial values
	-  .data -initialized at start up from code memory
	-  .bss - initialized to zero at start up
-  Names depend on compiler, architecture, or c-standard:
	-  .cinit
	-  .pinit
	-  .init/.fini
	-  .init_array
	-  .ctors/.dtors
- (unused) or .bootloader
#### Dependent bootloader  
---   
- Small block of code that is installed in code memory that is run at startup
- Allows you to check for a new install or run existing build
- Helps with reducing hardware costs
- On-chip software to install build using platform interfaces
	- Put in a safe/protected space so you do not overwrite it
- Create a linker script section for the bootloader code
- Exclude writing boot section for every install


## Runtime State of Program  
---   

## Data Memory  
---   
Data memory stores program operands so code program memory is stored there too, data gets loaded into registers, and stored back into memory. Data memory can be allocated at compile time or run time.

Data memory can exist for different length of time
- Lifetime of a function or block
- Lifetime of program
- Longer than a function, but less than a program

Since data memory is volatile extra non-volatile memory maybe be included in your system. Most common exampled of data memory is RAM.
# Data Segments  
A container for the various types of allocated data that get mapped into physical memory. There are four main sub segments:  
- Stack
- Heap
- Data
- BSS

You can corrupt your data by misaddressing  a variable or writing outside bounds of the segment space.  
Data sub-segments are allocated contiguously except for the stack.
## Stack  
---   
A stack store temporary data storage local variables. Stack allocate memory in descending fashion hight to low are called full descending stacks. Stack space is reserved at compile time, data is allocated at run time by precompiled instructions.   
General Stack Characterisitics
- Stack specific instructions and registers
- Ascending or descending growth
- Architecture specific contents
- Content order

- Stack segment is reserved at linking step
    - Compile option / linker file specifies size
- Stack memory is reused throughout program
    - Store temproray data
- Stack call convention, data is passed in and returned from a routine. 
    - Execution flow changes: copy params, save state, jump into sub-routine
    - Remove sub-routine allocations, return data, restore calling function state

  
#### Stores  
---   
- Local Variables  
- Input parameters  
- Return data  
- Copy of used registers  
- Return Address  
- Previous stack pointer  
- Copy of special function registers (interrupts)  

#### Frame Size  
---   
Automatic local variables, input parameters of a function, return values, previous stack pointers are stored in the stack memory generically without compiler optimizing.  

Stack is assigned to be a specific size (Depends of Architecture/Application Binary Interface's calling conventions):  

Frame size is affected by:
- Number of local variables
- Number of input parameters
- Size/Type of Local Variables
- Size/Type of Input Parameters
- Size/Type of Return data
- Number of nested subroutine calls
- Interrupts/nested interrupts


#### Stack Registers  
---   

| Register | Synonym | Special  | Roles in the procedure call standard                                                |
|----------|---------|----------|-------------------------------------------------------------------------------------|
| r15      |         | PC       | The program counter                                                                 |
| r14      |         | LR       | The link register                                                                   |
| r13      |         | SP       | The stack pointer                                                                   |
| r12      |         | IP       | The intra-procedure-call scratch register                                           |
| r11      | v8      |          | Variable Register 8                                                                 |
| r10      | v7      |          | Variable Register 7                                                                 |
| r9       |         | v6 SB TR | Platform register. The meaning of this register is defined by the platform standard |
| r8       | v5      |          | Variable Register 5                                                                 |
| r7       | v4      |          | Variable Register 4                                                                 |
| r6       | v3      |          | Variable Register 3                                                                 |
| r5       | v2      |          | Variable Register 2                                                                 |
| r4       | v1      |          | Variable Register 1                                                                 |
| r3       | a4      |          | Argument / scratch register 4                                                       |
| r2       | a3      |          | Argument / scratch register 3                                                       |
| r1       | a2      |          | Argument / result /scratch register 2                                               |
| r0       | a1      |          | Argument / result /scratch register 1                                               |  

r12-r15 are special purpose registers
- PSR - program status register
- PRIMASK, FAULTMASK, BASEPRI - exception mask registers
- CONTROL - control register


r0 - r11 are general purpose registers
size of registers is architecture dependent (ARM cortex-m - 32 bits)

ARM tries to avoid using the stack by using registers for:
- Function input parameters
- Local variables
- return values


There is a limited number of registers
- Only 12 registers of 32 bits each


Stack Growth
- Stack Pointer: Points to end of used stack
- Frame Pointer: Points to beginning of the stack frame or the previous stack pointer
- Grows upward or downwards of address


   
#### Specialized Operations  
---   
Can more data or multiple data. 
###### Push  
---   
- Copies data from registers to stack
	- {r0, r1, r2,lr}
   
###### Pop  
---   
- remove data from Stack Registers
	- {r4, pc}

 
#### Stack overflow  
---   
Numerous nested routine calls caused the stack to overflow into other reserved regions
## Heap  
---   
A heap is a dynamic storage at run time.

- Reserved at compile time, data is allocated at run time by directly calling memory functions
- Sub-segment of data memory reserved at compile time with a set size
- Data is allocated dynamically at runtime and managed by developer
- Each allocation can (pending space)
	- Vary in size
	- Be resized

Lifetime and Scope
- Heap data can have a lifetime longer than a function but less than the program
- Heap data can have a local scope or a global scope
- Allocation/deallocation adds execution overhead


#### Heap Functions  
---   
Any heap allocation/Reallocation requires raw byte count and returns a pointer the beginning of the piece of memory requested 

Failed Allocation
- When dynamic memory allocation fails, routines return a NULL pointer (Pointer to nothing/address 0x0)
- Cannot assume your allocation will work, need to check it succeeded! Heap might be free or the is not enough contiguous space
- Not enough contiguous space can occur when over allocating and free data frequently and inefficiently .



#### Malloc  
---   
void * malloc(size_t size)

- Allocates "n" contiguous bytes in heap space
- Once you receive pointer from this function not to change address to free the address later
- returns a pointer


#### Calloc  
---  
void * calloc(size_t nitems, size_t) 
Same as malloc but also initialize spaces with 0s
   
#### Realloc  
---   
void * realloc(void * ptr, size_t size)

- params: heap pointer
- Reallocates region to new size, and frees old space
- returns a new pointer


#### Free  
---   
void free (void * ptr) 

- Deallocates data back to heap free space
- Must free allocated data or heap will run out space


#### Issues  
---   
Heap Issues
- Direct Software Management
- Potential Memory Leaks
	- Loss of heap tracking pointer
	- Memory Framentation
	- Performance hit (extra CPU overhead)
		- Runtime allocated
		- Calling heap functions to allocate memory

 
## Data  
---   
Non-zero initialized global and static data
   
## BSS  
---   
Block started by symbol is a zero initialized and unitialized global and static data.
# Data Allocation      
Data represents more than just varaible declared and can be allocated with linker or dynamically at runtime. Many characteristics of data determine how to be mapped into the data segment.  
Allocated data can have varying size, access, scope, location, creation time, lifetime.  
Data allocation can be specified by utilizing variable types, type qualifiers, type modifiers, storage classes, compiler attributes and specilized functions.
## Static  
---   
   
## Dynamic  
---   
Data that is allocated at run time and managed directly by the software programmer. This allows users to reuse memory instead of statically allocating it. This requires malloc and free.
# Busses   

-  AMBA (advanced microcontroller bus architecture)
-  AHB
	-  Fast/High bandwidth interfaces
-  Private Cortex-M4 Busses
	-  Internal Private Peripherals Bus PPB
		-  SCB, NVIC, MPU
	-  External Private Peripherals Bus PPB
		-  External Debugging
-  AHB External Core AHB busses
	-  System Bus (AHB-Lite)
		-  SRAM
		-  High Speed Peripherals
		-  Peripheral Bridge
	- Flash Bus
		-  I-Code Bus
		-  D-Code Bus
	-  Flash busses allow for fetching of code and flash data simultaneously
-  Peripheral Bus
	-  Advance Peripheral Bus (APB)
		-  Low Bandwidth Bus
		-  Connected to CPU via Bridge to System Bus
	-  Interfaces with low Bandwidth
		-  Communications
			-  UART
			-  SPI
			-  I2C
		-  Timers
		-  ADC


   
# Memory Alignment   
## Packed  
---   
Data packed is memory efficient but CPU inefficient
## Aligned  
---   
Data aligned is CPU efficient and memory inefficient because of the added "padding" 

## Data Order
---
- Each address stores 1 byte
- Half word stores 2 bytes
- Word stores 4 bytes
- Most Significant Byte MSB
- Least Significant Byte LSB


## Endianness  
---   
How data is represented or the byte order in memory. 
- Little Endian
- Big Endian

MSB - Most Significant Bit  
LSB - Least Significant Bit 
These are only relevant for multi-byte data 
#### Little Endian  
---   
MSB Stored at the largest address 
#### Big Endian  
---   
MSB Stored at the smallest address
# Registers Details
Register data constantly changes, data is loading in from memory and results are stored back to memory.

Assembly relative load/store examples:
```
ldr r1, [r7,#8]
str r1, [r7,#8]
```

Each system architect have different memory maps for different types of memory. Peripherals, System, and Vendor have specific regions with immutable addresses.

Typical Register Memories:
- Internal Core CPU
- Internal Private Peripherals
- External Private Peripherals
- General Peripheral Memory


## Internal Core CPU  
---   

Cortex-M CPU core registers
- r0-r12 general purpose
	- used on every clock cycle
	- always updating
- r13-r15 special role, (lr,sp,pc)



## General Purpose Registers  
---   
General purpose store operation operands R0-R12
## Special Registers  
---
Special purpose track and control CPU state   
   
## Program Status Registers  
---   
Program status registers - helps captures the current CPU and program application state  
Not part of the memory map and require assembly to read/write data to them (MRS/MSR)
#### APSR  
---   
application program status registers   
-  Contains current state of condition flag from previous instruction execution
-  Contains status flags:
	-  N - Negative
	-  Z - Zero
	-  C - Carry
	-  V - Overflow
	-  Q - Saturation


#### IPSR  
---   
interrupt program status registers  
- contains the exception type number of the current ISR
- Exception Numbers
	- 0 = reset
	- 1 = Non maskable interrupt (NMI)
	- 2 = Hard Fault
	- 3 = Memory Management Fault
	- 16 = IRQ0
	- 17 = IRQ1
	- N+15 = IRQ(n-1)


#### EPSR  
---   
exception program status registers 
## Exception Mask Registers  
---   
   
#### PRIMASK  
---   
Prevents activation of all exceptions with configurable priority if set to 1
#### FAULTMASK  
---   
 Prevents activation of all exceptions with configurable priority except the non maskable interrupt (NMI) if set to 1  
#### BASEPRI  
---   
Defines minimum priority for exception processing
## Control Registers  
---   
allows processor move between privilege and non privileged states  
#### FPCA  
---   

Floating point state active
- 0 = No floating point context active
- 1 = Floating point context active


#### SPSEL  
--- 
Selects current stack pointer  
-  0 = MSP - Main stack pointer
-  1 = PSP - process stack pointer
   
#### NPRIV  
---   
Define privilege level 
-  0 = privileged
-  1 = unprivileged


## Private Peripherals  
---   
   
#### Internal Private Peripherals  
---   
   
#### External Private Peripherals  
---   
   
#### System Specific  
---   
-  System Control Space SCS
	-  System Control Block SCB - help perform software resets <-Private Peripherals
		-  Processor Debug Control
		-  FPU
	-  NVIC - configures all priority levels for various interrupts<-Private Peripherals 
		-  MPU
	-  SysTick Timer <-Private Peripherals
	-  Misc system control registers
-  FPB
-  DWT
-  ITM ETM - used to debug from external program<- External peripherals 


## Peripherals  
---   
-  Peripheral Bit Band Alias Region
-  Peripheral Region
	-  Each region for each device is a 4kb slot 
	-  The amount of regions are platform dependent
	- Each region has their own specific registers to help configure the device
	-  Some registers might even have their nested registers


   
## SRAM  
---   
 
#### SRAM Bit Band Alias  
---   
   
## Code  
---   
** reserved bits can be 
- unused
- reserved for advanced sub-family models
- for internal use only


   
## General Peripheral Memory  
---   
   
# Interacting With Memory  
Load Store Architecture
- CPU Register memory is small
	- 16 Registers (R0-R12, SP, PC, LR)
	- 5 Special Function Registers
- CPU Register data constantly changes
	- Data is loaded in from memory
	- Results are stored back into memory
- All processing occurs in CPI


- Memory storage interacting with the CPU
	- Code Memory
	- Data Memory
	- Registers (Peripherals)
- Load-Store architecture requires operations to occur in CPU
	- Data gets loaded into the CPU 
	- Data is operated on 
	- Data is stored back
- Load data can be byte sized, half word sized 2 byte, and word sized 4 byte

Read Modify Write
- Read: Data is loaded into the CPU
- Modify: Data is operated on
- Write: Result is stored back
- Compiler tries to reduce number of loads and stores for execution efficiency

Peripheral Registers
- Peripheral register require some contents (bit-fields) to be perserved
- Use bit manipulation to change certain bits of a register (not at all contents)

```
uint8_t * ptr = (uint8_T*)0X1000;

*ptr |= 0x10; // set 4th bit without changing other bits;
*ptr &= ~(0x10); // clear the 4th bit without changing the others;
```

## Configuring Endianness
- Configuration is available on many modern platforms
- ARM Cortex-M allows for configuration of data memory endianness
	- Code memory is set to little endian
	- Changing endianness requires a reset
- Application interrupt and reset control register (AIRCR)
	- Allows for reconfiguration of data memory endianness
	- Bit 15 of AIRCR Register 
		- 0 - little endian
		- 1 - big endian
- Troubles must be accounted for:
	- supporting multiple platforms/architectures with the same code base
	- connecting multiple systems together
		- This can be remedied with byte swapping function


## Peripheral Access Methods
These methods are used to read/write data. You can directly deferencing of memory or structure overlays.
#### Directly Dereference Memory
- Do not need a pointer variable to read/write to memory
```
(*((volatile uint16_t*)0x40000000)) = 0x0202; // equivalent to creating a pointer and deferencing it to mutate it but it save on data memory storage   
// its hard to read and maintain
```
To make it more readable you can use a preprocessor to define an access method without using hardcoded values
```
/* 8,16,32 Bit register access macros*/  
#define HWREG8(x)  (*((volatile uint8_t*)x))
#define HWREG16(x) (*((volatile uint16_t*)x))
#define HWREG32(x) (*((volatile uint32_t*)x))
#define TA0CTL (HWREG16(0x40000000))
```
These defines can be held in separate header files which can compile time switch.Volatile tells compiler not to optimize this code
- Volatile variable needs to be directly read and written when specified

Peripherals should be configured as soon as code executes, not moved to a later point in timeStructure Overlay
- Define a structure to directly match peripheral regions registers
```
// Define the base address of the peripheral regions
#define PERIPH_BASE ((uint32_t) 0x40000000)
#define TIMER_A0_BASE (PERIPH_BASE + 0x00000000)
#define TIMER_A1_BASE (PERIPH_BASE + 0x00000400)
#define TIMER_A2_BASE (PERIPH_BASE + 0x00000800)

// mutiple timer modules, different addresses
#define TIMER_A0 ((Timer_A_Type*) TIMER_A0_BASE)
#define TIMER_A1 ((Timer_A_Type*) TIMER_A1_BASE)
#define TIMER_A2 ((Timer_A_Type*) TIMER_A2_BASE)

#define __IO (volatile)
#define __I (volatile const)

typedef struct{
	__IO uint16_t CTL
	;__IO uint16_t CCTL[7];
	__IO uint16_t R;
	__IO uint16_t CCR[7];
	__IO uint16_t EX0;
	uint16_t RESERVED0[6];
	__I uint16_t IV;
} Timer_A_Type;

// Example use 
// -> deference from structure also doesn't take data memory storage
TIMER_A0->CTL 0x0202;

```
#### Structure Overlay
Structure overlay requires exact replica of peripheral regions
- size registers to equivalent standard types
- order matters
- leave space for reserved bytes
- read-only registers = Const!
- all registers are volatile

Bit Manipulation is used to configure microcontrollers
-  Peripheral registers require some contents (bit-fields) to be preserved
-  Use bit manipulation to change certain bits of a register (not all contents)\
-  standard is using hexadecimal in these operations to prevent errors

Bit Masks are constant expressions used to set clear or toggle a specific set of bits

Peripheral Configuration
- Often need to combine set and clear to create desired effect without destroying other bit values
	-  Set with OR
	-  Clear with AND/Complement(~)
	-  Preserve other bit values with combine logic and assignment


#### Bit Band Alias
-  Each bit in the peripheral & SRAM region is a bit addressable
	-  Bit are word aligned
-  Alias region is offset 0x020000000
	-  Peripheral Bit Band: 0x42000000
	-  SRAM Bit Band: 0x22000000
-  Allow single bit to be read or written to
-  Negatives
	-  Reduces the overall available memory for other hardware
-  Positives
	-  Reduces number of instructions needed for read, modify, write
		-  Operation is atomic - only one instruction is needed and it cannot be interrupted

