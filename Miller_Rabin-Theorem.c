#include<stdio.h>
#include<stdlib.h>

long long int pick_random(long long int n){
    long long int a = rand()%(n-3)+2;
    return a;
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


int miller_rabin(long long int n, long long int t){
long long s=0;
long long r=0;
if(n%2==0) return 0; //Incase someone gives even input by mistake
while((n-1)/(1<<s)==(double)(n-1)/(1<<s)){
    r=(n-1)/1<<s;
    s++;
}

for(int i=1;i<t;i++){
    long long int a=pick_random(n);
    long long y = modExponentiation(a,r,n);
    if(y!=1 && y!=n-1){
            long long int j=1;
            while(j<=s-1 && y!=n-1){
                y=modExponentiation(y,2,n);
                if(y==1) return 0;
                j++;
            if(y!=n-1) return 0;
            }
    }
}
return 1;
}
int main() {
long long int n=0;
scanf("%lld",&n);
if(miller_rabin(n,100)) printf("The Given Number: %lld is Prime",n);
else printf("The Given Number: %lld is Composite",n);
return 0;
}