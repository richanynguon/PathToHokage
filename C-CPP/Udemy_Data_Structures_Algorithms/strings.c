/*
1. Character Set/ASCII Codes
2. Character Array
3. String
4. Creating A String

char data type can only hold on ascii code

ASCII(2 btye) code is a subset of unicodes(16bits)

char x[2]={'a','b'}
char y[]={"a"}
char z[]={65,66}

CPP
String delimeter, end of string char, null char, string terminator
"\0"

char name[] = "John"; // stack
char * name = "John"; // heap

// these look for \0
printf 
scanf - can only give one word
gets - reads for the entire string until you press enter

*/

int strLength(char * string)
{
    int i;
    for(i=0; *(string+i)!='\0';i++)
    printf('Length is %d', i);
    return 0;
}

int reverseCases(char * string)
{
    int i, upperlow=65, upperhigh=90, lowerlow=97, lowerhigh=122;
    for(i=0; *(string+i)!='\0';i++)
    {
        int currChar = *(string+i);
        if(currChar>=upperlow && currChar <= upperhigh)
            *(string+i)+=32; 
        if(currChar>=lowerlow && currChar <= lowerhigh)
            *(string+i)-=32; 
    }
    return 1;   

}

int countVowelsCon(char * string)
{
    int i, upperlow=65, upperhigh=90, lowerlow=97, lowerhigh=122;
    int A=65,E=69,I=73,O=79,U=85; 
    int vowels=0, consonants=0;
    for(i=0; *(string+i)!='\0';i++)
    {
        int currChar = *(string+i);
        if(currChar>=upperlow && currChar <= upperhigh)
            if(currChar == A || currChar == E || currChar == I ||currChar == O|| currChar == U)
                vowels++;
            else
                consonants++;
        if(currChar>=lowerlow && currChar <= lowerhigh)
            if(currChar == A+32 || currChar == E+32 || currChar == I+32 ||currChar == O+32|| currChar == U+32) 
                vowels++;
            else
                consonants++;
    }
    printf("%d vowels %d consonants", vowels, consonants);
    return 1;   
}

int countWords(char * string)
{
    int i, word=1;
    for(i=0; *(string+i)!='\0';i++)
        if(*(string+i)==" "&&*(string+i-1)==" ") word++;
    printf("%d words", word);
    return 0;
}

int validateStr(char * string)
{
    int i, curr;
    for(i=0; *(string+i)!='\0';i++)
        curr = *(string+i);
        if(!(curr>=65&&curr<=90)&&!(curr>=97&&curr<=122)&&!(curr>=48&&curr<=57))
            return 0;
    return 1;

}

int * reverseString(char * string, int length)
{
    int i, j, reversed[length];
    for(i=length, j=0; j<=length; i--, j++)
        reversed[j]=*(string+i);
    return &reversed;
}

int reverseStringMemEff(char * string, int length)
{
    int i, j;
    for(i=length, j=0; j<=i; i--, j++)
        swap(*(string+i),*(string+j));
    return string; 

}

/*
Compare strings
*/

/* 
palindrome
reverse second string and compare
*/

/*
duplicates in a string, 
compare letters together, 
use hashtable
counting, 
using bits
anagram

Bitwise Operations
shifting
bit ORing (merging)
bit ANDing (masking)

setting the bit on in memory is merging
checking if bit is on is masking
*/ 
int main_is_there_duplicate()
{
  char A[]="finding";
  int i;
  long int h=0, x=0;
  for(i=0; A[i]!='\0';i++)
  {
    x=1;
    // minus it by the first letter
    // to make a 0 placement in the bit
    // shift one to the place of the alphabet
    x=x<<A[i]-97;
    if(x&h>0)
        // masking
        // checks if its bit extra bits are on

      print("%c is Duplicate", A[i]);
    else
    // merging
    // ask if both bit places either has ones
      h=x|h;
  }
}

/*
Permuation of a string:
Recursion (Calling itself)-> Back Tracking (Go back and take another route)-> Brute Force(Exploring all options)
*/
void permutations(char s[], int k)
{
    static int A[10]={0};
    static char res[10];
    int i;
    for(i=0; s[i]!='\0'; i++)
    {
        if(A[i]==0)
        {        
            res[k]=s[i];
            A[i]=1;
            permutations(s, k+1);
            A[i]=0;
        }
    }
}

void permutationsswap(char s[], int l, int h)
{
    int i;
    if(l==h)
        printf(s);
    for(i=0; i<=h; i++)
    {
        swap(s[l],s[i]);
        permutationsswap(s, l+1,h);
        swap(s[l],s[i]);
    }
}