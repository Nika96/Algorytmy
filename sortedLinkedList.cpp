#include "sortedLinkedList.h"

#define cc const_cast<SortedLinkedList&> //wytrych

SortedLinkedList::SortedLinkedList(){
	head = nullptr;
	size=0;
}

SortedLinkedList::~SortedLinkedList(){

}

void SortedLinkedList::push(int x) {
	size++;
	node *p, *n;

	p = head;
	//cout<<"test "<<x<<endl;
	//cout<<"test1"<<endl;
	//gdy lista jest pusta
	if(p == nullptr) {
		p = new node;
		p->x = x;
		p->next = nullptr;
		p->prev = nullptr;
		head = p;
		//head = n;
		return;
	}

	n = new node;
	n->x = x; //przechowuje podana wartosc
	//jesli lista nie jest pusta
	if(p != nullptr) {
		bool flag = 0;
		while(p->next) {
			if(p->x >= x){
				//cout<<"test"<<endl;
			 	n->prev = p->prev;
				if(p->prev)
					p->prev->next = n;
				else
					head = n;
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
	//delete p;
	size--;
	return temp;
}

int SortedLinkedList::erase(int i)
{
	size--;
	node *p;
	p = head;

	for(int j=0;j<i;j++)
	{
		p = p->next;
	}

	if(p->next)
		p->next->prev = p->prev;
	if(p->prev)
		p->prev->next = p->next;

	if(i==0)
	{
		head = p->next;
	}

	int temp = p->x;
	//delete p;
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
			//cout<<"counter:"<<counter<<" size: "<<size<<endl;
			erase(counter);
			counter--;
		}
		counter++;
		p=p->next;
	}

// >>>>>>> 07cd4eaaded7f793441fca0aae30cc68e879d682
}

void SortedLinkedList::print() {
	node *p;
    p = head;
    while(p){
        cout << p->x << endl;
        p = p->next;
    }
}

/*int SortedLinkedList::size(){
    node* p;
    int c = 0;
    p = head;
    while(p){
        c++;
        p = p->next; //p to jest kolejnym z listy
    }
    return c;
}*/

const int SortedLinkedList::getElement(const int i) const
{
	node *p;
	p = head;
	for(int j=0;j<i;j++)
		p = p->next;
	return p->x;
}

SortedLinkedList SortedLinkedList::merge(const SortedLinkedList& a, const SortedLinkedList& b)
{
	SortedLinkedList c;
	int max = a.size;
	for(int i = 0; i<max; i++) {
		c.push(a.getElement(i));
	}

	max = b.size;
	for(int i = 0; i<max; i++) {
		c.push(b.getElement(i));
	}
	return c;
}
