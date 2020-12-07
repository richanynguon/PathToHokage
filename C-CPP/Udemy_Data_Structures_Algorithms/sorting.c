/*
Critera For Analysis

1. Number of comparisons
2. Number of Swaps
3. Adaptive - when a algo can recognize if already in order it takes another strat - so it takes less time 
4. Stable - can handle duplicates preserving order as is
5. Extra Memory

Comparison Based Sorts:

O(n^2)
Bubble Sort
Insertion Sort
Selection Sort

O(nlog(n))
Heap Sort
Merge Sort
Quick Sort
Tree Sort

O(n^3/2)
Shell Sort
Index Based Sorts:
O(n)
Count Sort
Bucket/Bin Sort
Radix Sort
Tim Sort
*/

/*
O(n^2)
Bubble Sort
Will iterative through the list and swap depending if the next
element is lower than the current. It will loop through until
no swaps were made

1. Number of comparisons
2. Number of Swaps
3. Adaptive
4. Stable
5. Extra Memory

Given n = 5: 8,5,7,3,2
No of passes: 4-(n-1) passes
No of comp: O(n^2)
max no. of swaps: O(n^2)
stable
space complexity:O(1)


Worst complexity: n^2
Average complexity: n^2
Best complexity: n
Space complexity: 1
Method: Exchanging
Stable: Yes
Class: Comparison sort
*/

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubble(int A[],int n)
{
    int i,j,flag=0;

    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }

}

/*
O(n^2)
Insertion Sort
Splits the array into two, one side sorted the other unsorted. for each new element it arrives to it places it in the sorted section in the correct order

Given n = 5: 8,5,7,3,2
No of passes: (n-1) passes
No of comp: O(n^2)
max no. of swaps: O(n^2)
stable
space complexity:O(1)


Diff between insertion sort and bubble sort
Bubble sort is good with linked list but not insertion sert
Bubble sort has k passes while insertion sort goes through one pass

Worst complexity: n^2
Average complexity: n^2
Best complexity: n
Space complexity: 1
Method: Insertion
Stable: Yes
Class: Comparison sort

*/

void Insertion(int A[],int n)
{
    int i,j,x;

    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

/*
O(n^2)
Selection Sort
It iterates through the array k amount of times and selects the smallest
element then swaps the current element

Given n = 5: 8,5,7,3,2
No of passes: (n-1) passes
No of comp: O(n^2)
max no. of swaps: O(n^2)
not stable
space complexity:O(1)

Worst complexity: n^2
Average complexity: n^2
Best complexity: n^2
Space complexity: 1
Method: Selection
Stable: No
Class: Comparison sort

*/

void SelectionSort(int A[],int n)
{
    int i,j,k;

    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i],&A[k]);
    }
}


/*
O(nlog(n))
Merge Sort
Break them to single elements and merge them in order

Inventor: John von Neumann
Worst complexity: n*log(n)
Average complexity: n*log(n)
Best complexity: n*log(n)
Space complexity: n
Method: Merging
Stable: Yes
*/

void Merge(int A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}
void MergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);

    }
}

void IMergeSort(int A[],int n)
{
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2; 
            merge(A,l,mid,h);
        }
        if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A, l, mid, n-1);
        }
    }
    if(p/2<n)
    {
        merge(A,0,p/2-1,n-1);
    }
} 

/*
O(nlog(n))
Quick Sort
Elements are in a sorted position if any element to the right is larger
and any element to the left is lesser

Worst complexity: n^2
Average complexity: n*log(n)
Best complexity: n*log(n)
Method: Partitioning
Stable: No
Class: Comparison sort

*/

int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;

    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j)swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l],&A[j]);
    return j;
}
void QuickSort(int A[],int l,int h)
{
    int j;

    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}


/*
O(n^3/2)
Shell Sort

Have two pointers and check if each element is sorted
if not then they swap the gap will be n/2
and they reduce gap size by two each time 
and continue swapping until sorted

Inventor: Donald Shell
Worst complexity: Depends on gap sequence
Average complexity: n*log(n)^2 or n^(3/2)
Best complexity: n
Method: Insertion
Stable: No
Class: Comparison sort
*/

void ShellSort(int A[],int n)
{
    int gap,i,j,temp;

    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;

        }
    }

}


/*
O(n)
Count Sort

Create 0-max value array
count each ele and enter # entries in the array

Worst complexity: n+r
Average complexity: n+r
Space complexity: n+r
Stable: Yes
Class: Non-comparison sort
Worst-case performance: where k is the range of the non-negative key values
Data structure: Array
*/
int INT32_MIN;

int findMax(int A[],int n)
{
    int max=INT32_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
        max=A[i];
    }
    return max;
}
void CountSort(int A[],int n)
{
    int i,j,max,*C;

    max=findMax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++)
    {
        C[i]=0;
    }
    for(i=0;i<n;i++)
    {
        C[A[i]]++;
    }

    i=0;j=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++]=j;
            C[j]--;
        }
        else
            j++;
    }
}


/*
O(n)
Bucket/Bin Sort

Bucket is like countin sort, but instead of counting its a linked list


Class: Sorting algorithm
Data structure: Array


*/

/*
#include <iostream>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}
 
// Linked List node
class Node{
public:
    int value;
    Node* next;
};
 
void Insert(Node** ptrBins, int idx){
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){ // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
void BinSort(int A[], int n){
    int max = Max(A, n);
 
    // Create bins array
    Node** bins = new Node* [max + 1];
 
    // Initialize bins array with nullptr
    for (int i=0; i<max+1; i++){
        bins[i] = nullptr;
    }
 
    // Update count array values based on A values
    for (int i=0; i<n; i++){
        Insert(bins, A[i]);
    }
 
    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max+1){
        while (bins[i] != nullptr){
            A[j++] = Delete(bins, i);
        }
        i++;
    }
 
    // Delete heap memory
    delete [] bins;
}
 
int main() {
 
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\tA");
    BinSort(A, n);
    Print(A, n, " Sorted A");
    cout << endl;
    return 0;
}

*/


/*
O(n)
Radix Sort

Sorting numbers into bins and then resorting based on first, second, n number place
repeat until sorted

Worst complexity: n*k/d
Average complexity: n*k/d
Space complexity: n+2^d
Stable: Yes
Class: Non-comparison sort
Worst-case performance: where w is the number of bits required to store each key
Data structure: Array
*/


/*

#include <iostream>
#include <cmath>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}
 
// Linked List node
class Node{
public:
    int value;
    Node* next;
};
 
int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}
 
void initializeBins(Node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = nullptr;
    }
}
 
void Insert(Node** ptrBins, int value, int idx){
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}
 
void RadixSort(int A[], int n){
    int max = Max(A, n);
    int nPass = countDigits(max);
 
    // Create bins array
    Node** bins = new Node* [10];
 
    // Initialize bins array with nullptr
    initializeBins(bins, 10);
 
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
 
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
 
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != nullptr){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }
 
    // Delete heap memory
    delete [] bins;
}
 


*/