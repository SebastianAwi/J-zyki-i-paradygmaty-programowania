#include <stdio.h>

long long collatzSequenceLength(long long n) {
    long long length = 1;   // Inicjalizacja d�ugo�ci ci�gu na 1

    while (n != 1) {
        if (n % 2 == 0) {  // Je�li n jest parzyste
            n = n / 2;
        } else {  // Je�li n jest nieparzyste
            n = 3 * n + 1;
        }
        length++;  // Inkrementacja d�ugo�ci ci�gu
    }

    return length;
}

int main() {
    long long maxChainLength = 0;
    long long numberWithMaxChain = 0;

    for (long long i = 1; i < 1000000; i++) {
        long long chainLength = collatzSequenceLength(i);
        if (chainLength > maxChainLength) {
            maxChainLength = chainLength;
            numberWithMaxChain = i;
        }
    }

    printf("The starting number under one million that produces the longest chain is %lld\n", numberWithMaxChain);

    return 0;
}
