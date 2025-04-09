#include <math.h>

int isPrime(int num) {
    if(num == 0|| num == 1) {
        return 0;
    }
    for (int i = 2; i < num + 1 ; i++) { //i < (num / 2) + 1 ou encore mieux : i < sqrt(num) + 1
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int algoeuclide(int a, int b) {
    if (a%b == 0) {
        return a;
    }
    return algoeuclide(b, a%b);
}



int main(void) {
    return 0;
}
