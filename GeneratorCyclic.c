#include <stdio.h>
#include <stdbool.h>

int mod_pow(int a, int b, int p) {
    int result = 1;
    a = a % p;
    
    while (b > 0) {
        
        if (b % 2 == 1) {
            result = ((result%p) * a) % p;
        }
        b = b / 2;
        a = (a * a) % p;
    }

    return result;
}

bool IsGenerator(int g, int p) {

    for (int i = 1; i < p; i++) {
        if (mod_pow(g, i, p) == 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int p;
    printf("Enter a prime number:(P): ");
    scanf("%d", &p);
    
    for (int i = 2; i< p; i++) {
        if (IsGenerator(i, p)) {
            printf("A generator for the cyclic group modulo %d is: %d\n", p, i);
            break;
        }
    }

    return 0;
}