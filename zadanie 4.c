#include <stdio.h>
//Słowo kluczowe typedef służy do nadawania nowego nazwanego typu dla już istniejącego typu w języku C. W przypadku typedef struct, używamy go do definiowania nowego typu struktur
// Abstrakcyjna klasa bazowa
typedef struct {
    void (*print)(void*);
} BaseClass;

// Pierwsza pochodna klasy bazowej
////greet, która przyjmuje argument typu void* i nie zwraca żadnej wartości. To pole jest używane do przechowywania adresu funkcji derivedclass1 i wyswietalnie powitalnej klasy
typedef struct {
    BaseClass base;
    void (*greet)(void*);
} DerivedClass1;

// Druga pochodna klasy bazowej
typedef struct {
    BaseClass base;
    void (*calculate)(void*);
} DerivedClass2;
//klasa pochodna
// Metoda print dla klasy bazowej
void basePrint(void* obj) {
    printf("To jest obiekt klasy bazowej.\n");
}

// Metoda greet dla pierwszej pochodnej
void derived1Greet(void* obj) {
    printf("Witaj z obiektem pierwszej pochodnej klasy bazowej!\n");
}
//obj, który jest wskaźnikiem typu void. Wykorzystanie wskaźnika typu void* oznacza, że funkcja może przyjąć dowolny wskaźnik jako argument.
// Metoda calculate dla drugiej pochodnej
void derived2Calculate(void* obj) {
    printf("Obliczanie w obiekcie drugiej pochodnej klasy bazowej.\n");
}

int main() {
    BaseClass baseObj;
    DerivedClass1 derivedObj1;
    DerivedClass2 derivedObj2;
//obiekt pochodny
//klasa pochodna
    // Przypisanie odpowiednich metod
    baseObj.print = basePrint;
    derivedObj1.base.print = basePrint;
    derivedObj1.greet = derived1Greet;
    derivedObj2.base.print = basePrint;
    derivedObj2.calculate = derived2Calculate;

    // Wywolanie polimorficznych metod
    baseObj.print(&baseObj);
    derivedObj1.base.print(&derivedObj1);
    derivedObj1.greet(&derivedObj1);
    derivedObj2.base.print(&derivedObj2);
    derivedObj2.calculate(&derivedObj2);

    return 0;
}
