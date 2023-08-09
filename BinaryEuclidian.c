// Binary Euclidean algorithm for finding the Greatest Common Divisor of two large integers.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long long int  binary_gcd_calculator(long long int x, long long int y)
{
    long long g=1;
    long long t;

  while (x%2==0 && y%2==0){
    x=x/2;
    y=y/2;
    g=2*g;
  }

  while (x!=0){
  
    while(x%2==0){
        x=x/2;
    }
    while(y%2==0){
        y=y/2;
    }

    // t=abs(x-y)/2;
    if(x>y){
        t=(x-y)/2;
    }
    else{
        t=(y-x)/2;
    }

    
    if(x>=y){
        x=t;
    }
    else{
        y=t;
    }
    

  }

  return g*y;
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
         printf("The greatest common divisor of %lld and %lld is %lld\n",x,y,binary_gcd_calculator(x, y));

        
    }
    else{

        printf("Enter two long numbers you wish to find gcd of:");
        scanf("%lld", &x);
        scanf("%lld", &y);
        printf("The greatest common divisor of %lld and %lld is %lld\n",x,y,binary_gcd_calculator(x, y));

    }

    return 0;
}