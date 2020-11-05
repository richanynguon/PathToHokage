/*
A scalar data structure is the most basic data type that holds only a single atomic value at a time. Using scalars, more complex data types can be constructed. The five scalar data types are Numeric, Character, Integer, Logical and Complex.
*/

/*
Array is a collection of similar data types
*/

int x = 10;
// declaration
int A[5];
// assign value
// A[2] = 15;
// declaration and initialization
int B[5]={2,4,6,8,10};
// intialize all mem slots with 0
int C[5]= {0};

// to make a more dynamic array
#include <stdio.h>
void biggerArray(){
    int *p, *q;
    int i;
    p = (int *)malloc(5*sizeof(int));
    p[0]=3;
    q = (int *)malloc(10*sizeof(int));
    for(i=0; i<5; i++)
        q[i]=p[i];
    free(p);
    p=q;
    q= NULL;
};
// 2D array

void twoDArray()
{
    int A[3][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    
    int *B[3];
    B[0]=(int*)malloc(4*sizeof(int));
    B[1]=(int*)malloc(4*sizeof(int));
    B[2]=(int*)malloc(4*sizeof(int));

    int **C;
    C=(int**)malloc(3*sizeof(int *));
    C[0]=(int**)malloc(4*sizeof(int));
    C[1]=(int**)malloc(4*sizeof(int));
    C[2]=(int**)malloc(4*sizeof(int));

};

/*
So compiler will give back a pointer to the first 
address of the start of the array then will increments by size of int bytes to get to the next ones

addr(A[i]) = baseAddress + index * size of data type (word size)

addr(A[i]) = L0 + i * w

A[m][n]

Row major formula
left to right

addr(A[i]) = baseAddress + (index*columns+element index) * size of data type (word size)
addr(A[i][j]) = L0+(i*n+j)*w

Column Major formula
right to left

addr(A[i]) = baseAddress + (index*rows+element index) * size of data type (word size)
addr(A[i][j]) = L0+(j*m+i)*w

Formulas for nD arrays

Type A[d1][d2][d3][d4]

Row major
addr(A[i1][i2][i3][i4])=L0+(i1*d2*d3*d4+i2*d3*d4+i3*d4+i4)*w
                        // Applying horners rule to reduce 
                        // amount of operations and taking out GCF
                        = L0+i4+d4*(i3+d3*(i2+i1+d2))*w                

Column Major
addr(A[i1][i2][i3][i4])=L0+(i4*d1*d2*d3+i3*d1*d2+i2*d1+i1)*w
                        L0+i1+d1*(i2+d2*(i3+d3+i4))*w
Forumla for 3d Array

int A[l][m][n];

row major
addr(A[i][j][k]) = L0+(i*m*n+j*n+k)*w

column major
addr(A[i][j][k]) = L0+(k*l*m+j*l+i)*w
*/

/*
Array as an Abstract Data Type

Data
----
1. Array Space
2. Size
3. Length(no. of elements)

Operations
----
1. Display
2. Add/Append
3. Insert
4. Delete 
5. Search
6. Get
7. Set
8. Max/Min
9. Reverse
10. Shift/Rotate

*/

#include <stdlib.h>

struct Array
{
    // to give fix initialize size you can do A[20]
    // then intializing is just struct Array arr={{1,2,3,4},20,5}
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    // dot notation is when accessing directly to arr
    // its best to pass in the arr when not modifying
    print("\nElements are \n");
    for(i=0; i<arr.length;i++)
        printf("%d", arr.A[i]);
}

// O(1)
void AddAppend(struct Array *arr, int x)
{
    // arrow notation is when access from a pointer
    // best to pass a pointer when modifying
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
    return x;
}

// O(n)
void Insert(struct Array *arr, int index, int x)
{   
    int i;
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }

}

// O(n)
int Delete(struct Array *arr, int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index; i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

//O(n)
// To improve linear search you can implement a transposition
// where you can swap it back one
// Or you can move to head

void swap(int *x, int*y)
{
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i; 
    // regular search
    for(i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
            return i;
    }
    // transposition
    // for(i=0; i<arr->length; i++)
    // {
    //     if(key==arr->A[i])
    //         swap(&arr->A[i], &arr->A[i-1]);
    //         return i;
    // }
    // move to head
    // for(i=0; i<arr->length; i++)
    // {
    //     if(key==arr->A[i])
    //         swap(&arr->A[i], &arr->A[0]);
    //         return i;
    // }
    return -1;
    
}

int BinarySearchIterative(struct Array *arr, int key)
{
    int l, mid, h;
    l=0;
    h=arr->length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr->A[mid])
            return mid;
        else if (key<arr->A[mid])
            h=mid-1;
        else
            l=mid+1;    
    }
    return -1;
}


//O(log(n))
int BinarySearchRecursive(int a[], int l, int h, int key)
{
    int mid;
    if (l<=h)
    {
        mid = (1+h)/2;
        if(key==a[mid])
            return mid;
        else if (key<a[mid])
            return BinarySearchRecursive(a,l,mid-1,key);
        else
            return BinarySearchRecursive(a,l,mid+1,key);
    }
}

int Get(struct Array *arr, int index)
{
    if(index>=0 && index<arr->length)
        return arr->A[index];
    return -1;
}

int Set(struct Array *arr, int index, int x)
{
    if(index>=0&&index<arr->length)
        arr->A[index] = x;
    return -1;
}

int Max(struct Array *arr)
{
    int max = arr->A[0];
    int i;
    for(i=1; i<arr->length; i++)
    {
        if(arr->A[i]>max)
            max=arr->A[i];
    }
    return max;
}

int Min(struct Array *arr)
{
    int min=arr->A[0];
    int i;
    for(i=1; i<arr->length;i++)
    {
        if(arr->A[i]<min)
            min=arr->A[i];
    }
    return min;
}

float Avg(struct Array *arr)
{
    return (float)Sum(arr)/arr->length;
}

int Sum(struct Array * arr)
{
    int s=0;
    int i;
    for(i=0; i<arr->length; i++)
        s+=arr->A[i];
}

int Reverse(struct Array *arr)
{
    int *B;
    int i, j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1, j=0; i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i>arr->length;i++)
        arr->A[i]=B[i];
}

int Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}
int isSorted(struct Array *arr){
    int i;
    for(i=0;i<arr->length-1;i++)
    {
        if(arr->A[i]>arr->A[i+1])
        return 0;
    }
    return 1;
}
void InsertSort(struct Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;

}

void Rearrange(struct Array *arr)
{
    int i,j; 
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[i]>=0)j++;
        if(i<j)swap(&arr->A[i],&arr->[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
             arr3->A[k++]=arr2->A[j++]; 
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i++];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j++]; 
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}


int arrayInitalizationAndManipulation()
{
    struct Array arr;
    int n, i;
    printf("Enter size of an array");
    // the ampersands give status to that value
    // scanf write the value to the given variable
    scanf("%d", &arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    printf("Enter number of numbers");
    scanf("%d", &n);

    printf("Enter all Elements\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr.A[i]);
    arr.length=n;
    Display(arr);
    AddAppend(&arr, 10);
    Insert(&arr,5,10);
    Display(arr);
    printf("%d\n", Delete(&arr,4));
    printf("%d\n", LinearSearch(&arr, 6));
}