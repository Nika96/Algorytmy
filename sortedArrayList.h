#include <iostream>
#include <algorithm>
#define maxlength 50000
using namespace std;

class SortedArrayList {
public:

	int elements[maxlength];

	SortedArrayList();
    void push(int x);   // Wstawia element 'x'
    int pop();          // Zwraca i usuwa pierwszy (najmniejszy) element
    int erase(int i);   // Usuwa element na pozycji 'i' i zwraca jego wartość
    int find(int x);    // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size();         // Zwraca liczbę elementów w liście
    void remove(int x); // Usuwa wszystkie elementy równe 'x'
    static SortedArrayList merge(const SortedArrayList& a, const  SortedArrayList& b);  // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();      // Usuwa sąsiadujące duplikaty
    void print();       // Wypisuje elementy listy w porządku rosnącym
};
