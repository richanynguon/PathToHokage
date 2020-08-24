# Tooling   
- [Software](#Software)   
    - [IDE](#IDE)   
    - [GNU Toolchain](#GNU-Toolchain)   
        - [GNU Debugger](#GNU-Debugger)   
        - [Binary Utilities](#Binary-Utilities)   
            - [GNU Size](#GNU-Size)   
            - [NM](#NM)   
            - [Objcopy](#Objcopy) 
            - [Objdump](#Objdump)   
            - [Readelf](#Readelf)   
        - [Make](#Make)   
    - [Version Control](#Version-Control)   
- [Hardware](#Hardware)   
    - [Selector Guide](#Selector-Guide) 
    - [Product Brief](#Product-Breif)  
    - [Data Sheets](#Data-Sheets)   
    - [Family Technical Reference Manuals](#Family-Technical-Reference-Manuals)   
    - [Chip Errata](#Chip-Errata)   
# Software   
## IDE  
---   
Integrated Development Enviroment is software for building applications.  

Code Composer Studio is the recommended IDE for this course.  

[![MSP432 CCS Tutorial](../assets/CCSv4_IDE_Debug.jpg)](https://www.youtube.com/watch?v=SEELbfUnYmA)

   
## GNU Toolchain  
---   
   
#### [GNU Debugger](https://www.gnu.org/software/gdb/)  
---   

Allows user to see what is going on `inside' another program while it executes -- or what another program was doing at the moment it crashed
   
[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#GDB)

#### Binary Utilities  
---   
   
###### GNU Size  
---  

Display the sizes of the compiled sections inside your object files and executable file outputs

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#Size)
   
###### NM  
---   
The symbol utility allows us to investigate the size of all the possible symbols that are defined in a given executable or object file.

Symbols are identifiers in your source code that can be referenced
- Variables
- Functions 
- Debug  

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#NM) 

###### Objcopy 
---   
The object copy utility is used to convert object files from one format to another and make a copy of an object files.

Executable output types:
- Binary
- srec (Motorola S-Record)
- intel Hex Record (ihex)
- elf32-littlearm
- elf32-bigarm

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#Objcopy) 

###### Objdump  
---   

Dumps information about an object which includes: section header, symbols, and debugging information.  
Objdump can take object files and dumb assembly from the machine code.  

This program allows you to debug symbols from your c-program and assembly to intermix.

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#Objdump) 
   
###### Readelf  
---   

Displays information about a ELF formatted files:
- Compiled sections
- Memory section
- Symbol Tables
- Architecture Specifics

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#ReadElf) 

#### Make  
---   

 A tool to automate the process of compiling files into an executable using a makefile.  

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#Make) 

## Version Control  
---   

 A system that manages a program.  

 Git is a popular version control system.  

[Commands](https://github.com/richanynguon/PathToHokage/blob/master/Embedded_System/coursera_ese/src/Quick_Commands.md#Git) 

   
# Hardware   
## Selector Guide  
---
   
A parametric tool that allows you to find and compare the specifications and features of devices  

## Product Brief   
---   
A brief which gives concise overview of a product, talks about use cases, gives more detailed feature specifications.

## Data Sheets  
---   

Data sheets are an informative dense read that contains detailed technical specifications
These can contains types of details like such:
- Electrical
- Timing
- Environmental
- Physical Package


   
## Family Technical Reference Manuals  
---   
A manual that gives information about

- Configuration Details
- Operation descriptions
- Used to write Bare-Metal Firmware


   
## Chip Errata  
---   
   
A document that shows error descriptions  and provides corrective information or workaround to issue

