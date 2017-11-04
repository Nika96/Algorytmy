#include <iostream>
#include <algorithm>
#define maxlength 10
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
    static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);  // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();      // Usuwa sąsiadujące duplikaty
    void print();       // Wypisuje elementy listy w porządku rosnącym
};

SortedArrayList::SortedArrayList() {
	for(int i = 0; i<maxlength; i++)
		elements[i] = -1;
}

int SortedArrayList::size() {

	int counter =0;
	for(int i=0; i<maxlength; i++) {
		if(elements[i] != -1)
			counter++;
	}
	return counter;
}

void SortedArrayList::print() {
	for(int i=0; i<size(); i++) {
		if(elements[i] != -1)
			cout<<elements[i]<<endl;
	}
}

void SortedArrayList::push(int x) {
	for(int i = 0; i<maxlength; i++) {
		if(x >= elements[i]) {
			if(elements[i] == -1) {
				elements[i] = x;
				break;
			}
		}
		else {
			for(int z = size(); z>= i; z--) {
				elements[z+1] = elements[z];
			}
			elements[i] = x;
			break;
		}
	}

}

int SortedArrayList::pop() {
	//temp to najmniejszy element tablicy, bo jest posortowana
	int temp = elements[0];
	if(size()>0) {
		for(int i=0; i<size();i++) {
			elements[i] = elements[i+1];
		}
		int s = size();
		s = size() -1;
		return temp;
	}
	else
		return -1;
}

//usuwa element na pozycji "i" i zwraca jego wartosc
int SortedArrayList::erase(int i) {

}
/*
int SortedArrayList::find(int x) {
	for(int i=0; i<elements.size(); i++) {
		if(elements[i] == x) {
			return i;
		}
	}
	return -1;
}

//usuwa wszystkie elementy rowne x
void SortedArrayList::remove(int x) {
	int counter = 1;
	for(int i = 0; i<elements.size(); i++) {
		if(elements[i] == elements[i+1]) {
			counter++;
		}
	}
	cout << "Ilosc powtorzen = " << counter << endl;

	for(int i=0; i<elements.size(); i++) {
		if(elements[i] == elements[i+1]) {
			elements.erase(elements.begin()+i, elements.begin()+i+counter);
		}
	}
}

//usuwa sasiadujace duplikaty
void SortedArrayList::unique() {
	
	int counter = 1;
	for(int i = 0; i<elements.size(); i++) {
		if(elements[i] == elements[i+1]) {
			counter++;
		}
	}
	cout << "Ilosc powtorzen = " << counter << endl;

	//ilosc powtorzen jest parzysta - usuwa wszyskie powtorzenia w liscie
	if(counter%2 == 0) {
		for(int i=0; i<elements.size(); i++) {
			if(elements[i] == elements[i+1]) {
				elements.erase(elements.begin()+i, elements.begin()+i+counter);
			}
		}		
	}
	//ilosc powtorzen jest nieparzysta - zostawia jedna wartosc powtorzona w liscie
	if(counter%2 == 1) {
		for(int i=0; i<elements.size(); i++) {
			if(elements[i] == elements[i+1]) {
				elements.erase(elements.begin()+i, elements.begin()+i+counter-1);
			}
		}
	}

} */

int main() {
	SortedArrayList sorted, sorted2;

	/*sorted2.elements[0] = 4;
	sorted2.elements[1] = 2;
	sorted2.elements[2] = 6;
	cout << sorted2.size() << endl;*/

	sorted.push(30);
//	sorted.print();
	sorted.push(76);
//	sorted.print();
	sorted.push(8);
	sorted.push(0);
	sorted.push(324);
	sorted.print(); 

	//cout <<sorted.size()<< endl;
	cout << "#######################" << endl;
	sorted.pop();
	sorted.print();	

}