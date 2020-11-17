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

#include <stdio.h>
#include <stdlib.h>

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

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void pushLLStack(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }

}

int popLLStack()
{
    struct Node *t;
    int x=-1;

    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void DisplayLLStack()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

/*
cpp
#include <iostream>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};
 
Stack::Stack() {
    top = nullptr;
}
 
Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}
 
void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
 
int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}
 
int Stack::isEmpty() {
    return top ? 0 : 1;
}
 
int Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}
 
int Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;
 
        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }
 
        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Stack stk;
 
    // Populate stack
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
 
    cout << "Stack peek at 3rd: " << stk.peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.peek(10) << endl;
    cout << "Stack top: " << stk.stackTop() << endl;
    cout << "Stack full: " << stk.isFull() << endl;
    cout << "Stack empty: " << stk.isEmpty() << endl;
 
    // Pop out elements from stack
    cout << "Popped: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
 
    // Underflow
    cout << stk.pop() << endl;
 
    return 0;
}
*/

int isBalanced(char *exp)
{
    int i;

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            pushLLStack(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL)
                return 0;
            popLLStack();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

/*
cpp
#include <iostream>
#include<cstring>
#include <stack>
#include <map>

using namespace std;
 
int isBalanced(char* exp){
 
    // Create map
    map<char, char> mapping;
    mapping['}'] = '{';
    mapping[')'] = '(';
    mapping[']'] = '[';
 
    // Create map iterator
    map<char, char>::iterator itr;
 
    // Create stack
    stack<char> stk;
 
    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            stk.push(exp[i]);
        } else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if (stk.empty()){
                return false;
            } else {
                char temp = stk.top();
                itr = mapping.find(exp[i]);
                if (temp == itr->second){  // itr->first is key, itr->second is value
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return stk.empty() ? true : false;
}
 
int main() {
 
    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;
 
    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl;
 
    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;
 
    return 0;
}
*/

/*
Infix to Postfix Conversion

1. What is postfix
2. Why postfix
3. Precedence
4. Manual Conversion


Infix: a+b
Prefix: +ab
Postfix: ab+

infix
a+b*c

prefix
+a*bc

postfix
abc*+

infix
a+b+c*d

prefix
++ab*cd

postfix
ab+cd*+


*+ab-cd
ab+cd-*

1. Associativity
2. Unary Operators

Sym |Pre|Assoc
+,- | 1 | L-R
*,/ | 2 | L-R 
^   | 3 | R-L
∪,∩,| 4 | R-L (also can be - + *)
()  | 5 | L-R



*/


#include<strings.h>

int pre(char x)
{
 if(x=='+' || x=='-')
 return 1;
 else if(x=='*' || x=='/')
 return 2;
 return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;

}

char * InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
                pushLLStack(infix[i++]);
            else
            {
                postfix[j++]=popLLStack();
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=popLLStack();
    postfix[j]='\0';
    return postfix;
}


char * InToPost2(char *infix)
{
    int i=0,j=0;
    char *postfix;
    long len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
                pushLLStack(infix[i++]);
            else
            {
                postfix[j++]=popLLStack();
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=popLLStack();
    postfix[j]='\0';
    return postfix;
}

int Eval(char *postfix)
{
    int i=0;
    int x1,x2,r=0 ;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            pushLLStack(postfix[i]-'0');
        }
        else
        {
            x2=popLLStack();
            x1=popLLStack();
            switch(postfix[i])
            {
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            pushLLStack(r);
        }
    }
    return top->data;
}

/*
OSP Out Stack Presendence
ISP Inside Stack Presendence
 
Check the OSP of each symbol to push in the stack
Check the ISP to pop out of the stack
If they are operands then send
Sym|OSP|ISP
-----------
+,-|1  |2
*,/|3  |4
^  |6  |5
(  |7  |0
)  |0  |?

*/