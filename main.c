#include <stdio.h>
#include <string.h>

int get_num_letters(int num); //pobiera jako argument liczbe ca³kowita num, a nastêpnie zwraca liczbe liter, które bylyby u¿yte

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += get_num_letters(i);
    }
    printf("Calkowita liczba uzytych liter to %d\n", sum);
    return 0;
}

int get_num_letters(int num) {
    char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int num_letters = 0;

    if (num == 1000) {
        return strlen("onethousand"); // zwraca dlugosc lancucha znakow 11
    }

    if (num >= 100) {
        num_letters += strlen(ones[num/100]) + strlen("hundred");      // okreœlenie cyfry setek
        if (num % 100 != 0) {
          //reszta z dzielenia przez 100, dziesiatki i jednosci
            num_letters += strlen("and");
        }
    }

    if (num % 100 < 20) {
        num_letters += strlen(ones[num % 100]);
    } else {
        num_letters += strlen(tens[(num % 100)/10]);
        num_letters += strlen(ones[num % 10]);
    }

    return num_letters;
}
