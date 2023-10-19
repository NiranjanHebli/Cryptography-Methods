#include<stdio.h>
#include<stdlib.h>

long long int pick_random(long long int n){
    long long int a = rand()%(n-3)+2;
    if(a%2) a=a-1;
    return a;
}
long long int jacobi(long long int n,long long int a){
    if(a==0) return 0;
    if(a==1) return 1;
    long long int a1=0;
    long long int e=0;
    long long int x=(1<<e);
    while(x<a){
        e++;
        x=(1<<e);
    }
    a1=a/x;
    printf("Value of a1 : %lld\n",a1);
     printf("Value of e : %lld\n",e);
    long long int s=0;
    if(e%2==0){
        s=1;
    }
    else if((n-1)%8==0 || (n-7)%8==0) s=1;
    else if ((n-3)%8==0 || (n-5)%8==0) s=-1;
    if((n-3)%4==0 && (a1-3)%4==0) s=-1*s;
    long long n1= n%a1;
    if(a1==1) return s;
    return s*jacobi(n1,a1);

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

    printf("%d\n", bits);
    return result;
}

int solovay_strassen_theorem(long long int n,long long int t){
    long long int a =0;
    for(int i=1;i<t;i++){
        a=pick_random(n);
        long long int r = modExponentiation(a,(n-1)/2,n);
        if(r!=1 && r!=n-1) return 0;
        long long int s=jacobi(n,a);
        if((r-s)%n!=0) return 0;
    }
    return 1;
}

int main(){
    long long int n;
    scanf("%lld",&n);
    int ans = solovay_strassen_theorem(n,100);
    if(ans) printf("The given number: %lld is Prime",n);
    else printf("The given number: %lld is Composite",n); 
}