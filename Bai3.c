#include <stdio.h>
#include <math.h>   
#include <string.h>

int toNum(char x){
    return x - '0';
}

int firstCheck(char a[20])
{
    int n = strlen(a);
    if (n < 13 || n > 16) return 0;
    if(a[0] != '4' && a[0] != '5' && a[0] != '6') return 0;
    if(a[0] == '3' && a[1] != '7') return 0;
    return 1;
}

int reCal(int n)
{
    if(n < 10) return n;
    else return 1 + n%10; 
}

int secondCheck(char a[20])
{
    int oddSum = 0, evenSum = 0;
     int n = strlen(a);
     if(n % 2 != 0)
     {
        for(int i =0;i<strlen(a);i++)
        {
            if(i % 2 == 1) evenSum += reCal(toNum(a[i])*2);
            else oddSum += toNum(a[i]);  
        }
     }
     
     else
     {
        for(int i=0;i<strlen(a);i++)
        {
            if(i % 2 == 0) evenSum += reCal(toNum(a[i])*2);
            else oddSum += toNum(a[i]);
        }
     }
        
       int totalSum = oddSum + evenSum;
    
       if(totalSum %10 == 0) return 1;
       return 0; 
}

int main()
{
    char s[20];
    gets(s);
    if( firstCheck(s) == 0||secondCheck(s) == 0 )
    {
        printf("So the tin dung khong hop le");
    }
    else printf("So the tin dung hop le");
}

