# Code Design   
- [Tools](#Tools)   
    - [Flow Diagram](#Flow-Diagram)   
    - [Software Block](#Software-Block)   
    - [Component Design](#Component-Design)   
- [Standarization](#Standarization)   
    - [Versions of C Standard](#Versions-of-C-Standard)   
    - [Standard Organizations](#Standard-Organizations)
- [Coding Guideline](#Coding-Guideline)   
- [Coding Standards](#Coding-Standards)   
- [File Structure](#File-Structure)   
    - [Header File](#Header-File)   
    - [Implementation File](#Implementation-File)   
- [Platform](#Platform)   
    - [Native](#Native)   
    - [Cross](#Cross)   
- [Libraries](#Libraries)   
- [Modules](#Modules)   
# Tools   
## Flow Diagram  
---   

![Flow Diagram](../assets/flowchart.png) 
   
## Software Block  
---   

![Window Architecture](../assets/win_2000.png) 
## Component Design  
---   
A Component Design is a specification for an Adaptable Component that can be used to construct a draft application work product.  

# Standarization  
Standards provide specific syntax and features what each version of the language supports 
## Versions of C Standard  
---   
- C11
- C99
- C89/c90
- K&R C-programming

## Standard Organizations
- [International Electrical and Electronic Engineers](https://www.ieee.org/)
- [International Organization for Standardization](https://www.iso.org/home.html)
- [American National Standards Institute](https://www.ansi.org/)


# Coding Guideline  
- [MISRA C Coding Guideline - Motor Industry Software Reliability Association](https://www.perforce.com/resources/qac/misra-c-cpp)
- [Ganssle's "Firmware Development Standard"](http://www.ganssle.com/fsm.htm)

# Coding Standards Example   
- Header - A function prototype  that's really informative commented sections
- Constant information will  be represented with all capitals
- Variable names are all lowercase with their name maps with the purpose of the variable
- Indentations and newlines are used to help with readability
- Numbers in array indentation is used for multi line statements 
- Variable values and function parameters both have commas and spaces to separate each item
# File Structure   
## Header File  
---  
These files contain public function declarations and documentation.  
- Contain the function declarations, macros & derived data type definitions(structs, enums)
- Anything that needs to be accessible should be declared in the header function - they are the interface
- Make informative function comments in the header files
    - Function descriptions
    - Inputs: type and descriptions
    - Returns: type and description


[Template](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Document_Templates.md) 

## Implementation File  
---   
These files contain private declaration and all function definitions. This file should not be directly accessible by software projects so implementations are kept private.
[Template](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Document_Templates.md) 

# Platform   
When designing software it's important to understand the contrainst of the platform that you intend to run your program on.
- Native
    - Compile an executable on one system and it is intended to run on the same system - this is unusual for embedded projects
- Cross Platform
    - Platform Examples
        - RTOS
        - QNX
        - Linux Kernel
        - ARM
        - Windows Embedded Compacy
        - CompactRIO

Attempt to write as much software with architecture and platform independence to maximize portability and res usability.

Impossible to make everything independent because firmware layer still interacts with hardware and assembly code is architecture dependent.  

Embedded systems really require the software designer to know as much about the architecture and platform as possible.  

Higher level software can be reused however the architecture and platforms are unique and require a specific interface.  

Embedded Application Binary Interface EABI provides details on how a binary must be compiled and interfaced with platform components.  
- Register Use/Word Size
	- Word Size is the operand size of the instruction set architecture
- Code/Data Storage Requirements
- Addressing Modes
- Calling Conventions
- Helper Functions and Libraries

   
# Libraries  
Collection of software (precompiled or direct source) 
Question you should Ask when including precompiled libraries:
If library is precompiled:
- Is it compiled for my architecture?
- Was this designed to be optimized for my architecture?
- If you have a full library source code:
- What software feature does this use
- What other code does this include?


String and stdio libraries - they are optimized but only for the instruction set architectures, but not for the specific platform you're using
Is there hardware offloading that can increase performance?
What are internal memory requirements does this require?  
- Static Libraries: Directly linked into your output exectuable
    - Installed with program image as part of the exectuable
    - create using archiver

- Shared Libraries: Linked dynamically at runtime with your executable
    - pre-installed onto target
    - used for applications with an operating system
    - create shared flag


Linker by default links with c-standard libraries specific for your architecture  
Can remove the dependency on using these libraries --nostdlib  
Requires to implement all libraries and support software yourself  




# Modules   
Software organization that each module has encapsulated certain functionality within a library

When you define your own modules, give it a descriptive name relating to functionality - give a similar all caps name to include guard preprocessing  

- Module Design
- Where do the logical boundaries exist?
- What have architecture dependencies?
- What have platform dependencies?

