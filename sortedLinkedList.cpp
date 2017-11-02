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
		/*if(p->x < x) {
			n = head;
		}*/
		while(p->next) {
			if(p->x >= x){
				n->prev = p->prev;
				p->prev->next = n;
				p->prev = n;
				n->next = p;
				break;
				// p->next = n->next;
				// n->prev = p->prev;
				// n->x =  x;

			}
			//cout<<p->x<<" "<<x<<endl;
			// if(p->x < x) {
			//
			// 	n->prev = p->prev;
			// 	p->prev->next = n;
			// 	p->prev = n;
			// 	n->next = p;
			// 	//n->x = x;
			// }
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

	// build model to test our methods.


	SortedLinkedList::node *a = new SortedLinkedList::node;
	SortedLinkedList::node *b = new SortedLinkedList::node;
	SortedLinkedList::node *c = new SortedLinkedList::node;
	SortedLinkedList::node *d = new SortedLinkedList::node;
	SortedLinkedList::node *e = new SortedLinkedList::node;
	SortedLinkedList::node *f = new SortedLinkedList::node;

	a->prev = nullptr;
	a->next = b;
	sorted.head = a;
	b->prev = a;
	b->next = c;
	c->prev = b;
	c->next = d;
	d->prev = c;
	d->next = e;
	e->prev = d;
	e->next = f;
	f->prev = e;
	f->next = nullptr;

	cout<<"model created succesfully!"<<endl;

	//cout<<sorted.head->x<<endl;

	cout<<"data writing:"<<endl;

	a->x = 1;
	b->x = 2;
	c->x = 3;
	d->x = 4;
	e->x = 5;
	f->x = 6;
	// end of model

	cout<<"data writing succesfull!"<<endl;
	//test for our function
	sorted.print();
	sorted.push(2); // should find 5 becasue 5 is first bigger than 4
	sorted.print();



	//sorted.print();
	//cout << sorted.size() << endl;
}
