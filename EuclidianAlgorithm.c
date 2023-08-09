// Euclidean algorithm for finding the Greatest Common Divisor of two large integers.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long long int  gcd_calculator(long long int a, long long int b)
{
    while (b > 0)
    {
        long long int q = (long long int)(a/b);
        long long int r = a - q * b;
        a = b;
        b = r;
    }

    return a;
}
long long int randll(){
    long long int a = rand();
    long long int b= rand();
    int c = b%33;
    if(a>b){
        return (a<<c)|b;
    }
    else{
        return (b<<c)|a;
    }
    
}
int main()
{
    srand(time(NULL));
    long long int x;
    long long int y;
    printf("Do you want to use random values of x and y to test the code?\n");
    int choice = 0;
    printf("Press 0 to continue, press any other key to decline\n");
    scanf("%d", &choice);

    if (choice == 0)
    {
        x= randll();
        y= randll();
        if(x <y){
            long long int temp = x;
            x=y;
            y=temp;
        }
         printf("The greatest common divisor of %lld and %lld is %lld\n",x,y,gcd_calculator(x, y));

        
    }
    else{

        printf("Enter two long numbers you wish to find gcd of:");
        scanf("%lld", &x);
        scanf("%lld", &y);
        printf("The greatest common divisor of %lld and %lld is %lld\n",x,y,gcd_calculator(x, y));

    }

    return 0;
}