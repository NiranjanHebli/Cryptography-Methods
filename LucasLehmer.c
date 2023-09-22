#include<stdio.h>
#include<stdlib.h>
int lucasLehmer(int S){

    if(S==2) return 0;
    long long int n= (1<<S)-1;
    for(int i=S;i*i<=S;i++){
        if(S%i==0) return 1;
    }

    long long int u=4;
    
    for(int i=1;i<S-1;i++){
        u=((u%n)*(u%n)-2)%n;
    }

    return u;

}

int main()
{
    int S;
    printf("Enter the Power of 2 in N= 2^S-1:\n");
    scanf("%d",&S);
    long long int n=(1<<S)-1;
    int ans = lucasLehmer(S);
    if(ans) printf("The given integer: %lld is Composite\n",n);
    else printf("The given integer: %lld is Prime\n",n);
}
