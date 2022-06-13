#include <stdio.h>  
#include <math.h>
#include <string.h>

char a[1000];
char b[1000];

void string_copy(int i)
{
    if(i == strlen(a)) return;
    else
    {
        b[i] = a[i];
    }
    string_copy(i+1);
}

int main()
{
    gets(a);
    string_copy(0);
    printf("%s",b);
}
