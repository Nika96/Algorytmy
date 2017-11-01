#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxlength = 50000;

class SortedArrayList {
	vector <int> elements;
		
	public:
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


int SortedArrayList::size() {
	int s = 0;
	s =	elements.size();

	return s;
}

void SortedArrayList::print() {
	for(vector<int>::iterator it = elements.begin(); it != elements.end(); ++it)
		cout << *it << endl;
}

void SortedArrayList::push(int x) {

	elements.push_back ( x );

	//funkcja sortujaca sort() 
	sort(elements.begin(), elements.begin()+elements.size());
}

int SortedArrayList::pop() {
	//temp to najmniejszy element tablicy, bo jest posortowana
	int temp = elements[0];
	if(elements.size()>0) {
		for(int i=0; i<elements.size();i++) {
			elements[i] = elements[i+1];
		}
		int s = elements.size();
		s = elements.size() -1;
		elements.pop_back();
		return temp;
	}
	else
		return -1;
}

//usuwa element na pozycji "i" i zwraca jego wartosc
int SortedArrayList::erase(int i) {
	elements.erase(elements.begin() + i);
}

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

}

int main() {
	SortedArrayList sorted;

	sorted.push(2);
	sorted.push(2);
	sorted.push(2);
	sorted.push(3);
	sorted.push(3);
	sorted.push(3);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`" << endl;
//	sorted.remove(345);
	sorted.unique();
	sorted.print();
	cout << "SIZE " << sorted.size() << endl;

}