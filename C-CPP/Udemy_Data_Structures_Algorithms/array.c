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
        if(i<j)swap(&arr->A[i],&arr->A[j]);
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
// Merges set in order
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}
// common items
struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}
// items that are different
struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];

    arr3->length=k;
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

int menuDriver()
{
    struct Array arr1;
    int ch;
    int x,index;

    printf("Enter Size of Array");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter you choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter an element and index");
                scanf("%d%d",&x,&index);
                Insert(&arr1,index,x);
                break;
            case 2: printf("Enter index ");
                scanf("%d",&index);
                x=Delete(&arr1,index);
                printf("Deleted Element is %d\n",x);
                break;
            case 3:printf("Enter element to search ");
                scanf("%d",&x);
                index=LinearSearch(&arr1,x);
                printf("Element index %d",index);
                break;
            case 4:printf("Sum is %d\n",Sum(&arr1));
                break;
            case 5:Display(arr1);
        }
    }while(ch<6);
    return 0;
}

/*
CPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<class T>

class Array
{
private:
    T *A;
    int size;
    int length;
    void swap(int *x, int *y);
public:
    Array()
    {
        size=10;
        legnth=0;
        A=new T[size];
    }
    Array(int sz)
    {
        size=sz;
        legnth=0;
        A=new T[size];
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, T x);
    T Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, T x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);

};

void Array::Display(){
    int i;
    for(i=0; i<length;i++)
        cout<<A[i]<< " ";
    cout<<endl;
}

void Array::AddAppend(int x)
{
    if(length<size)
        A[length++]=x;
    return x;
}

template<class T>
void Array<T>::Insert(int index, T x)
{   
    int i;
    if(index>=0 && index <=length)
    {
        for(i=length; i>index; i--)
            A[i]=A[i-1];
        A[index]=x;
        length++;
    }

}
template<class T>
T Array<T>::Delete(int index)
{
    T x=0;
    int i;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index; i<length-1;i++)
            A[i]=A[i+1];
        length--;
        return x;
    }
    return 0;
}


void Array::swap(int *x, int*y)
{
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

int Array::LinearSearch(int key)
{
    int i; 
    for(i=0; i<length; i++)
    {
        if(key==A[i])
            swap(&A[i], &A[0]);
            return i;
    }
    return -1;
    
}

int Array::BinarySearchIterative(int key)
{
    int l, mid, h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid])
            return mid;
        else if (key<A[mid])
            h=mid-1;
        else
            l=mid+1;    
    }
    return -1;
}


int Array::Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

int Array::Set(int index, int x)
{
    if(index>=0&&index<length)
        A[index] = x;
    return -1;
}

int Array::Max()
{
    int max = A[0];
    int i;
    for(i=1; i<length; i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

int Array::Min()
{
    int min=A[0];
    int i;
    for(i=1; i<length;i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

float Array::Avg()
{
    return (float)Sum(arr)/length;
}

int Array::Sum()
{
    int s=0;
    int i;
    for(i=0; i<length; i++)
        s+=A[i];
}

int Array::Reverse()
{
    int *B;
    int i, j;
    B=(int *)malloc(length*sizeof(int));
    for(i=length-1, j=0; i>=0;i--,j++)
        B[j]=A[i];
    for(i=0;i>length;i++)
        A[i]=B[i];
}

int Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    }
}
int Array::isSorted(){
    int i;
    for(i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
        return 0;
    }
    return 1;
}
void Array::InsertSort(int x)
{
    int i=length-1;
    if(length==size)
        return;
    while(i>=0 && A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;

}

void Array::Rearrange()
{
    int i,j; 
    i=0;
    j=length-1;
    while(i<j)
    {
        while(A[i]<0)i++;
        while(A[i]>=0)j++;
        if(i<j)swap(&A[i],&[j]);
    }
}

Array* Array::Merge(Array arr2)
{
    int i, j, k;
    i=j=k=0;
    Array *arr3 = new Array(length+arr2.length)
    while(i<length && j<arr2.length)
    {
        if (A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else
             arr3->A[k++]=arr2.A[j++]; 
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i++];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j++]; 
    arr3->length=length+arr2.length;
    arr3->size=10;

    return arr3;
}

Array* Array::Union(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=new Array(length)

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i])
            arr3->A[k++]=arr2.A[j++];
        else
        {
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

Array* Array::Intersection(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=new Array(length)

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            i++;
        else if(arr2.A[j]<A[i])
            j++;
        else if(A[i]==arr2.A[j])
        {
            arr3->A[k++]=A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

Array* Array::Difference(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=new Array(length)

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

Multiple insertion operations (<<) may be chained in a single statement:
cout << "This " << " is a " << "single C++ statement";
Alternatively, the endl manipulator can also be used to break lines. For example:

1 cout << "First sentence." << endl;
2 cout << "Second sentence." << endl;




int menuDriver()
{
    Array *arr1;
    int ch;
    int x,index;

    cout<< "Enter Size of Array" << endl;
    int sz;
    cin >> sz;
    arr1=new Array(sz)

    do
    {
        cout << "\n\nMenu\n" << endl;
        cout << "1. Insert\n" << endl;
        cout << "2. Delete\n" << endl;
        cout << "3. Search\n" << endl;
        cout << "4. Sum\n" << endl;
        cout << "5. Display\n" << endl;
        cout << "6.Exit\n" << endl;

        cout << "enter you choice " << endl;
        int ch;
        cin >> ch;

        switch(ch)
        {
            case 1: cout << "Enter an element and index" << endl;
                int x, index;
                cin >> x;
                cin >> index;
                arr1.Insert(index,x);
                break;
            case 2: cout << "Enter index " << endl;
                int index;
                cin >> index;
                x=arr1.Delete(index);
                cout << "Deleted Element is" << x << endl;
                break;
            case 3:cout << "Enter element to search " << endl;
                int x;
                cin >> x;
                index=arr1.LinearSearch(x);
                cout << "Element index" << index << endl;
                break;
            case 4:cout << "Sum is %d\n",Sum());
                break;
            case 5:arr1.Display();
        }
    }while(ch<6);
    return 0;
}

*/

// Finding Single Missing Element in Arr

// Using sums formula n*(n+1)/2
int missingElementSums(int * arr, int size)
{
    int i, sum=0, n=*(arr+size-1), s;
    for(i=0; i<size; i++)
        // deferences the array and calls the address
        sum = sum+*(arr+i);
    s = n*(n+1)/2;
    return s-sum;

}

int missingElementBrute(int * arr, int size)
{
    int l=*(arr+1),h=*(arr+size-1), diff=l-0,i;
    for(i=0; i<size; i++)
        if(*(arr+i)-i!=diff)
        {
            printf("Missing Element %d \n", i+diff);
            break;
        }


}

// Finding Multiple Missing Elements
int * missingElements(int * arr, int size)
{
    int l=*(arr+1),h=*(arr+size-1), diff=l-0,i;
    for(i=0; i<size; i++)
    {    
        if(*(arr+i)-i!=diff)
        {
            while(diff<*(arr+i)-i)
            {
                printf("%d\n", i+diff);
                diff++;                
            }
        }
    }
}

// using hashing
int * missingElements(int * arr, int size)
{
    int h=*(arr+size-1), i;
    // hashtable or bitset
    int hashtable[h];
    // this makes it so it creates 0 in all the entries
    memset(arr, 0, sizeof(int)*h);
    for(i=0; i<size; i++)
        hashtable[*(arr+i)]++;
    for(i=0; i<h;i++)
        if(hashtable[i]==0) printf("Missing element %d \n", i);
}


// Find Duplicates in Sorted Array
int * duplicatesSorted(int * arr, int size)
{
    int i;
    for(i=0; i<size-1; i++)
    {
        if(*(arr+i)==*(arr+i+1))
        {
            int j=i+1;
            while(*(arr+j)==*(arr+i)) j++;
            printf("%d is appearing %d times", *(arr+i),j-i);
            i=j-i;
        }
    }
}


// Find duplicated in unsorted array using hashing
int * duplicates(int * arr, int size)
{
    int h=*(arr+size-1), i;
    int hashtable[h];
    memset(arr, 0, sizeof(int)*h);
    for(i=0; i<size; i++)
        hashtable[*(arr+i)]++;
    for(i=0; i<h;i++)
        if(hashtable[i]>1) printf("%d appears %d times\n", i, hashtable[i]); 
}
// Finding pair of elements with sum k
int * pairSumK(int * arr, int size, int sum)
{
    int i;
    int hashtable[size];
    for(i=0; i<size; i++)
    {
        if(hashtable[sum-*(arr-i)!=0])
        {
            printf("%d+%d=%d",*(arr-i),sum-*(arr-i), sum);
        }
        hashtable[*(arr-i)]++;
    }
}

// finding pair of elements with sum k in sorted array
int * pairSumKSorted(int * arr, int size, int sum)
{
    int i=0, j=sum-1;
    while(i<j)
    {
        if(*(arr-i)+*(arr-j)==sum)
            printf("%d+%d=%d", *(arr-i), *(arr-j), sum);
        else if (*(arr-i)+*(arr-j)<sum)
            i++;
        else
            j--;
        
    }
}

// finding max and min in a single scan
int MaxOneGo(int * arr, int size)
{
    int i, max=*(arr+1);
    for(i=0; i<size; i++)
        if(*(arr+i)>max)
            max =*(arr+i);
    return max;
}

int MinOneGo(int * arr, int size)
{
    int i, min=*(arr+1);
    for(i=0; i<size; i++)
        if(*(arr+i)<min)
            min =*(arr+i);
    return min;
}