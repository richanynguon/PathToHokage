/*
1. What is a heap
    - Must be a binary tree, can come in max or min heap
    - Can be represented through an array
      - Node at index i
      - Left child at 2*i
      - Right child at 2*i+1
2. Insert in heap
    - Use the algorithms above to insert into 
    - Array must have contigent elements to be complete and a heap
    - When inserted bubble up or bubble down
3. Deleting from heap
4. Heap sort
5. Heapify
6. Priority Queues

*/

struct Heap
{
    int * storage;
    int maxLength;
    int size;
    int max;
    int min;
};

void create(struct Heap *h, int size, int max)
{
    h->maxLength = size*2;
    h->storage = (int *)malloc(h->maxLength*sizeof(int));
    if (max == 0)
        h->min = 1;
    else
        h->max =1;
};

void insert(struct Heap *h,  int max)
{
    int i = h->maxLength;
    int temp = h->storage[h->maxLength];
    if (max == 1)
        while (i > 0 && temp > h->storage[i % 2 == 0 ? (i/2)-1 : i/2]){
            h->storage[i] = h->storage[i % 2 == 0 ? (i/2)-1 : i/2];
            i = i % 2 == 0 ? (i/2)-1 : i/2;
        }
    else
        while (i > 0 && temp < h->storage[i % 2 == 0 ? (i/2)-1 : i/2]){
            h->storage[i] = h->storage[i % 2 == 0 ? (i/2)-1 : i/2];
            i = i % 2 == 0 ? (i/2)-1 : i/2;
        } 
    h->storage[i] = temp;
}

void delete(struct Heap *h, int n)
{
    int i, j, x, temp, val;
    val=h->storage[1];
    x=h->storage[n];
    h->storage[1]=h->storage[n];
    i=1; j=i*2;
    while(j<n-1)
    {
        if(j<n-1 && h->storage[j+1]>h->storage[j])
            j=j+1;
        if(h->storage[i]<h->storage[j])
        {
            temp=h->storage[i];
            h->storage[i]=h->storage[j];
            h->storage[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;  
    }
    return val;
}

/*

Heapify is the process of converting a binary tree. Will compare element to the children.
If its bigger or smaller shift

heap is helping to serve as a priority queue

*/