// Repeated square-and-multiply algorithm for exponentiation in Zn
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int binary_digits(long long int k)
{
    int digits = 0;
    while (k)
    {
        k = k / 2;
        digits++;
    }
    return digits;
}

long long int repeated_square_and_multiple(long long int a, long long int k, long long int n)
{

    long long int b = 1;
    if (k == 0)
    {
        return b;
    }
    long long int A = a;
    if (k & 1)
    {
        b = a;
    }
    int t = binary_digits(k);
    k = k / 2;
    for (int i = 0; i < t; t++)
    {
        A = (A * A) % n;
        if (k & 1)
        {
            b = (A * b) % n;
        }
        k = k / 2;
    }

    return b;
}

int main()
{
    srand(time(NULL));

    long long int a;

    long long int k;

    long long int n;
    int choice = 1;

    printf("Do you want to use random value to test the code?\n");
    printf("Press 0 to continue, press any other key to decline\n");
    scanf("%d", &choice);
    if (choice == 0)
    {
        a = rand();
        k = rand();
        n = rand();
    }

else{
printf("Enter number a [The number you want to find exponentiation modulus of ]: ");
scanf("%lld", &a);
printf("Enter number k [The exponent number]: ");
scanf("%lld", &k);

printf("Enter number n [The number of terms in Zn]: ");
scanf("%lld", &n);

printf("The value of a^k mod n is %lld\n", repeated_square_and_multiple(a, k, n));
}

return 0;
}
