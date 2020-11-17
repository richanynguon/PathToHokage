/*
Stack Last In First Out

Data:
1. Space for storing elements 
2. Top pointer

Operations:
1. Push
2. Pop
3. Peek
4. Stack top
5. isEmpty
6. isFull
*/

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack * st, int sz)
{
    st->size = sz;
    st->s = (int *)malloc(st->size*sizeof(int));
}

void push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
 
}
int pop(struct Stack *st)
{
    int x=-1;

    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x=st->s[st->top--];
    }
    return x;
}
int peek(struct Stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
        printf("Invalid Index \n");
    x=st.s[st.top-index+1];

    return x;
}
int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    return st.top==st.size-1;
}
int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}

/*
CPP
#include <iostream>
using namespace std;
 
class Stack{
private:
    int size;
    int top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();
};
 
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new int[size];
}
 
Stack::~Stack() {
    delete[] S;
}
 
void Stack::push(int x) {
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}
 
int Stack::pop() {
    int x = 1;
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}
 
int Stack::peek(int index) {
    int x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}
 
int Stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int Stack::isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
int Stack::stackTop() {
    if (isEmpty()){
        return -1;
    }
    return S[top];
}
 
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Stack stk(sizeof(A)/sizeof(A[0]));
 
    // Populate stack with array elements
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
    stk.push(11);
 
    cout << "Stack full: " << stk.isFull() << endl;
 
    // Display stack;
    cout << "Stack: " << flush;
    stk.display();
 
    // Peek
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;
 
    // Top element
    cout << "Top element: " << stk.stackTop() << endl;
 
    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();
 
    cout << "Stack empty: " << stk.isEmpty() << endl;
 
    return 0;
}
*/