/*

Tracing Recusion

    fun(3)
     /\
    3   fun(2)
          /\
          2 fun(1)
              /\
              1 fun(0)
                  |
                  done

*/
void fun(int n)
{
    // this is the base case to continue recursion
    if(n>0){
        // this will be declared in the code segment
        // but it wont need to be copied like n would
        // be in the stack
        // static will be like a global variable memory wise
        static int x = 0;
        // calling time
        printf("%d", n);
        fun(n-1);
        // returning time
    }
}

void main_fun()
{
    int x = 3;
    fun(x);
}

/*
Types of recursion
1. Tail

void fun(int n)
{
    if(n>0){
        printf("%d", n);
        fun(n-1);
    }
}

All operations will be done at calling time

2. Head

void fun(int n)
{
    if(n>0){
        fun(n-1);
        printf("%d", n);
    }
}

All operations are done at returning time

3. Tree 

void fun(int n)
{
    if(n>0){
        printf("%d", n);
        fun(n-1);
        fun(n-1);
    }
}
Linear recursion is when a function only calls themselves once
Tree recursion is when function is called itself more than one time

4. Indirect 

void a(int n)
{
    if (n>0)
    {
        printf("%d", n);
        b(n-1);
    }
}
void b(int n)
{   
    if(n>1)
    {
        printf("%d", n);
        a(n/2);
    }

}

Two functions that keep calling eachother

5. Nested

int fun(int n)
{
    if(n>100)
    {
        return n-10;
    }
    else
    {
        return fun(fun(n+11))
    }
}

*/

// Sums of First N Natural Numbers

// sums formula is n*(n+1)/2

int sumsOfNRecursive(int n)
{
    if(n>0){
        return sumsOfNRecursive(n-1)+n;
    }
    else
    {
        return 0;
    }
}

int sumOfNIterative(int n)
{
    int i;
    int s = 0;
    for(i=1;i<=n;i++)
    {
        s=s+i;
    }
    return s;
}

// Factorial of a Number Recurrsion
// fact(n) = (n-1)*n

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
    
}

// Power using recursion
int pow(int m, int n)
{
    if(n==0){
        return 1;
    }
    else{
        return pow(m,n-1)*m;
    }
}

// more efficient pow using recursion
int fasterPow(int m, int n)
{
    if(n==0)
        return (1);
    if (n%2==0)
        return fasterPow(m*m, n/2);
    else 
        return m*fasterPow(m*m,(n-1)/2);  
}

// Taylor series
double e (int x, int n)
{
    static double p=1, f=1;
    double r;
    if (n==0)
        return (1);
    else 
    {
        r=e(x,n-1);
        p = p*x;
        f= f*n;
        return r+p/f;
    }
}

// Taking common calculations or factors can reduce
// the amount of operations there are

double fasterE(int x, int n)
{
    static double s;
    if(n==0)
        return s;
    s=1+x*s/n;
    return fasterE(x,n-1);
}

// Recursion with memoization

// fib without memoization

int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-2)+fib(n-1);
}

// diff between global variable and 
// static variable is that static is exclusive
// to that program
// global variables can be called with extern
// for arrays it must be a global variable

int F[10];

int mFib(int n)
{
    if (n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=mFib(n-2);
       if(F[n-1]==-1)
            F[n-1]=mFib(n-1);
        return F[n-1]+F[n-2];
    }
}

// nCr formula or combination formula
// n!/r!(n-r)! pascals triangle can be used for 
// ncr value

int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den=fact(r)*fact(n-r);
    return num/den;
}

int nCrRecursive(int n, int r)
{
    if(n==r||r==0)
        return 1;
    return nCrRecursive(n-1, n-r)+nCrRecursive(n-1,r);
}

// tower of hanoi
// returns steps to solve tower of hanoi
void TOH(int n, int a, int b, int c)
{
    if(n>0)
    {
        TOH(n-1, a,c,b);
        printf("(%d,%d)\n",a,c);
        TOH(n-1,b,a,c);
    }
}