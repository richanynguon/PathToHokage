/*
Queues
Data:
1. Space for storing elements
2. Front for deletion
3. Rear for insertion
Operations:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. First
6. Last
*/

#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is Full");
    else
    {
        q->rear++;
        q->
        Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;

    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
 int i;

 for(i=q.front+1;i<=q.rear;i++)
    printf("%d ",q.Q[i]);
 printf("\n");
}

/*
CCP
#include <iostream>

using namespace std;
 
class Queue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
int Queue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 
void Queue::display() {
    for (int i=front+1; i<=rear; i++){
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q(sizeof(A)/sizeof(A[0]));
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
 
    // Underflow
    q.dequeue();
    
    return 0;
}
*/

struct CirQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct CirQueue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct CirQueue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct CirQueue *q)
{
    int x=-1;

    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct CirQueue q)
{
    int i=q.front+1;

    do
    {

        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);

    printf("\n");
}

/*
cpp
#include <iostream>

using namespace std;
 
class CircularQueue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size];
}
 
CircularQueue::~CircularQueue() {
    delete [] Q;
}
 
bool CircularQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}
 
void CircularQueue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
 
int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
 
void CircularQueue::display() {
    int i = front + 1;
    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}
 
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
 
    // Display
    cq.display();
    cout << endl;
 
    // Overflow
    cq.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
 
    // Underflow
    cq.dequeue();
 
    return 0;
}
*/

struct Node
{
    int data;
    struct Node *next;

}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }

}
int dequeue()
{
    int x=-1;
    struct Node* t;

    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node *p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

/*
CPP
#include <iostream>

using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Queue{
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};
 
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}
 
void Queue::enqueue(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Queue Overflow" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr){
            front = t;
            rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}
 
int Queue::dequeue() {
    int x = -1;
    Node* p;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
 
bool Queue::isEmpty() {
    if (front == nullptr){
        return true;
    }
    return false;
}
 
Queue::~Queue() {
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
 
void Queue::display() {
    Node* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    q.dequeue();
 
    return 0;
}
*/

/*
CPP
Dequeuing using arr
Can also have small variations like input restricted double ended queue
or output restricted
#include <iostream>

using namespace std;
 
class DEQueue{
private:
    int front;
    int rear;
    int size;
    int* Q;
 
public:
    DEQueue(int size);
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};
 
DEQueue::DEQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}
 
DEQueue::~DEQueue() {
    delete [] Q;
}
 
bool DEQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool DEQueue::isFull() {
    if (rear == size - 1){
        return true;
    }
    return false;
}
 
void DEQueue::enqueueFront(int x) {
    if (front == -1){
        cout << "DEQueue Overflow" << endl;
    } else {
        Q[front] = x;
        front--;
    }
}
 
void DEQueue::enqueueRear(int x) {
    if (isFull()){
        cout << "DEQueue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
int DEQueue::dequeueFront() {
    int x = -1;
    if (isEmpty()){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[front];
        front++;
    }
    return x;
}
 
int DEQueue::dequeueRear() {
    int x = -1;
    if (rear == -1){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}
 
void DEQueue::display() {
    for (int i=front+1; i<=rear; i++) {
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEQueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    cout << endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();
 
    return 0;
}
*/
/*
Priority Queues
1. Limited Set of priorities
Useful in operating systems
Uses multiple queues based on priorities
2. Element priority



*/
/*
CPP

Queue using 2 stacks
enqueue in stack one if stack two is empty
put elements in stack one and push into stack two
to pop out on stack two

#include <iostream>
#include <stack>

using namespace std;
 
class Queue{
private:
    stack<int> e_stk;
    stack<int> d_stk;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};
 
void Queue::enqueue(int x) {
    e_stk.push(x);
}
 
int Queue::dequeue() {
    int x = -1;
    if (d_stk.empty()){
        if (e_stk.empty()){
            cout << "Queue Underflow" << endl;
            return x;
        } else {
            while (!e_stk.empty()){
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    x = d_stk.top();
    d_stk.pop();
    return x;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    cout << "Enqueue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
    cout << endl;
 
    cout << "Dequeue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << q.dequeue() << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
 
    return 0;
}
*/