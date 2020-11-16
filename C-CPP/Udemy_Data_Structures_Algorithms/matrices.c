/*
Special Matrices

1. Diagonal 
2. Lower Triangular
3. Upper Triangular
4. Symetric
5. Tridiagonal
6. Band
7. Toeplitz
8. Sparse
*/

/**/

/*
Diagonal
m[i][j] = 0 if i!=j

1  0  0  0  0
0  2  0  0  0
0  0  3  0  0
0  0  0  4  0
0  0  0  0  5

A[5]={1,2,3,4,5}
*/
struct Matrix
{
    int A[10];
    int n;
};


void diagSet(struct Matrix *m, int i, int j, int x)
{
    // where matrix[i][j]
    if(i==j)
        m->A[i-1]=x;

}
int diagGet(struct Matrix *m, int i, int j)
{
    if(i==j) return m->A[i-1];
    else return 0;
}

/*
CPP version

class Diagonal
{
private:
    int n;
    int *A;
public:
    Diagonal(int n)
    {
        this->n=n;
        A=new int[n]
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Diagonal();
}

void Diagonal::diagSet(int i, int j, int x)
{
    // where matrix[i][j]
    if(i==j)
        A[i-1]=x;

}
int Diagonal::diagGet(int i, int j)
{
    if(i==j) return A[i-1];
    else return 0;
}

*/

/*
Lower Triangular
m[i][j]=0 if i<j

1  0  0  0  0
1  1  0  0  0
1  1  1  0  0
1  1  1  1  0
1  1  1  1  1

row major formula
Index(A[i][j])=(i(i-1)/2)+j-1)

column major formula
index(A[i][j])= (n(j-1)-(j-2)(j-1)2)+i-j

*/

struct LTMatrix
{
    int *A;
    int n;
};

void LTSet(struct LTMatrix *m, int i , int j , int x)
{
    if(i>=j)
        m->A[i*(i-1)/2+j-1]=x;
    
}
int LTGet(struct LTMatrix * m, int i , int j)
{
    if(i>=j)
        return m->A[i*(i-1)/2+j-1];
    else
        return 0;
}


/*
Upper Triangular
m[i][j]=0 if i>j

1  1  1  1  1
0  1  1  1  1
0  0  1  1  1
0  0  0  1  1
0  0  0  0  1

row major formula
Index(A[i][j])=((i-1)*n-(i-2)(i-1)/2)+j-1)

column major formula
index(A[i][j])= (j(j-1)/2)+i-1

*/

/*
Symmetric
if m[i][j]=m[j][i] == true

2  2  2  2  2
2  3  3  3  3
2  3  4  4  4
2  3  4  5  5
2  3  4  5  6
*/

/*
Tridiagonal
m[i][j]!=0 if |i-j|<=1
amount of elements that are none zero = 3n-2

formula cases
        A[i][j]=
i-j=1           i-1
i-j=0           n-1+i-1
i-j=-1          2n-1+i-1

1  1  0  0  0
1  1  1  0  0
0  1  1  1  0
0  0  1  1  1
0  0  0  1  1
*/

/*
square Band
same amounts of diagonal on each side
1  1  1  1  1  0  0
1  1  1  1  1  1  0
1  1  1  1  1  1  1
1  1  1  1  1  1  1
1  1  1  1  1  1  1
0  1  1  1  1  1  1
0  0  1  1  1  1  1
*/

/*
Toeplitz

elements in a diagonal are the same
you only need to store first row and column in an array

index(A[i][j])
i<=j: j-1
i>j: n+i-j-1

2  3  4  5  6
7  2  3  4  5
8  7  2  3  4
9  8  7  2  3
10 9  8  7  2
*/

/*
Sparse matrix
more 0 elements than non0 elements
 _1__2__3__4__5__6__7_
1|1  1  3  0  1  0  0
2|0  0  0  0  1  0  0
3|1  0  1  0  0  0  1
4|0  0  0  0  1  1  0
5|1  1  0  1  0  0  0
6|0  0  1  0  1  0  1
7|0  0  0  0  0  0  0

You can represent sparse matrix in two ways
1. coordinate list / 3 column representation

__row___|__col___|__el___
0|  5       6       16 non0 el
1|    1       1       1
2|    1       2       1
3|    1       3       3
    ...     ...     ...

16 el * 3 arr * 2 bytes
2. compressed sparse row

List of non0 elements in order
A[1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1]

counting elements in each row
IA[0,4,5,8,10,13,16,16]

specifying where a[i] element in which column
JA[1,2,3,5,5,1,3,7,5,6,1,2,4,3,5,7]

16 el *2 + 7rows*2bytes

Adding sparse matrices

Make 3 column rep for each matrices
create new 3 col rep with size a-el+b-el
fill in each if they match then add el value

*/

#include <stdio.h>
#include<stdlib.h>
struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
    int i;

    printf("Eneter Dimensions");
    scanf("%d%d",&s->m,&s->n);
    printf("Number of non-zero");
    scanf("%d",&s->num);

    s->ele=(struct Element *)malloc(s->num*sizeof(struct
    Element));
    printf("Eneter non-zero Elements");
    for(i=0;i<s->num;i++)
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);

}
void display(struct Sparse s)
{
    int i,j,k=0;

    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
        if(i==s.ele[k].i && j==s.ele[k].j)
        printf("%d ",s.ele[k++].x);
        else
        printf("0 ");
        }
        printf("\n");
        }
    }
struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;

    if(s1->n != s2->n && s1->m != s2->m)
        return NULL;
    sum=(struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));
    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i<s2->ele[j].i)
            sum->ele[k++]=s1->ele[i++];
        else if(s1->ele[i].i>s2->ele[j].i)
            sum->ele[k++]=s2->ele[j++];
        else
        {
            if(s1->ele[i].j<s2->ele[j].j)
                sum->ele[k++]=s1->ele[i++];
            else if(s1->ele[i].j>s2->ele[j].j)
                sum->ele[k++]=s2->ele[j++];
            else
            {
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;
            }

        }
    }
    for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
    for(;j<s2->num;j++)sum->ele[k++]=s2->ele[j];
    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k;


    return sum;
}
int Structmain()
{
    struct Sparse s1,s2,*s3;

    create(&s1);
    create(&s2);

    s3=add(&s1,&s2);

    printf("First Matrix\n");
    display(s1);
    printf("Second Matrix\n");
    display(s2);
    printf("Sum Matrix\n");
    display(*s3);


    return 0;
}
/*
CPP
https://en.cppreference.com/w/cpp/language/friend

#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;
public:
 Sparse(int m,int n,int num)
 {
    this->m=m;
    this->n=n;
    this->num=num;
    ele=new Element[this->num];
 }
 ~Sparse()
 {
    delete [] ele;
 }

 Sparse operator+(Sparse &s);

 friend istream & operator>>(istream &is,Sparse &s);
 friend ostream & operator<<(ostream &os,Sparse &s);


};
Sparse Sparse::operator+(Sparse &s)
{
    int i,j,k;
    if(m!=s.m || n!=s.n)
    return Sparse(0,0,0);
    Sparse *sum=new Sparse(m,n,num+s.num);

    i=j=k=0;
    while(i<num && j<s.num)
    {
        if(ele[i].i<s.ele[j].i)
            sum->ele[k++]=ele[i++];
        else if(ele[i].i > s.ele[j].i)
            sum->ele[k++]=s.ele[j++];
        else
        {
            if(ele[i].j<s.ele[j].j)
                sum->ele[k++]=ele[i++];
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++]=s.ele[j++];
            else
            {
                sum->ele[k]=ele[i];
                sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
            }
        }
    }
    for(;i<num;i++)sum->ele[k++]=ele[i];
    for(;j<s.num;j++)sum->ele[k++]=s.ele[j];
    sum->num=k;

    return *sum;

}
istream & operator>>(istream &is,Sparse &s)
{
    cout<<"Enter non-zero elements";
    for(int i=0;i<s.num;i++)
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    return is;
}
ostream & operator<<(ostream &os,Sparse &s)
{
    int k=0;
    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            if(s.ele[k].i==i && s.ele[k].j==j)
                cout<<s.ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

int main()
{
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);

    cin>>s1;
    cin>>s2;

    Sparse sum=s1+s2;

    cout<<"First Matrix"<<endl<<s1;
    cout<<"Second MAtrix"<<endl<<s2;
    cout<<"Sum Matrix"<<endl<<sum;

    return 0;
}

*/

/*
Polynomial Representation
1. Polynomial Representation
2. Evaluation of Polynomial
3. Additions of polynomials

Example
3x^5+2x^4+5x^2+2x+7

coefficient
3|2|5|2|7
exponent
5|4|2|1|0

*/
struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    int i;
    printf("Number of terms?");
    scanf("%d",&p->n);
    p->terms=(struct Term*)malloc(p->n*sizeof(struct Term));

    printf("Enter terms\n");
    for(i=0;i<p->n;i++)
        scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);

}
void display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
        printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
        printf("\n");
}
struct Poly *add(struct Poly *p1,struct Poly *p2)
{
 int i,j,k;
 struct Poly *sum;

 sum=(struct Poly*)malloc(sizeof(struct Poly));
 sum->terms=(struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term));
 i=j=k=0;

 while(i<p1->n && j<p2->n)
 {
    if(p1->terms[i].exp>p2->terms[j].exp)
        sum->terms[k++]=p1->terms[i++];
    else if(p1->terms[i].exp < p2->terms[j].exp)
        sum->terms[k++]=p2->terms[j++];
    else
    {
        sum->terms[k].exp=p1->terms[i].exp;
        sum->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
    }
 }
 for(;i<p1->n;i++)sum->terms[k++]=p1->terms[i];
 for(;j<p2->n;j++)sum->terms[k++]=p2->terms[j];

 sum->n=k;
 return sum;


}