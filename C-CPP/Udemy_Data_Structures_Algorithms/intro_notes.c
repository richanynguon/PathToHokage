/*

In business data there are two types: 
Historical/Legacy and operational

Legacy data can be kept in a data warehouse.
It can also be described as big data.
Analyzing that data are called data mining algorithms

*/

/*
Stack and Heap Memory

Larger memory divides memory into segment.

Heap, Stack, Code Sections are the divided segments.

Program code will be in code section.
Variable declarations will be in the stack.

We must assume that int is 2 bytes and float is 4 bytes 
but ultimately it depends on the compiler

16 bit compiles int is 2bytes
Dev studios code block will int will be 4 bytes

void main()
{
    int a; 
    float b;
}


                       [CPU]
                        ^v
                    __________
                    |         | 
                    |_________| <--- heap - unorganized
                    |_________| <-\
    stackframe ---> | [a][b]  | <---stack - organized
 activation rec \-> |_________| <-/
                    | main()  | <--- code section
                    |_________|

                   
static memory allocation is the memory allocated at compile time

heap can be used to describe an organized or unorganized pile
heap memory should be used as a resource
when you use it - you allocate it
when you're done delete it
you can access heap memory through a pointer

void main()
{
    int * p;
    // c++
    p=new int[5]
    //c
    p=(int*)malloc(2*5)

    delete []p;
    p=NULL;
    
}


*/

/*

Physical Data Structures
1. Array
    -- In a stack
    -- size of list is known
2. Linked Lists
    -- Heap
    -- size of list is not known
Defines how data is organized

Logical Data Structures
- Linear
1. Stacks
    - LIFO
2. Queues
    - FIFO
- Non-linear
3. Trees
    - Hiearchy
4. Graphs
    - Non-heiarchy
- Tabular
5. Hash Table

*/

/*
Abstract Data Type (ADT)
1. Representation of Data
    - has a way to show elements
    - show capacity/size
2. Operation on Data
    - add
    - remove
    - search

int x;
 ________________________________
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
 ^
 |
 sign bit

2 bytes = 16 bits
*/
