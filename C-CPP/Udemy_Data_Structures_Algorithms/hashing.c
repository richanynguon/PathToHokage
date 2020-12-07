/*

Why hashing - optimize search process
Ideal Hashing - ideally would insertion, fetching, and deletion O(1)
where relations are 1 to 1
Modulus Hashfunction - will have collisions where its many to 1
Drawbacks
Solution

open hashing
    - Chaining
closed hashing - will only utilize give space, but will not increase
    - open addressing
        1. Linear Probing
        2. Quadratic probling
        3. Double hashing



Chaining
 Each bucket will have a head to a linked list
 Hasing is done based on loading factor, meaning at
 each location it cannot be more than amount of elements/size



Other notable hash functions
DJB2
SHA-256

with probing it just retries a placement formula until it finds
an empty slot to dump in 

so linear will increase bucket plus one
quadratic will increase bucket plus x**2
double hash will increase bucket plus Hash2 evaluation
*/
#define PRIME 7
#define SIZE 10
int hash(int key)
{
    return key%SIZE;
}

int PrimeHash(int key){
    return PRIME - (key % PRIME);
}
// linear probing
// with linear probing you keep going to the next slot to 
// insert or find the value - when retreival happens
// and u face an empty slot you stop
// loading factor // lambda should be <= 0.5
// deletion is not recommending in linear probing
// then it becomes unstable
// when GCD(x, tablesize) = 1 will able to generate a full cycle
// and will find an empty bucket to prevent infinite loop
int probe(int H[],int key)
{
    int index=hash(key);
    int i=0;
    // where i
    while(H[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}

/*
To prevent infinite loop you can take one of three popular approaches
1. let formula for key/position be  = x**2, keep table size a prime number > 3 and keep load factor <= 1/2
2. let x**2+x/2, keep table size power of two
3. let (-1**x)*x**2 keep table size prime N where N == 3 mod 4
*/
int QuadraticProbe(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    // where i^2
    while (H[(idx+i*i) % SIZE] != 0){
        i++;
    }
    return (idx + i*i) % SIZE;
}

// reduces linear probing
// so given delta where hash2(k) mod tablesize
// 1<=delta< tablesize and GCD(delta, tablesize)=1 - N will be a prime
int DoubleHash(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    // where hashing twice
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0){
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}

// search and insert will be different based on accessing 
// depending which method is used

void Insert(int H[],int key)
{
    int index=hash(key);

    if(H[index]!=0)
        index=probe(H,key);
    H[index]=key;
}

int Search(int H[],int key)
{
    int index=hash(key);
    int i=0;

    while(H[(index+i)%SIZE]!=key)
        i++;

    return (index+i)%SIZE;
}

/*

size of hashtable is a prime number when using modular hashing
midsquare: ex: lets say key =11, 11^2 = 121 take middle number -> 2 and thats is the key
folding: split digit into even part for ex:
123346 -> 12,33,46 and sum them to be a key -> 91 then 9+1 -> 10
*/