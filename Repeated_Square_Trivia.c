#include<stdio.h>
#include<stdlib.h>

 int power( int a,  int k){
    k=k-1;
    while(k--){
        a=a*a;
    }
    return a;
}

int main()
{
     int a=5;
     int k=596;
     int n=1234;
     int ans =power(a,k);
    printf("%d",ans%n);
    
    return 0;
}
