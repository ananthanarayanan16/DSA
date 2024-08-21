// IMPLEMENTATION OF RECURSION 

#include<stdio.h>

//  FUCNTION DECLERATION

void function_1(int);
void function_2(int);

//  MAIN FUNCTION

int main()
{
    int n;
    
    printf("Enter a number : ");
    scanf("%d",&n);

    //  FUNCTION CLALLING

    printf("Function_1\n");
    function_1(n);
  
    printf("Function_2\n");
    function_2(n);

    return 0;
}

//  FUNCTION_1 DEFINITION

void function_1(int n)
{
    if(n > 0)
    {
        function_1(n - 1);      //  FUNCTION CALL ITSELF.
        printf("%d\n",n);
    }
}

//  FUNCTION_2 DEFINITION

void function_2(int n)
{
    if(n > 0)
    {
        function_2(n - 1);      //  FUNCTION CALL ITSELF.
        printf("%d\n",n);
    }
}

/*

output : 

Enter a number : 5
Function_1
1
2
3
4
5
Function_2
1
2
3
4
5

*/