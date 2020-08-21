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
- [Types](#Types)   
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
            - [Local Variables](#Local-Variables)   
            - [Input parameters](#Input-parameters)   
            - [Return data](#Return-data)   
            - [Copy of used registers](#Copy-of-used-registers)   
            - [Return Address](#Return-Address)   
            - [Previous stack pointer](#Previous-stack-pointer)   
            - [Copy of special function registers (interrupts)](#Copy-of-special-function-registers-(interrupts))   
        - [Frame Size](#Frame-Size)   
        - [Registers](#Registers)   
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
    - [AMBA](#AMBA)   
    - [AHB](#AHB)   
    - [Private Busses](#Private-Busses)   
        - [Internal](#Internal)   
        - [External](#External)   
    - [AHB External Core](#AHB-External-Core)   
        - [System Bus](#System-Bus)   
            - [SRAM](#SRAM)   
            - [High Speed Peripherals](#High-Speed-Peripherals)   
            - [Peripheral Bridge](#Peripheral-Bridge)   
        - [Flash Bus](#Flash-Bus)   
            - [I-Code Bus](#I-Code-Bus)   
            - [D-Code Bus](#D-Code-Bus)   
    - [Peripheral Bus](#Peripheral-Bus)   
        - [Advance Peripheral Bus](#Advance-Peripheral-Bus)   
- [Memory Alignment](#Memory-Alignment)   
    - [Packed](#Packed)   
    - [Aligned](#Aligned)   
    - [Endianness](#Endianness)   
        - [Little Endian](#Little-Endian)   
        - [Big Endian](#Big-Endian)   
- [Registers](#Registers)   
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
        - [Internal Private Peripherals](#Internal-Private-Peripherals)   
        - [External Private Peripherals](#External-Private-Peripherals)   
        - [System Specific](#System-Specific)   
            - [System Control Block SCB](#System-Control-Block-SCB)   
                - [Processor Debug Control](#Processor-Debug-Control)   
                - [FPU](#FPU)   
            - [NVIC](#NVIC)   
                - [MPU](#MPU)   
            - [SysTick Timer](#SysTick-Timer)   
                - [Misc System Control Registers](#Misc-System-Control-Registers)   
        - [FPB](#FPB)   
        - [DWT](#DWT)   
        - [ITM](#ITM)   
        - [ETM](#ETM)   
    - [Peripherals](#Peripherals)   
        - [Peripheral Bit Band Alias](#Peripheral-Bit-Band-Alias)   
    - [SRAM](#SRAM)   
        - [SRAM](#SRAM)   
        - [SRAM Bit Band Alias](#SRAM-Bit-Band-Alias)   
    - [Code](#Code)   
    - [General Peripheral Memory](#General-Peripheral-Memory)   
# Characteristics   
## Capacity  
---   
   
## Volatility  
---   
   
## Access  
---   
   
## Power Consumption  
---   
   
## Latency  
---   
   
## Durability  
---   
   
## Transaction Size  
---   
   
# Hierarchy Descending Latency   
## Registers  
---   
   
## Cache L1, L2, L3  
---   
   
## RAM SRAM DRAM  
---   
   
## Flash EEPROM  
---   
   
# Types   
## Code Memory  
---   
   
#### Intvecs  
---   
   
###### Vector Tables  
---   
   
#### Text  
---   
   
#### Const  
---   
   
#### Initialized segments  
---   
   
#### Dependent bootloader  
---   
   
## Data Memory  
---   
   
## Runtime State of Program  
---   
   
# Data Segments   
## Stack  
---   
   
#### Stores  
---   
   
###### Local Variables  
---   
   
###### Input parameters  
---   
   
###### Return data  
---   
   
###### Copy of used registers  
---   
   
###### Return Address  
---   
   
###### Previous stack pointer  
---   
   
###### Copy of special function registers (interrupts)  
---   
   
#### Frame Size  
---   
   
#### Registers  
---   
   
#### Specialized Operations  
---   
   
###### Push  
---   
   
###### Pop  
---   
   
#### Stack overflow  
---   
   
## Heap  
---   
   
#### Heap Functions  
---   
   
#### Malloc  
---   
   
#### Calloc  
---   
   
#### Realloc  
---   
   
#### Free  
---   
   
#### Issues  
---   
   
## Data  
---   
   
## BSS  
---   
   
# Data Allocation   
## Static  
---   
   
## Dynamic  
---   
   
# Busses   
## AMBA  
---   
   
## AHB  
---   
   
## Private Busses  
---   
   
#### Internal  
---   
   
#### External  
---   
   
## AHB External Core  
---   
   
#### System Bus  
---   
   
###### SRAM  
---   
   
###### High Speed Peripherals  
---   
   
###### Peripheral Bridge  
---   
   
#### Flash Bus  
---   
   
###### I-Code Bus  
---   
   
###### D-Code Bus  
---   
   
## Peripheral Bus  
---   
   
#### Advance Peripheral Bus  
---   
   
# Memory Alignment   
## Packed  
---   
   
## Aligned  
---   
   
## Endianness  
---   
   
#### Little Endian  
---   
   
#### Big Endian  
---   
   
# Registers   
## Internal Core CPU  
---   
   
## General Purpose Registers  
---   
   
## Special Registers  
---   
   
## Program Status Registers  
---   
   
#### APSR  
---   
   
#### IPSR  
---   
   
#### EPSR  
---   
   
## Exception Mask Registers  
---   
   
#### PRIMASK  
---   
   
#### FAULTMASK  
---   
   
#### BASEPRI  
---   
   
## Control Registers  
---   
   
#### FPCA  
---   
   
#### SPSEL  
---   
   
#### NPRIV  
---   
   
## Private Peripherals  
---   
   
#### Internal Private Peripherals  
---   
   
#### External Private Peripherals  
---   
   
#### System Specific  
---   
   
###### System Control Block SCB  
---   
   
- Processor Debug Control   
- FPU   
###### NVIC  
---   
   
- MPU   
###### SysTick Timer  
---   
   
- Misc System Control Registers   
#### FPB  
---   
   
#### DWT  
---   
   
#### ITM  
---   
   
#### ETM  
---   
   
## Peripherals  
---   
   
#### Peripheral Bit Band Alias  
---   
   
## SRAM  
---   
   
#### SRAM  
---   
   
#### SRAM Bit Band Alias  
---   
   
## Code  
---   
   
## General Peripheral Memory  
---   
   
