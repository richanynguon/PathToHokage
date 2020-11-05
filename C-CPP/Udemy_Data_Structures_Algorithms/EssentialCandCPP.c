#include <stdlib.h>
// array basics

/*
Main Memory

|Heap -----------------
|
|Stack ----------------
|MainFunction: 
|Variable declarations 
|Code Section ---------
|Code is here
-----------------------

*/

int main_array()
{   
    // declaration
    int A[5];
    // declaration + initalization
    int B[5] = {2,4,6,8,10};
    int i;
    for(i=0; i<5; i++)
    {
        // https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
        printf("%d", B[i]);
    }
}

// structures
/*
A rectangle 
length x breadth

|Heap -----------------
|
|Stack ----------------
|MainFunction: 
|Variable declarations 
|Code Section ---------
|Code is here
-----------------------
*/

struct Rectangle
{
    int length; // 2 byte
    int breadth; // 2 byte
}; // 4 byte of memory

int main_structures()
{
    // declaration
    struct Rectangle r;
    // declaration + initalization
    struct Rectangle r = {10,5};
    // re-assignment
    r.length = 15;
    r.breadth= 10;
    printf("Area of Rectangle is %d", r.length*r.breadth);
}

struct Complex{
    int real; // 2 bytes
    int img; // 2 bytes
}; // 4 bytes

struct Student{
    int roll; // 2 bytes
    char name[25]; // 25 bytes
    char dept[10]; // 10 bytes
    char address[50];// 50 bytes 
}; // 77 bytes

int struct_array_main()
{
    struct Student attendence[3] ={{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    printf("%c",attendence[0].name);
}

// pointers
// pointers are used to access it in a heap memory

int pointer_main()
{
    int a = 10;
    // makes a pointers
    int *p;
    // points pointer to variable a address
    p = &a;
    // deferencing or getting the value at that address
    printf("%d", *p);
}


int pointer_ex_main()
{
    int *p;
    // malloc allocates x bytes where x = 5*sizeof(int)
    // returns a void pointer and to access the pointer
    // it is require to type cast as you would do with int or char
    // it becomes (int*)
    // this will allocate in heap
    p = (int *)malloc(5*sizeof(int));
    // c ++: p = new int[5];
}

/* c++ reference
 int reference_main()
 {
    int a = 10;
    int &r = a;
     // it makes a have a second name r
    cout <<a; //10
    r++ 
    cout <<r; //11
    cout <<a; //11
}
*/ 

/*
pointer to a structure
*/
int point_to_struct(){
    struct Rectangle r = {10,5};
    struct Rectangle *p; // point takes word size assuming 2 bytes
    r.length = 15;
    (*p).length = 20;
    p->length = 20;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 10;
    p->breadth = 5;
}

// monolithic programing and keeping everything in one function
// when breaking up a function into smaller functions is called
// modular programming or procedural programming
// source code will be modular but in cpu will be monolithic

int add (int a, int b)
{
    int c;
    c = a+b;
    return (c);
}

int add_main()
{
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x,y);
    printf("sum is %d", z);
}

// parameter passing methods

// pass by value
// when you dont have to alter a parameter
// return results 
// add two values is more suitable
void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int swap_main()
{
    int a,b;
    a = 0;
    b = 20;
    swap(a,b);
    print("%d %d",a,b);
}

// pass by address
void swap(int * x, int * y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int swap_main()
{
    int a,b;
    a = 0;
    b = 20;
    swap(&a,&b);
    print("%d %d",a,b);
}

// pass by reference c++ - should not be use in complex function
/*
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int swap_main()
{
    int a,b;
    a = 0;
    b = 20;
    swap(a,b);
    print("%d %d",a,b);
}
*/

// pass array as parameters
// void fun(int * A, int n) can use this but 
// brackets show it points to an arr

void fun(int A[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d", A[i]);
    }
};

int fun_main()
{
    int A[5]={2,4,5,6,7};
    fun(A,5);
};

// return arr 
int * fun2(int n)
{
    int * p;
    p = (int *)malloc(n*sizeof(int));
    return p;
}
int return_arr_main()
{
    int * A;
    A = fun2(5);
    return 1;
}

// structure as a parameter
// pass by value
void area(struct Rectangle r1)
{   
    r1.length++; // this wont change the original value
    return r1.length * r1.breadth;
}

int struct_p_main()
{
    struct Rectangle r = {10,5};
    area(r);
    return 1;
}

// pass by reference c++
// void area(struct Rectangle &r1)
// {   
//     r1.length++; // this will change the original value
//     return r1.length * r1.breadth;
// }

// int struct_p_main()
// {
//     struct Rectangle r = {10,5};
//     area(r);
//     return 1;
// }

// pass by address

void changeLength(struct Rectangle *p, int l)
{
    p->length=l;
}

int changeMain()
{   
    struct Rectangle r = {10,5};
    changeLength(&r,20);
    return 1;
}


// you can send struct that has an arr by value
// but not an arr itself by value
// the reason why is because its too time consuming to duplicate arr
// each time but in a struct they are forced to 
struct Test
{
    int A[5];
    int n;
};

void struct2Parameter(struct Test t1)
{
    t1.A[0] = 10;
    t1.A[1] = 9;
}

int struct2Main()
{
    struct Test t={{2,3,4,5,6},5};
    struct2Parameter(t);

}

// Structures and Functions

struct Rect
{
    int length;
    int breadth;
};

void initialize(struct Rect * r, int l, int b)
{
    r->length=l;
    r->breadth=b;
}

int rectArea(struct Rect r)
{
    return r.length * r.breadth;
}

void changeRectLength(struct Rect * r, int l)
{
    r->length=l;
}

int main()
{
    struct Rect r;
    // &x is used to get the address of x so no need to create
    // a pointer variable
    initialize(&r, 10,5);
    rectArea(r);
    changeRectLength(&r,20);
}

// converted c to c++
/*
class Rect
{
    private:
        int length;
        int breadth;

    public:
        Rect(int l, int b)
        {
            length=l;
            breadth=b;
        }

        int rectArea()
        {
            return length * breadth;
        }

        void changeRectLength(int l)
        {
            length=l;
        }
}
int main()
{   
    Rect r;
    r.initialize(10,5);
    r.rectArea();
    r.changeRectLength(20);
}
*/

// class and constructor c++
/*
#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    public:
        // overloaded constructors
        Rectangle()
        // default constructor
        {
            length=l;
            breadth=b;
        }
        Rectangle(int l, int b);
        // facilitators
        int area();
        int perimeter();
        // accessor
        int getLength(){return length;};
        // mutator
        void setLength(int l){length=1;};
        // destructor
        ~Rectange();

}
// scope resolution operator :: used in the following purposes:
    1) To access a global variable when there is a local variable with same name
    2) To define a function outside a class.
    3) To access a class’s static variables.
    4) In case of multiple Inheritance:
    5) For namespace
    6) Refer to a class inside another class:

Rectangle::Rectangle(int l, int b)
{
    length = 1;
    breadth = b;
}

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::Perimeter()
{
    return 2*(length+breadth)
}

Rectangle::~Rectangle()
{
    delete length;
    delete breadth;
}

int main()
{
    Rectangle r(10,5);
    // >> << are extraction opertors - extract data for or from the input stream
    std::cout << r.area() <<std::endl;
    std::cout << r.perimeter()<<std::endl;
    r.setLength(20);
    std::cout << r.getLength()<<std::endl:
}

*/

// Template Class

// Generic using template
// template allows functions to use different data types
/*
    template<class T>
    class Arithmetic
    {
        private:
            T a;
            T b;
        public:
            Arithmetic(T a, T b);
            T add();
            T sub();
    };

    template<class T>
    Arithmetic<T>::Arithmetic(T a, T b)
    {
        this->a=a;
        this->b=b;
    }

    template<class T>
    T Arithmetic<T>::add()
    {
        T c;
        c=a+b;
        return c;
    }

    template<class T>
    T Arithmetic<T>::sub()
    {
        T c;
        c=a-b;
        return c;
    }

    int main()
    {
        // when using template classes must define type
        Arithmetic<int> ar(10,5);
        Arithmetic<float> ar1(1.5,1.2);
    }

*/