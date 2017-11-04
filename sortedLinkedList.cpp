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
    static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);
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
	if(p->next == NULL && p->prev == NULL) {
		n->x = x;
		head = n;
		return;
	}

	//jesli lista nie jest pusta
	if(p != NULL) {
		bool flag = 0;
		while(p->next) {
			if(p->x >= x){
			 	n->prev = p->prev;
				p->prev->next = n;
			 	p->prev = n;
			 	n->next = p;
			 	flag =1;
				break;
			}
			p=p->next; // do konca lisy
		}

		if(flag == 0)
		{
			p->next = n;
			n->prev = p;
			n->next = nullptr;
		}
	}
}

int SortedLinkedList::pop()
{
	node *p;
	p = head;
	head = p->next;
	int temp = p->x;
	delete p;
	return temp;
}

int SortedLinkedList::erase(int i)
{
	node *p;
	p = head;

	for(int j=0;j<i;j++)
	{
		p = p->next;
	}

<<<<<<< HEAD
	//this code will run if we won't find bigger
	p->next = n;
	n->prev = p;
	n->next = nullptr;
=======
	if(p->next)
		p->next->prev = p->prev;
	p->prev->next = p->next;
	int temp = p->x;
	delete p;
	return temp;
}

void SortedLinkedList::remove(int x) {
	node *p;
	p = head;

	int counter = 0;
	while(p->next) {
		if(p->x == x) {
			erase(counter);
			counter--;
		}
		counter++;
		p=p->next;
	}
}

void SortedLinkedList::unique() {
	node *p;
	p = head;
	int counter = 0;
	while(p->next) {
		if(p->x == p->next->x) {
			erase(counter);
			counter--;
		}
		counter++;
		p=p->next;
	}

>>>>>>> 07cd4eaaded7f793441fca0aae30cc68e879d682
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

<<<<<<< HEAD
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
	sorted.push(12); // should find 5 becasue 5 is first bigger than 4
	sorted.print();

=======
SortedLinkedList SortedLinkedList::merge(const SortedLinkedList& a, const SortedLinkedList& b)
{
	//a.push(0);
}
>>>>>>> 07cd4eaaded7f793441fca0aae30cc68e879d682

int main() {

	SortedLinkedList sorted1, sorted2;

	sorted1.push(1);
	sorted1.push(2);
	sorted1.push(15);
	sorted1.push(7);
	sorted1.push(7);
	sorted1.push(3);
	sorted1.print();

	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;

	sorted2.push(23);
	sorted2.push(1);
	sorted2.push(8);
	sorted2.push(7);
	sorted2.print();

	SortedLinkedList::merge(sorted1, sorted2);
}
