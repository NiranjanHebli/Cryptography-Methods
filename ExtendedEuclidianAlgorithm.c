// Extended Euclidean algorithm for finding the Greatest Common Divisor of two large integers which satisfies the equation ax+by=d

#include <stdio.h>
#include <time.h>
#include<stdlib.h>

typedef struct sol
{
    long long int d;
    long long int x;
    long long int y;
} sol;

sol gcd_calculator(long long int a, long long int b)
{
    if (b == 0)
    {
        sol ans;
        ans.d = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    long long int x2 = 1;
    long long int x1 = 0;
    long long int y2 = 0;
    long long int y1 = 1;
    long long int x;
    long long int y;

    while (b > 0)
    {
        long long int q = (long long int)(a/b);
        long long int r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }

    sol ans;
    ans.d = a;
    ans.x = x2;
    ans.y = y2;
    return ans;
}
long long int randll(){
    long long int a = rand();
    long long int b= rand();
    int c = b%33;
    return (a<<c)|b;

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

    if (choice != 0)
    {
        printf("Enter two long numbers you wish to find gcd of:");
        scanf("%lld", &x);
        scanf("%lld", &y);
        printf("The greatest common divisor of %lld and %lld is %lld and it satisfies the equation ax+by=d  for x=%lld and y=%lld", x,y,gcd_calculator(x, y).d,gcd_calculator(x,y).x,gcd_calculator(x,y).y);
    }
    else{
        x= randll();
        y= randll();
        if(x <y){
            long long int temp = x;
            x=y;
            y=temp;
        }
    printf("The greatest common divisor of %lld and %lld is %lld and it satisfies the equation ax+by=d  for x=%lld and y=%lld", x,y,gcd_calculator(x, y).d,gcd_calculator(x,y).x,gcd_calculator(x,y).y);

    }

    return 0;
}