#include <stdio.h>
#include <stdlib.h>

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
        long long int q = (long long int)(a / b);
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

int main()
{
    long long int K;
    printf("Enter the number of terms:-(K)\n");
    scanf("%lld", &K);
    long long int *v = (long long int *)malloc(sizeof(long long int) * K);
    long long int *m = (long long int *)malloc(sizeof(long long int) * K);

    printf("Enter number whose moduli with X is tobe found(vi):-");
    for (int i = 0; i < K; i++)
    {

        scanf("%lld", &v[i]);
    }
    printf("Enter number which is used to find moduli (mi):-");
    long long int N = 1;
    for (int i = 0; i < K; i++)
    {

        scanf("%lld", &m[i]);
        N *= m[i];
    }

    long long int *Ni = (long long int *)malloc(sizeof(long long int) * K);
    for (int i = 0; i < K; i++)
    {
        Ni[i] = N / m[i];
        // printf("%lld ", Ni[i]);
    }
    long long int *X = (long long int *)malloc(sizeof(long long int) * K);
    for (int i = 0; i < K; i++)
    {
        X[i] = gcd_calculator(Ni[i], m[i]).x;
        // printf("%lld ", X[i]);
    }

    long long Xbar = 0;
    for (int i = 0; i < K; i++)
    {
        Xbar += X[i] * v[i] * Ni[i];
    }
    while (Xbar < 0) Xbar += N;
    printf("%lld", Xbar%N);

    return 0;
}
