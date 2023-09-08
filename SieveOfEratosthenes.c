#include<stdio.h>
#include<stdlib.h>

int isPrime(int x){
    int i=2;
    while(i*i<=x){
        if(x%i==0) return 0;
        i++;
    }
    return 1;

}
void SieveOfEratosthenes(unsigned long long int* A,long long int N){
    if(N>=1) A[0]=-1;
    if(N>=2) A[1]=-1;
    for(int i=2;i<N;i++){
        A[i]=i;
    }
    for(int i=2;i<N;i++){
        if(A[i]==-1) continue;
        if(isPrime(A[i])){
        int k=1;
        for(int j=i;j<N;){   
        k++;
         j=A[i]*k;
         if(j>=N) break;
         A[j]=-1;
        }
        
        }   
        }
        }

void showSieve(unsigned long long int*A,long long int N){
    for(int i=0;i<N;i++){
        if(A[i]!=-1){
            printf("%d,",i);
        }
    }
    printf("\n");

}
int main()
{
    long long int N;
    printf("Enter the number of bits of which numbers are tobe printed:\n");
    scanf("%lld",&N);
    unsigned long int maxN=(1<<N);
    unsigned long long int* A = (unsigned  long long int*)malloc((maxN)*sizeof(unsigned long long int));
    SieveOfEratosthenes(A,maxN);
    showSieve(A,maxN);
    
    return 0;
}
