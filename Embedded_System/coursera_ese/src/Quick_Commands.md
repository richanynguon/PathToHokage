# Quick Commands   
- [GNU Toolchain](#GNU-Toolchain)
- [GNU GCC](#GNU-GCC)
- [Make](#Make)
- [GDB](#GDB)
- [Arm Specific Commands](#Arm-Specific-Commands)
- [Assembler](#Assembler)
- [Compiler](#Compiler)
- [Linker](#Linker)
- [Size](#Size)
- [NM](#NM)
- [Objcopy](#Objcopy)
- [Objdump](#Objdump)
- [ReadElf](#ReadElf)
- [Linux](#Linux)
- [Git](#Git)

# GNU Toolchain  
## GNU GCC  
---
Creates a executable  

```
g++ -o <exe_file_name> <Filename.cpp>
```
Runs executable  

```
./<exe_file_name>
```
GCC Flags  
| Options & Format    | Purpose                                      |
|---------------------|----------------------------------------------|
| -c                  | Compile and Assemble File but does not link  |
| -o <FILE>           | Compile. Assemble, and Link to OUTPUT_FILE   |
| -g                  | Generate Debugging Information in Executable |
| -Wall               | Enable all warning messages                  |
| -Werror             | Treat all warnings as errors                 |
| -I<DIR>             | Include this <DIR> to Look for headers files |
| -ansi -std=STANDARD | Specify which standard version to use        |
| -v                  | verbose output from GCC                      |  

Command Structure of Compiling and Linking  
```
gcc -std=c99 -Werror -o main.out main.c
```
Just Compiling With Verbose Messages  
```
gcc -std=c89 -Wall -v -c main.c -o main.o
```
C to Assembly With Architecture Flags  
```
arm-none-eabi-gcc -std=c99 -mcpu=cortex-m0plus -mthumb -Wall -S main.c -o main.s
```
## Make  
---
## GDB  
---
Compile Program with Debugging Option
```
cc -g <filename.cpp>
```
Launch gdb
```
gdb a.out
```
Set Breakpoints
```
break line_number
break [file_name]:line_number
break [file_name]:func_name
```
Execute debugger
```
run [args]
```
Printing variables
```
print {variable}
```
Controller commands
```
l     //list
p     //print
c     //continue
s     //step
ENTER    //pressing enter key would execute the previously executed command again.
```
Miscellaneous gdb commands

```
l command    //Use gdb command l or list to print the source code in the debug mode. Use l line-number to view a specific line number (or) l function to view a specific function.
bt     //backtrack – Print backtrace of all stack frames, or innermost COUNT frames.
help     //View help for a particular gdb topic — help TOPICNAME.
quit     //Exit from the gdb debugger.
```
Can tell compiler to stop after preprocessing
```
gcc -E -o main.i main.c 
```

Linking Commands Variations
```
gcc <other-options-here> -Xlinker -T Xlinker mk125z_lnk.ld
gcc main.c -o main.out -W1, -T, linker_file.lds

// Include map using Xlinker
gcc <other-options-here> -Xlinker -Map=main.map
gcc <other-options-here> -Xlinker -T=mk125z_lnk.ld

// Include map using Wl
gcc <other-options-here> -Wl, options
gcc <other-options-here> -Wl, -Map=main.map
gcc <other-options-here> --Wl, -Map=main.map
```

| Option & Format     | Purpose                                                     |
|---------------------|-------------------------------------------------------------|
| -map [NAME]         | Outputs a memory map file [NAME] from the result of linking |
| -T [NAME]           | Specifies a linker script name [NAME]                       |
| -o [NAME]           | Place the output in the file name  [NAME]                   |
| -O<#>               | The level of optimization from [#=0-3] (-O0, -O1, -O2, -O3) |
| -Os                 | Optimize for memory size                                    |
| -z stacksize=[SIZE] | The amount of stack space to reverse                        |
| -shared             | Produce a shared library (dynamic linking library)          |
| -l [LIB]            | Link with a library                                         |
| -L {DIR}            | Including the following library path                        |
| -Wl, <OPTION>       | Pass Option to linker from compiler                         |
| -Xlinker <OPTION>   | Pass option to linker from compiler                         |
| -nostdlib           | Prevent auto link of standard libraries                     |  
# ARM Specific Commands
Arm Toolset  
| Name      | Symbol | ARM Executable        | Purpose                                                 |
|-----------|--------|-----------------------|---------------------------------------------------------|
| Assembler | as     | arm-none-eabi-as      | Create assembly code                                    |
| Compiler  | gcc    | arm-none-eabi-gcc     | Create executable                                       |
| Linker    | ld     | arm-none-eabi-ld      | Links files together                                    |
| size      |        | arm-none-eabi-size    | Lists the sections size for object and executable files |
| nm        |        | arm-none-eabi-nm      | List the symbols from object files                      |
| objcopy   |        | arm-none-eabi-objcopy | Copies and translate object files                       |
| objdump   |        | arm-none-eabi-objdump | Display information from object filkes                  |
| readelf   |        | arm-none-eabi-readelf | Display information from elf files                      |  

Compiler Flags   
| Options & Format  | Purpose                                                   |
|-------------------|-----------------------------------------------------------|
| -mcpu=[NAME]      | Specifies target ARM processor and architecture           |
| -march=[NAME]     | Target ARM architecture                                   |
| -mtume=[NAME]     | Target Arm processor                                      |
| -mthumb           | Generate code in Thumb States                             |
| -marm             | Generate code in ARM states                               |
| -mthumb-interwork | Generate code that supports calling between ARM and Thumb |
| -mlittle-endian   | Generate code for little Endian Mode                      |
| -mbig-endian      | Generate code for big Endian Mode                         |    


# Size 
```
size
```
[Documentation](https://ftp.gnu.org/old-gnu/Manuals/binutils-2.12/html_node/binutils_8.html)
# NM 
```
NM
```

Flags 
```
T: Code
R: Read only
D: Initialized data
B: Uninitialized Data (BSS)
```
[Documentation](https://ftp.gnu.org/old-gnu/Manuals/binutils-2.12/html_node/binutils_4.html#SEC4)
# Objcopy  
```
arm-none-eabi-objcopy -O srec demo.out dmeo.s19
```

# Objdump 
```
objdump
```
[Documentation](https://ftp.gnu.org/old-gnu/Manuals/binutils-2.12/html_node/binutils_6.html#IDX54)
# ReadElf  
```
readelf
```
[Documentation](https://ftp.gnu.org/old-gnu/Manuals/binutils-2.12/html_node/binutils_16.html#IDX114)
# Linux
```
which // will show you where the library path is
```
```
man // will show manual for specific library
```
# Git
