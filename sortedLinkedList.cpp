#include<iostream>
using namespace std;

class SortedLinkedList {
public:
	struct node {       // Zagnieżdżona klasa węzła
        int x;          // Element przechowywany przez węzeł listy
        node* next;     // Wskaźnik do kolejnego węzła
        node* prev;     // Wskaźnik do poprzedniego węzła
    };
  
    node* head;        // Wskaźnik do pierwszego węzła
   // int size;           // Ew. rozmiar listy

    SortedLinkedList();
    ~SortedLinkedList();
    void push(int x); // Wstawia element 'x'
    int pop(); // Zwraca i usuwa pierwszy (najmniejszy) element
    int erase(int i); // Usuwa element na pozycji 'i' i zwraca jego wartość
    int find(int x); // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size(); // Zwraca liczbę elementów w liście
    void remove(int x); // Usuwa wszystkie elementy równe 'x'
    static SortedLinkedList merge(const SortedLinkedList&a, const SortedLinkedList& b);
    void unique(); // Usuwa sąsiadujące duplikaty
    void print(); // Wypisuje elementy listy w porządku rosnącym
};

SortedLinkedList::SortedLinkedList(){
	head = NULL;
}

SortedLinkedList::~SortedLinkedList(){
    node *tmp;
    while(head!=nullptr){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

void SortedLinkedList::push(int x) {

	node *p, *n;
	n = new node;
	n->x = x; //przechowuje podana wartosc
	p = head;
	
	//gdy lista jest pusta
	if(n->next == NULL && n->prev == NULL) {
		n->x = x;
		return;
	}

	//jesli lista nie jest pusta
	if(p != NULL) {
		while(p->next) {
			if(p->x >= x){
			/*	p = p->next;
				n->x = head; */
			}
			if(p->x < x) {
				p->x = p; //pierwszy wiekszy to p
				//n->x = x;
				n->next = p; //nastepny dla n przypisujemy p
				n->prev = p->prev; //poprzedni dla n to p
				p->prev = n->prev; //poprzedni dla p to n
				n->x = x;
			}
			p=p->next; // do konca lisy	
		}
	}
}	

/*	node *p, *n;
    n = new node; //stworzenie nowego elementu
    n->next = NULL; //koniec listy
    n->x = x; //przechowuje podana wartosc
    p = head;
    if(p!= NULL){ //jesli lista nie jest pusta
        while(p->next) p = p->next; //szuka konca listy
        p->next = n; //wstawienie na koniec zamiast NULL
        n->prev = p;
    }
    else head = n; //w sytuacji gdy lista byla pusta
}
}*/

void SortedLinkedList::print() {
	node *p;
    p = head;
    while(p){
        cout << p->x << endl ;
        p = p->next;
    }
}

int SortedLinkedList::size(){
    node* p;
    int c = 0;
    p = head;
    while(p){
        c++;
        p = p->next; //p to jest kolejnym z listy
    }
    return c;
}

int main() {

	SortedLinkedList sorted;
	sorted.print();
	cout << sorted.size() << endl;
}