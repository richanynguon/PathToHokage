/*
Terminology
1. Root
2. Parent
3. Children
4. Siblings
5. Decendents
6. Ancestors
7. Degree of nodes
8. Internal nodes external nodes, leaf nodes, terminal nodes
9. Levels - start from 1
10. Height - Count edges start from 0
11. Forest - collection of trees

2 Types of nodes 
Labelled node
Unlabelled node

Unlabelled
Number of Binary Tree structure combination using num of nodes
Catalan Number 
t(n) = ²ⁿCₙ/n+1
max height = 2ⁿ⁻¹

recursive formula
t(n)=ⁿΣᵢ₌₁ T(i-1)*T(n-i)

Labelled
t(n) = ²ⁿCₙ/n+1 * n!

Given height
min # nodes: n = h+1
max # nodes: n = 2⁽ʰ⁺¹⁾-1

Given nodes
min height: h = log₂(n-1)-1
max height: h = n+1


Relationships between leaf nodes and non leaf nodes
leaves external -> none leaves internal
deg(0)=deg(2)+1


strict binary tree
1. Stict/proper/complete
Parent can only have o or 2 children
2. height v nodes
min # nodes: n = 2h+1
max # nodes: n = 2⁽ʰ⁺¹⁾-1
min height: h = log₂(n-1)-1
max height: h = n+1/2
3. internal & external nodes
external nodes = internal nodes + 1

n-ary trees
1. What are n-ary tree
Each parent can have a range of 0-n of children
2. Strict n-ary tree
Each parent must have n children
3. height v nodes for stric n-ary tree
m being n in n-ary
min nodes: n = mh+1
max nodes: n = (m⁽h⁺¹⁾-1)/m-1
min height: h = logₘ(n(m-1)+1)-1
max height: h = n-1/m
4. internal & external nodes
external nodes = (m-1)*internal nodes +1


Binary Tree Representation
1. Array Rep
store nodes in an array in this order 
node - i, left child - 2i, right child 2i+1
parent - i//2

2. Linked Rep
*/

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

/*
Full Vs Complete Binary Tree

Full Binary Tree has max nodes
and you can store it an array

Complete binary
When rep in array there should not be any blank spaces
It will be full from 0 to h-1, the most right child will be missing

Strict vs Complete Binary Tree

Alternative names
Strict -> complete
complete -> almost complete

Binary Tree Traversals
1. Preorder: n,l,r
2. Inorder: l,n,r
3. Post order: l,r,n
4. Level Order: level by level


Binary Tree Using queues
*/


#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct
    Node *));
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;

    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

struct Node *root=NULL;
void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Eneter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("eneter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct
            Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("eneter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct
            Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
// can also make it iteratively with a stack
void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q,100);

    printf("%d ",root->data);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
    return 0;
}
int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;

} 
/*
CPP
generating tree from preorder
using namespace std;
class Tree
{
 Node *root;

public:
    Tree(){root=NULL;}
    void CreateTree();
    void Preorder(){Preorder(root);}
    void Preorder(Node *p);
    void Postorder(){Postorder(root);}
    void Postorder(Node *p);
    void Inorder(){Inorder(root);}
    void Inorder(Node *p);
    void Levelorder(){Levelorder(root);}
    void Levelorder(Node *p);
    int Height(){return Height(root);}
    int Height(Node *root);
};
void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    printf("Eneter root value ");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("eneter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("eneter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void Tree::Levelorder(struct Node *root)
{
    Queue q(100);

    printf("%d ",root->data);
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}
int Tree::Height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;

}

*/

/*
Binary Search Trees

A binary tree where larger eles are on the right
and lower ele are on the left
Search time depends on the height
No duplicates
Inorder gives sorted of a BST


*/

/*
CPP
#include <iostream>
#include <stack>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iInsert(int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
    void createFromPreorder(int pre[], int n);
};
 
void BST::iInsert(int key) {
 
    Node* t = root;
    Node* p;
    Node* r;
 
    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
 
    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
 
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
 
}
 
void BST::Inorder(Node* p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;
}
 
Node* BST::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }
 
    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
    return p;  // key == p->data?
}
 
Node* BST::rSearch(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }
 
    if (key == p->data){
        return p;
    } else if (key < p->data){
        return rSearch(p->lchild, key);
    } else {
        return rSearch(p->rchild, key);
    }
}
 
Node* BST::Delete(Node *p, int key) {
    Node* q;
 
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
 
int BST::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
 
Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
 
Node* BST::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}
 
void BST::createFromPreorder(int *pre, int n) {
 
    // Create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;
 
    // Iterative steps
    Node* t;
    Node* p = root;
    stack<Node*> stk;
 
    while (i < n){
        // Left child case
        if (pre[i] < p->data){
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        } else {
            // Right child cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}
 
 
int main() {
 
    BST bst;
 
    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;
 
    // Iterative search
    Node* temp = bst.iSearch(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    // Recursive insert
    bst.rInsert(bst.getRoot(), 50);
    bst.rInsert(bst.getRoot(), 70);
    bst.rInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    cout << "\n" << endl;
 
    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(5);
    bs.iInsert(2);
    bs.iInsert(8);
    bs.iInsert(7);
    bs.iInsert(9);
    bs.iInsert(1);
 
    temp = bs.InPre(bs.getRoot());
    cout << "InPre: " << temp->data << endl;
 
    temp = bs.InSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;
 
    bs.Inorder(bs.getRoot());
    cout << endl;
 
    // Delete
    bs.Delete(bs.getRoot(), 5);
    bs.Inorder(bs.getRoot());
    cout << endl;
 
    // BST from Preorder traversal
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;
 
    return 0;
}
*/

/*
AVL Trees
Adelson-Velskii and Landis

balance factor = height of left subtree - height of right subtree

bf=hl-hr = {-1,0,1}

bf = | h1-hr | <=1

if bf = | h1-hr | > 1 = imbalanced

to balanced unbalanced trees you can perform one or double rotations



*/


struct AVLNode
{
    struct AVLNode *lchild;
    int data;
    int height;
    struct AVLNode *rchild;
}*root=NULL;

int NodeHeight(struct AVLNode *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl>hr ? hl+1 : hr+1;
}

int BalanceFactor(struct AVLNode *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl-hr;
}

struct AVLNode * LLRotation(struct AVLNode *p)
{
    struct AVLNode *pl=p->lchild;
    struct AVLNode *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
        root=pl;

    return pl;
}

struct AVLNode * LRRoation(struct AVLNode *p)
{

    struct AVLNode *pl=p->lchild;
    struct AVLNode *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(root==p)
        root=plr;
    return plr;

}

struct AVLNode * RRRotation(struct AVLNode *p)
{
    struct AVLNode* pr = p->rchild;
    struct AVLNode* prl = pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;
 
    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
 
    // Update root
    if (root == p)
        root = pr;
    return pr;
}

struct AVLNode * RLRoation(struct AVLNode *p)
{

    struct AVLNode* pr = p->rchild;
    struct AVLNode* prl = pr->lchild;
 
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;
 
    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
 
    // Update root
    if (root == p)
        root = prl;
    return prl;

}

struct AVLNode *RAVLInsert(struct AVLNode *p, int key)
{
    struct AVLNode *t=NULL;
    if(p==NULL)
    {
        t=(struct AVLNode *)malloc(sizeof(struct AVLNode));
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
        p->lchild=RAVLInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild=RAVLInsert(p->rchild, key);

    p->height = NodeHeight(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    return p;
}

struct AVLNode * InPre(struct AVLNode *p)
{
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct AVLNode * InSucc(struct AVLNode *p)
{
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}


void Inorder(struct AVLNode *p) {
    if (p){
        Inorder(p->lchild);
        printf("%d" ,p->data);
        Inorder(p->rchild);
    }
}
 
struct AVLNode * Delete(struct AVLNode *p, int key) {
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL){
        if (p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        struct AVLNode * q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
 
    // Update height
    p->height = NodeHeight(p);
 
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
    return p;
}

/*
height analysis of avl tree

given height
min nodes: n(h) = 0, 1 , N(h-2) + N(h-1) + 1 
max # nodes: n = 2⁽ʰ⁾-1

given nodes:

min height: h = log₂(n+1)
max height: opposite n(h) = 0, 1 , N(h-2) + N(h-1) + 1 

max height: 1.44 logn
"Since this is a modification of the Fibonacci sequence, you might want to look at Binet's formula that refers to the Golden ratio. 
https://www.ics.uci.edu/~pattis/ICS-23/lectures/notes/AVL.txt"
*/

/*
2-3 Trees

What are 2-3 Trees
- Multiway search trees
- Up to 3 degrees
- B-trees: balancing trees grows upwards. If there is no space to store a key it will expand and the middle value will be the parent node if there was a parent node with a space u can shift above if not make a new one, if there needs to be a shift it can be done
- All leaf nodes are at the same level
- Every node must have (n/2)=(3/2)= min 2 children

- With one key its a regular binary tree but with two keys it can have three children

Insert/Create

20,30,40,50,60,10,15,70,80

(20,30)

|20|30|

(40)

    |30| |
    /   \
|20| |  |40| |

(50)

    |30| |
    /   \
|20| |  |40|50|

(60)
    |30|50|
    /   \
|20| |  |40|60|

(10)

    |30|50|
    /   \
|10|20|  |40|60|

(15)

    |30|50|
    /   \
|10|20|  |40|60|

split where its supposed to go
and split the parent as well so since 30 is the middle value
it will be the upper most parent

        |30| |
        /   \
    |15| |  |50| |
    /  \      /   \
|10| | |20| |40| | |60| | 

(70,80,90)

        |30| |
        /   \
    |15| |  |50| |
    /  \      /   \
|10| | |20| |40| | |60|70| 

        |30| |
        /   \
    |15| |  | 50  |     70|
    /  \      /      /      \
|10| | |20| |40| | |60| | |80| |

        |30| |
        /   \
    |15| |  | 50  |     70|
    /  \      /      /      \
|10| | |20| |40| | |60| | |80|90|

Deletion

Simple delete

(90)
        |30| |
        /   \
    |15| |  | 50  |     70|
    /  \      /      /      \
|10| | |20| |40| | |60| | |80| |


Delete and merge

(80)
merge right
        |30| |
        /   \
    |15| |  | 50  |    |
    /  \      /      \      
|10| | |20| |40| | |60| 70| 

or
merge left
        |30| |
        /   \
    |15| |  | 70  |    |
    /  \      /      \      
|10| | |20| |40|50| |80| | 

Borrow
(10)

    |20| |
    /     \
|10| |  |30|40|

    |30| |
    /     \
|20| |  |40| |

Given height
min # nodes: n = 2⁽ʰ⁺¹⁾-1
max # nodes: n = 3⁽ʰ⁺¹⁾-1/3-1

give nodes 
min height: h= log₃(n(3-1)+1)-1
max height: h = log₂(n+1)

b-tree
b+tree 

are used in database management system


2-3-4 trees
B-tree of degree 4
every node must have (4/2)=2 children
min 2 children max of 4 children
all leaf at same level


insert 
(10,20,30)
|10|20|30|

(40)
one key one side 
two keys the other side

|20| | |
    /   \
|10| | | |30|40| |

(50)
|20| | |
    /   \
|10| | | |30|40|50|

(60)
push first middle up
one key one side 
two keys the other side

    |20|40| |
    /   |     \
|10||| |30|||  |50|60||

(70,80)
    |20|40|60|     - |70|80||
    /   |  \
|10||| |30||||50|||

(90, 100)
    |20|40|60|     - |70|80|90|
    /   |  \
|10||| |30||||50|||


            |20|40|60| <80
|10||| |30||| |50||| |70||| |90|100||

                |40|||
            |20||| |60|80||
|10||| |30||| |50||| |70||| |90|100||


deletion
go between borrowing and merging
(70)
borrow

                |40|||
            |20||| |60|90||
|10||| |30||| |50||| |80||| |100|||

(30)
        |60|||
    |40||| |90|||
|10|20|| |50||| |80||| |100|||

(80)
        
    |40|60|| 
|10|20|| |50||| |90|100|| 
*/

/*
Red Black Tree
1. It s aheight balanced binary tree, similar to 2-3-4 tree
2. Every node is either red or black
3. Root of the tree is black
4. Null is also black
5. Number of blacks on paths from root to leaf are same
6. No 2 consecutive red, parent and children of red are black
7. New inserted node is red
8. Hieght in log(n) <= h <= 2log(n)



Recoloring if uncle is red

Grandparent|B
    /    \
Uncle|R   Parent|R
    / \       / \
  n|b n|b   n|b  Child|R

If find RR and Uncle is red
Recolor to this pattern

Grandparent|R
    /    \
Uncle|B   Parent|B
            \
            Child|R

If GP is root it must turn black

Grandparent|B
    /    \
Uncle|B   Parent|B
            \
            Child|R

If uncle is black must perform one of the two rotations

LL/RR Zig zig, 

Grandparent|B
    /    \
  n|b   Parent|R
            / \
           n|b  Child|R

 Parent|b
    / \
GP|R  Child|R

LR/RL zig zag rotation

Grandparent|B
    /    \
  n|b   Parent|R
            /   \
        child|r  n|b

 Child|b
    / \
GP|R  P|R

remember AVL rotation rules

2-3-4 Trees v Red Black Trees

in the 234 tree, if a node has more than one key 
the key after the first will be red key

*/