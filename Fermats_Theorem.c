#include <stdlib.h>

#include <stdio.h>
#include <time.h>

int power( int a,  int k){
    // k=k-1;
    while(k--){
        a=a*a;
    }
    return a;
}

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
long long int modExponentiation(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    int bits = 0;
    if(exponent==0){
        return result;
    }
    
    if(exponent%2==1){
        result = base;
    }
    while (exponent > 0) {
       
        exponent = (exponent/ 2);
        bits++;
        base = (base * base) % modulus;
        
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
    }

    // printf("%d\n", bits);
    return result;
}

long long int pick_random(long long int n){
    long long int a = rand()%(n-3)+2;
    return a;
}
int fermats_theorem(long long int  n,long long int t ){
    
    for(int i=1;i<t;i++){
        long long int a = pick_random(n);
        printf("%lld\n",a);
        long long int r = modExponentiation(a,n-1,n);
        // long long int r = power(a,n-1)%n;
        if(r!=1) return 0;
    }
    return 1;
}

int main(){
     srand(time(NULL));
    long long int n;
    scanf("%lld",&n);
    int ans = fermats_theorem(n,1000);
    if(ans){
        printf("The given number: %lld is Prime",n);
    }
    else{
        printf("The given number: %lld is Composite",n);

    }
    return 0;
}