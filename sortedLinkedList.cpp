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
    node *find(int x) {
    	node *tmp = head;

        while (tmp!=nullptr) //dopóki tmp nie wskazuje na ostatni rekord listy}
        {
            if (tmp->x == x)
                return tmp;

            tmp=tmp->next;
        }
        cout<<"nie istnieje"<<endl;
        return nullptr; //zwraca ENDL, jeśli wcześniej nie został znaleziony rekord z elementem x
    }
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
		head = n;
		return;
	}

	//jesli lista nie jest pusta
	if(p != NULL) {
		if(p->x < x) {
			n = head;
		}
		while(p->next) {
			if(p->x >= x){
				n->prev = p->prev;
				p->prev->next = n;
				p->prev = n;
				n->next = p;
				//n->x = x;
			}
			p=p->next; // do konca lisy	
		}
	}
}	

void SortedLinkedList::print() {
	node *p;
    p = head;
    while(p){
        cout << p->x << endl;
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
	sorted.push(10);
	sorted.push(20);
	sorted.push(2443);
	sorted.push(1);
	sorted.print();
	cout << sorted.size() << endl;
}