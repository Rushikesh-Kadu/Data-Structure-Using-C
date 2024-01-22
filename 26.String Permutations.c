#include<stdio.h>
#include<conio.h>

void permutation(char *s,int i,int j)
{
    static int count;
    int x,temp;
    if(i==j)
       printf("%d) %s\n",++count,s);
    else
    {
        for(x=i;x<=j;x++)
        {
            temp = s[x];
            s[x] = s[i];
            s[i] = temp;
            permutation(s,i+1,j);
            temp = s[x];
            s[x] = s[i];
            s[i] = temp;
        }
    }
}

void main()
{
    char s[] = "ABC";
    permutation(s,0,2);
}