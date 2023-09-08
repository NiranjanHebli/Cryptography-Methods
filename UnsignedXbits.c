#include<stdio.h>
#include<stdlib.h>

int main()
{

long long int N;
printf("Enter the number of bits of which numbers are tobe printed:\n");
scanf("%lld",&N);
long long int maxN=(1<<N);
for(long long int i=0;i<=maxN;i++){
    printf("%lld",i);
    if(i!=maxN) printf(",");
}
printf("\n");


    return 0;
}
