//  RECURSION FUNCTOIN IN GLOBAL AND STATIC VARIABLE

#include<stdio.h>

//  GLOBAL VARIABLE

int x = 0;

//  FUNCTION DECLERATION

int function(int);

//  MAIN FUNCTION

int main()
{
    int n, m;

    printf("Enter a number : ");
    scanf("%d",&n);

    //  FUNCTION CALLING

    m = function(n);

    printf("m = %d\n",m);

    return 0;
}

//  FUNCTION DEFINITION

int function(int n)
{
    if(n > 0)
    {
        x++;

        return function(n - 1) + x;     //  FUNCTION CALLING ITSELF
    }
    return 0;
}

/*

output :

Enter a number : 6
m = 36

*/