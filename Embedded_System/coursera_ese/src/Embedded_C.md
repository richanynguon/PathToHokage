# Embedded C   
- [Difference Between Embedded C and C](#Difference-Between-Embedded-C-and-C)   
- [Variable Declaration](#Variable-Declaration)   
- [Data Types](#Data-Types)   
    - [Integers](#Integers)   
    - [Floating Point](#Floating-Point)   
    - [Enumerated](#Enumerated)   
    - [Derived](#Derived)   
    - [Void](#Void)   
    - [Dynamic](#Dynamic) 
    - [Char](#Char)
    - [_Bool, _Complex(c99)](_Bool,-_Complex(c99))  
- [Type Modifiers](#Type-Modifiers)    
- [Type Qualifiers](#Type-Qualifiers)   
- [Storage Classes](#Storage-Classes)   
- [Standard](#Standard)   
    - [Integer Sizes](#Integer-Sizes)   
    - [Fast Types](#Fast-Types)   
    - [Least Types](#Least-Types)   
- [Bit Manipulation](#Bit-Manipulation)   
    - [Bit shift](#Bit-shift)     
    - [And](#And)   
    - [Or](#Or)   
    - [Xor](#Xor)   
    - [Complement](#Complement)   
- [Pointers](#Pointers)   
    - [Null Pointer](#Null-Pointer)
    - [Void Pointer](#Void-Pointer)   
    - [Double Pointer](#Double-Pointer)   
    - [Restrict](#Restrict)   
    - [Function](#Function)   
- [Attributes](#Attributes)   
    - [Memory Alignment](#Memory-Alignment)   
        - [Aligned](#Aligned)   
        - [Packed](#Packed)   
    - [GCC](#GCC)   
        - [Always inline](#Always-inline)   
- [Typedef](#Typedef)   
- [Structures](#Structures)   
- [Enumerations](#Enumerations)   
- [Unions](#Unions)   
- [Bit Fields](#Bit-Fields)   
- [Encapsulation](#Encapsulation)   
    - [Composite Data Structure](#Composite-Data-Structure)   
    - [Abstract Data Structure](#Abstract-Data-Structure)   
- [Preprocessor Directives](#Preprocessor-Directives)   
    - [#define, #undef](##define,-#undef)   
    - [#ifndef, #ifdef, #endif, #elif, #else](##ifndef,-#ifdef,-#endif-#elif,-#else)   
    - [#include](##include)   
    - [#warning, #error](##warning,-#error)   
    - [#pragma](##pragma)   
    - [Macro](#Macro)   
        - [Macro Issues](#Macro-Issues)   
        - [Port Macros](#Port-Macros)   
        - [Bit Band Macros](#Bit-Band-Macros)   
- [Abstract Data Structures](#Abstract-Data-Structures)   
    - [LIFO](#LIFO)   
    - [FIFO](#FIFO)   
    - [Linked List](#Linked-List)   
- [Memory Manipulation](#Memory-Manipulation)   
    - [Directly Dereferencing Memory](#Directly-Dereferencing-Memory)   
        - [Pointer Casting](#Pointer-Casting)   
        - [Typedef struct](#Typedef-struct)   
    - [Heap Data Manipulation](#Heap-Data-Manipulation)   
        - [Malloc](#Malloc)   
        - [Calloc](#Calloc)   
        - [Realloc](#Realloc)   
        - [Free](#Free)   
- [Inline and Static Keyword](#Inline-and-Static-Keyword)   
# Difference Between Embedded C and C
- Embedded C has Optimum Features with minimum space and time
- Efficient Memory Management
- Timing Centric Operation
- Direction Hardware/IO Control
- Code Size Constraints
- Optimized Execution

# Variable Declaration
Variable declarations are formatted in   
type-qualifier(s) type-modifier data-type variable-name = initial-value;
```C
const unsigned char foo = 12;
long int foo;
foo = 400;
```
# Data Types 

## Integers  
---   
   
## Floating Point  
---   
   
## Enumerated  
---   
   
## Derived  
---   
   
## Void  
---   
   
## Dynamic  
---   

## Char
---

## _Bool, _Complex(c99)
   
# Type Modifiers   
Type modifiers dictates how many bytes are needed to store that variable.

|      Type      | Storage Size |                       Value Range                       |
|:--------------:|:------------:|:-------------------------------------------------------:|
|  unsigned char |    1 byte    |                         0 - 255                         |
|   signed char  |    1 byte    |                       (-128) - 127                      |
|      char      |    1 byte    |                 (-128) - 127 / 0 - 255                  |
| unsigned short |    2 bytes   |                       0 -  65,535                       |
|      short     |    2 bytes   |                   (-32,768) - 32,767                    |
|  unsigned int  | 2 or 4 bytes | (-32,768) - 32,767  /  (-2,147,483,648) - 2,147,483,647 |
|       int      | 2 or 4 bytes |             0 -  65,535 / 0 - 4,294,967,295             |
|  unsigned long |    4 bytes   |             (-2,147,483,648) - 2,147,483,647            |
|      long      |    4 bytes   |                    0 - 4,294,967,295                    |

 
# Type Qualifiers   
- Const type qualifier
    - Allocates the data as a constant, will be mapped to read-only memory like flash
    - Sub segment name is application dependent like .rodata, .const
# Storage Classes   
Storage classes specify lifetime and scope of a data.
- Auto
    - Automatically allocate and deallocated data on the stack
    - Has a lifetime of a function or a block
- Static
    - Data will persist in memory until the end of the program
    - Can be stored in .data and .bss
- Extern
    - Declares a global reference defined in another file to be visible by current file / allows variable to exist outside current scope of access.
        - This can be stored in .bss or .data
        - Initial definition must be a global variable
- Register
    - Allocates data directly in the CPU
        - Used for repeated variables use with high speed
        - This is not guaranteed and is not commonly used
# Standard Integer Sizes  
- Variable length types can cause portability
- Explicitly defined types that specify storage and sign
	- Provide exact size, minimize size, and fast size
- Define in the stdint.h header file
- Explicitly defined types that specify exact size and sign
	- U = Unsigned
	- Int = Integer type
	- #, 8,16,32 bit
	- _t=type


   
## Fast Types  
---   

- You need a data size that allows for the fastest access while having at least N bits
- Typically rounds up to word sizes - most optimum size for operations


## Least Types  
---   
- You need the smallest data size that has a minimum size of N bits
# Bit Manipulation 
Bit Manipulation is used to configure microcontrollers  
## Bit Shift
---
#### Logical Shifts
---
When shifting with a logical shift, the least-significant bit is lost and a 00 is inserted on the other end.
#### Arithmetic Shifts
---
When shifting with an arithmetic shift, the least-significant bit is lost and the most-significant bit is copied.
## And  
---   

The output of bitwise AND is 1 if the corresponding bits of two operands is 1. If either bit of an operand is 0, the result of corresponding bit is evaluated to 0.

```
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bit Operation of 12 and 25
  00001100
& 00011001
  ________
  00001000  = 8 (In decimal)
```
   
## Or  
---   

The output of bitwise OR is 1 if at least one corresponding bit of two operands is 1. In C Programming, bitwise OR operator is denoted by |.


```
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise OR Operation of 12 and 25
  00001100
| 00011001
  ________
  00011101  = 29 (In decimal)
```
## Xor  
---  

The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. It is denoted by ^.

```
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise XOR Operation of 12 and 25
  00001100
^ 00011001
  ________
  00010101  = 21 (In decimal)
```
   
## Complement  
---   
Bitwise compliment operator is an unary operator (works on only one operand). It changes 1 to 0 and 0 to 1. It is denoted by ~.


```
35 = 00100011 (In Binary)

Bitwise complement Operation of 35
~ 00100011 
  ________
  11011100  = 220 (In decimal)
```
# Pointers  
Pointers address are different on each systems depending on the amount of memory there is. 
```C
int foo = 0x34;
int * ptr; // Pointer Declaration Operator We use a pointer star and a variable declaration to specify a data type is a pointer.
ptr = &foo; // Address of Operator The address of operator is used to assign other variables that have been declared their addresses to pointer variables
*ptr = 0x52; // Dereference Operator The pointer dereference star, which is used after a pointer declaration, is used to dereference a point in memory

=> foo = 0x52
```
## Null Pointer
---
-  At time of pointer declaration, you might not know the address
	-  Use a null pointer for initialization
	-  Null pointers point to nothing
	-  Used to check for valid pointer
	-  Pointers with out initialized data will have garbage data and you may corrupt data using it


```
#define NULL ((void*)0)
// Access a struct data

typedef struct foo {
    unint8_T varA;    
    unint8_t varB;
}

foo_t varS
foo_t * varS_ptr = &varS
varS->varB
```
-  When converting the access type it shows only what is requested so will show 8/32 bytes if deferred like such.


## Void Pointer 
---   

- Generic pointers to memory address
- void = Lack of type, dereferencing does not make sense!
- Void pointers are not NULL pointers but a NULL pointer is a void pointer
- must cast before using
- no dereferencing on a void *
```
void * ptr1 = (void *)0x40000000;
*((uint16_t*)ptr1)= 0x0202;
```
- cannot do pointer arithmetic on a void *
- malloc and void - Malloc reserve blocks of data, it does not care how it is used
	- Returns a void pointer, you cast this pointer for intended use
- you might not know the underlying type with some processing
	- sequence of bytes being sent, first byte is type indicator


   
## Double Pointer  
---   

-  Double pointers are a pointer to a pointer
-  Must use the ** in declarations
-  Used to set value of a pointer addr
	-  single dereference accesses pointer address
	-  double dereference access pointer data
-  Copies of pointers are made when passed into a function
	-  original pointer address cannot be altered!


   
## Restrict  
---   

- Restrict type qualifier helps compiler to optimize memory interactions
- Introduced in c99 standard
```
uint32_t * restrict ptr4;
```

-  must use the restrict qualifier after the * in declarations
-  only the data  at this locations or data near is accessed by this pointer
-  largest speed up comes from iterative memory interaction
	-  compiler removes unneeded assembly instructions
	-  restrict tells compiler that this memory is not overlapped with any other parameters or aliases to other pointers and it can go ahead optimizing the interaction with memory
	-  Reduces couple assembly instructions per loop
   
## Function  
---   
-  Defined just like a function
	-  return type
	-  function parameters
	-  pointer name
-  Dereferencing the function pointer yields the referenced function, which can be invoked and passed arguments just as in a normal function call.

```
<type>(*<function_pointer_name>)(<parameter list>) = <function-address>;
void(*foo)();
int8_t void (*bar)(int8_t a, int8_t *b);
```
- Initialization and assignment to a function pointer should have matching return types and parameter list
- Can generalize function pointer type with a typedef
	- using typedef we can define as many function pointer variables 

```
typedef int (*fptr_TYPE)(int c, int d);

// two function pointer declarations
fptr_TYPE = fptr1 = &foo;
fptr_TYPE = fptr2 = &bar;

// defined functions
int foo(int a, int b);
int bar(int c, int d);

// calling the function
ret = fptr1(1,3);
ret = (*fptr2)(4,5);
```
-  Can also use a pointer array  

```
typedef void(*FuncPtr_t[2])();

FuncPtr_t example = {foo,bar};

// or 

typedef void(*FuncPtr_t)();

FuncPtr_t example[2] = {foo,bar};

typedef enum
{
FP_FOO=0,
FP_BAR=1,
}FP_e;

example[FP_FOO]();
example[FP_BAR]();
```
Can also be defined like

```
typedef void func_t(int);
func_t * my_func_pointer = void this_func(int a){
 // i do something here
};
```

# Attributes

Attributes can give specific details on how to compile code for
- variables
- structures and structure members
- functions

Attributes are not part of the C-standard so there are not portable across the compilers

Alignment Attributes specifiy memory alignment for data
- Power of two, 2,4,8,16;

```
int8_t foo__attribute__((aligned(4))); // to align on a 4 byte boundary
int8_t foo__attribute__((packed)); // packs the data

/* 
Skips calling convention, copies function body into calling code
always_inline is a gcc attribute and not supported by other compilers
*/
__attribute__((always_inline))inline int32_t add(int32_t x, int32_t y){
    return(x+y);
}
// inline key word is a c99 feature not support in c89
```

## Memory Alignment  
---   
   
#### Aligned  
---   
```
int8_t foo__attribute__((aligned(4))); // to align on a 4 byte boundary
```
#### Packed  
---   
```
int8_t foo__attribute__((packed)); // packs the data
```
   
#### Always inline  
---   
```
Skips calling convention, copies function body into calling code
always_inline is a gcc attribute and not supported by other compilers
*/
__attribute__((always_inline))inline int32_t add(int32_t x, int32_t y){
    return(x+y);
}
// inline key word is a c99 feature not support in c89
```
# Typedef   
Typedef keywords allow programmer to create their own types or derived types
# Structures   

- allows you to create your own types made up of:
	- Standard C-Types
	- Derived Types
	- Enumerated Types
	- Other

```
struct <STRUCT-NAME>{
    <TYPE> <MEMBER-NAME>;
   <TYPE> <MEMBER-NAME>;
}
```

# Enumerations  
-  Enums are an enumerated type built into C-programming
	-  Integer data type
-  Enumeration definitions does not reserve memory
	-  Only the declaration of an enumerated type
-  Multiple implementation exists (per eABI)
	-  normally unsigned int or signed int
	-  Alternatively smallest integer type to fit all enumerated values
-  Good practices are up to the developer and team
-  Suggestions:
	-  Write enum constants in capitals
	-  Prefix each enum constants with a type acronym
	-  add final enum
-  Re-declarations of enumertor names will cause compile errors.

```
//Circular Buffer Enum ex
typedef enum {
    CB_NO_ERROR = 0,
    CB_ERROR,
    CB_NULL,
    CB_FULL,
    CB_EMPTY,
    CB_END, // final enum
}CB_Status_e;
```
-  when compiled enums might be 4 bytes 
-  can add -fshorts-enums to reduce the sizes of the enum


# Unions  
Derived data type containing multiple data members that occupy the same address

```
union <union_type>{
    <type> <name>;
    <type> <name>;
};

typedef union {
    uint8_t x;
    uint8_t y;
    uint8_t z;
} ex1;

ex1 point;
point.x = 0x15;
```
-  Unions can contain multiple members
	-  Each can be different types and sizes
-  Size of a union is equal to largest member
-  Core microcontroller standard interface software (CMSIS) provides Core CPU register structure definitions in core_cm4.h


# Bit Fields   

-  Bit fields allow us to allocate, read & write data within a union or struct that is smaller than a byte
-  Use a colon after name to specify bit length
```
struct <name> {
    uint32_t x:BITSIZE;
    uint32_t y:BITSIZE;
    uint32_t z:BITSIZE;
};

// or 

union <name> {
    uint32_t x:BITSIZE;
    uint32_t y:BITSIZE;
    uint32_t z:BITSIZE;
};
```

-  Must be assigned a value that can fit within the type
-  Bit field must be less than total type size, length 0 is possible. it ends the unit, so that the next bit field is not put into the same unit, even if it fits - but almost no one uses it.
-  Bit fields pack into the type listed, until they cannot fit
-  bit fields can be mixed with normal structure members


Bit Fields Pack
-  Bit fields will pack one right after another until type size is met or exceeded
-  Reading/Writing bit fields implicitly use bit manipulation operations
	-  reduces your execution efficiency
	-  increase your storage efficiency


Bit Fields Alignment
-  Bit fields can enforce a particular alignment internal to structure
	- use :0 with no bit name
	-  use this to ensure a specific bit orientation or mapping

```
// just an example you wouldn't typically write to APSR
APSR_Type aspr;
aspr.w = 0xF0000000;

aspr.b.N // b accesses the bit field structure and N accesses the individual field we intend to write to

__ASM lets us use inline assembly
```

# Encapsulation  
Encapsulation is a means to enclose the operation or interaction with software construct within a processing entity 
## Composite Data Structure  
---   
-  Structure is defined using only built in c-types and /or other composite data types
	-  not necessary to define the interface

## Abstract Data Structure  
---
- Structure that can be applied to any number of applications
	- must define structure and interface
	- comes in the form of encapsulated methods acting on a data structure

Interfaces methods allow for operations on a structure including:
- Adding new data
- removing data
- initializing a structure
- clearing a structure


- LIFO - Last in first out buffer
- Circular FIFO first in first out buffers
- linked list - singly doubly circular


---   
   
# Preprocessor Directives   
Special keywords used by the preprocessor before compiling. These can help perform compile time switches. Directives will start with "#".

Compile time switches are conditions provided at compile time to dictat what should be compiled. It uses a combination of #if-else and #define.  
Pros:
- Allow use of the same code for different platforms since each platform has a unique hardware and firmware configuration
- Offers less overhead and greater imporvements for writing maintainable and readable programs
Cons:
- No type checking, increase probability of bugs and increase code size

There are newer features and alternatives but its good to know for older code bases

## #define, #undef  
---   
#define   
#define can be used for defining constants, features, or macro functions
```C
#define <MACRO-NAME><MACRO-VALUE>
#define <FEATURE-NAME>
```
#undef  
#undef removes a defined component.
   
## #ifndef, #ifdef, #endif, #elif, #else 
---   
These directives conditionally compiles a block of code. These are useful for debugging.  
#ifndef if not defined  
#ifdef if defined  
#elif  else if  
#else  else  
#endif  end if block this is required  
   
```C
// example of a run time switch
int main (void){
   #ifdef( KL25_PLATFROM ) && !defined ( MSP_PLATFORM)
     kl25_init();
   #elif ( MSP_PLATFORM ) &&  !defined( KL25_PLATFROM )
     msp_init();
   #else
     #error "Plaese specify one platfrom target"
   #endif
    return 0;
}
```
## #include  
---   
The #include directive includes software defined in other files and the declaration gets copied.

```C
#include "uart.h"     //include file from local directory
#include <stdio.h>     //include file from a library path or include path
```
   
## #warning, #error  
---   
   
## #pragma  
---   
The #pragma directive gives a specific instruction to the compiler controls compilation from software instead of the command line. These instructions are usually implementation / compiler specific and unrecognized pragma will be ignored.

```C
#pragma GCC push_options    //Adds options to compiler for specific functions
#pragma GCC posion printf sprint fprintf    //causes an error during compilation if code uses these functions
#pragma GCC target ("arch=armv6") -or- ("cpu=cortex-m0plus")    //compile a function with a specific architecture
```


- Pragmas provide special instructions to the compiler
	- Push/pop - add extra option for compilation
	- Optimize - Specify a certain level of optimization block of code

```
#ifndef(__GNUC__)
#define __attribute__(x) // gcc compiler keyword that throws errors for other compilers
#endif

#pragma GCC push // this pushes it the the GCC function list
#pragma GCC optimize("O0") // this optimizes at an O0 level
int32_t add(int32_t x, int32_t y){
    return(x+y);
}
#pragma GCC pop // removes it from the GCC function list
```

- Embedded teams can support multiple chipset platforms and multiple architectures
	- Different architecture may require different compiler


## Macro  
---   
```C
#define <MACRO-NAME><MACRO-VALUE>
```
#### Macro Issues  
--- 
When macros are defined they are not computed before plugged in thus creating such a scenario:  
```C
#define SQUARE (x) (x*x)

int main(){
   int y_squared;
   int y= 2;
    y_squared = SQUARE(y++); // this translate to y_squared(y++*y++);
    return 0;
}
```

-  Numerous issues with macro functions
	-  No type checking
	-  Bug introduction
	-  Complex/Confusing Layers of Macros Calling Macros


#### Port Macros  
---   

- Generic memory access macro for different sized register
- Port registers use the generalized access macros

```
//Port Structure Overlay

typedef struct{
__I uint8_t IN;
uint8_t RESERVED0;
__I uint8_t OUT;
uint8_t RESERVED1;
__I uint8_t DIR;
uint8_t RESERVED2;
__I uint8_t REN;
uint8_t RESERVED3;
}DIO_PORT_TYPE;

/*Define the PORT constants and types*/
#define PIN0(0x0)
#define DIO_PORT1_ADDR ((uint32_t)0x40004C0)
#define P1((DIO_PORT_Type*)(DIO_PORT1_ADDR))

#define SET_PORT_PIN_DIR(port, pin)(((port)->DIR) |= (1<<pin))

/*set bit p1.0 to be output direction*/
SET_PORT_PIN_DIR(P1, PIN0);
```
#### Bit Band Macros  
---   

- Bit Band Region allows for atomic reads/writes of single bits for first 1MB of SRAM and Peripheral Memory
- Not all of the SRAM & peripheral memory has a bit band alias

```
#define TA0CTL_ADDR(0x40000000)

/*Bit Band Region is offset from Peripheral/SRAM*/
#define BB_OFFSET (0x02000000)

/*Macro Function to Read memory*/
#define HWREG32(addr)(*((volatile uint32_t*)(x)))

/*Bit Band Alias offset Address*/
#define BITBAND_ADDR(addr, bit)((addr & 0xF0000000) + BB_OFFSET + \
                                                        ((addr & 0xFFFFF << 5)))

/*Set bit 1 of TA0CTL Register*/
HWREG32(BITBAND_ADDR(TA0CTL, 1));
```

# Abstract Data Structures   
## LIFO  
---   
[Code Sample](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Code_Samples.md#LIFO-Buffer) 
## FIFO  
---   
[Code Sample](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Code_Samples.md#Circular-Buffer) 
## Linked List  
---   
   
# Memory Manipulation   
## Directly Dereferencing Memory  
---   

#### Pointer Casting  
---   
```
<type>(*<function_pointer_name>)(<parameter list>) = <function-address>;
void(*foo)();
int8_t void (*bar)(int8_t a, int8_t *b);
```
   
#### Typedef struct  
---   
```
typedef int (*fptr_TYPE)(int c, int d);

// two function pointer declarations
fptr_TYPE = fptr1 = &foo;
fptr_TYPE = fptr2 = &bar;

// defined functions
int foo(int a, int b);
int bar(int c, int d);

// calling the function
ret = fptr1(1,3);
ret = (*fptr2)(4,5);

//
typedef void(*FuncPtr_t[2])();

FuncPtr_t example = {foo,bar};

// or 

typedef void(*FuncPtr_t)();

FuncPtr_t example[2] = {foo,bar};

typedef enum
{
FP_FOO=0,
FP_BAR=1,
}FP_e;

example[FP_FOO]();
example[FP_BAR]();
//

typedef void func_t(int);
func_t * my_func_pointer = void this_func(int a){
 // i do something here
};
```
   
## Heap Data Manipulation  
---   
   
#### Malloc  
---   
```
void * malloc(size_t size)
```

- Allocates "n" contiguous bytes in heap space
- Once you receive pointer from this function not to change address to free the address later
- returns a pointer


#### Calloc  
---   
```
void * calloc(size_t nitems, size_t)
```
- Same as malloc but also initialize spaces with 0s
#### Realloc  
---   
```
void * realloc(void * ptr, size_t size)
```
- params: heap pointer
- Reallocates region to new size, and frees old space
- returns a new pointer


#### Free  
---   
```
void free (void * ptr)
``` 

- Deallocates data back to heap free space
- Must free allocated data or heap will run out space


# Inline and Static Keyword   

- Functions are excellent for encapsulating a specialized operation
- Calling a tradition C-function can decrease performance due to calling convention overhead
	- Saving data to stack
	- Creating local varaibles
	- Branching

** Combine static and inline to prevent integrating all code into calling function 
- Linkage is internal to file

## Inline Keyword
- Compiler attributes can apply to functions
	- Inline- skips calling convention, copies function body into calling code
	- Good for small functions
	- Bad for / will not work for recursive, variadic, and long functions
		- a variadic function is a function of indefinite arity, i.e., one which accepts a variable number of arguments


## Static Keyword
- Static keyword  can apply to functions to create private access
	- Function/Variable only visible to current file






# [Converting Bases](https://www.tutorialspoint.com/computer_logical_organization/number_system_conversion.htm)