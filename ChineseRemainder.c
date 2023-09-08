#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < K; i++)
    {

        scanf("%lld", &m[i]);
    }

    //Brute Force

    long long int x = 1;
    while (1)
    {
        int i = 0;
        for (i = 0; i < K; i++)
        {
            if ((x - v[i]) % m[i] == 0)
            {}
            else
                break;
        }
        if (i == K)
            break;
        x++;
    }
    printf("x=%lld\n", x);

    return 0;
}
