#include "sortedArrayList.h"

#define cc const_cast<SortedArrayList&>

SortedArrayList::SortedArrayList() {
	for(int i = 0; i<maxlength; i++)
		elements[i] = -1;

	size = 0;
}

/*int SortedArrayList::size() {

	int counter =0;
	for(int i=0; i<maxlength; i++) {
		if(elements[i] != -1)
			counter++;
	}
	return counter;
}*/

void SortedArrayList::print() {
	for(int i=0; i<size; i++) {
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
			for(int z = size; z>= i; z--) {
				elements[z+1] = elements[z];
			}
			elements[i] = x;
			break;
		}
	}
	size++;

}

int SortedArrayList::pop() {
	//temp to najmniejszy element tablicy, bo jest posortowana
	int temp = elements[0];
	if(size>0) {
		for(int i=0; i<size;i++) {
			elements[i] = elements[i+1];
		}
		//int s = size;
		//s = size -1;
		size--;
		return temp;
	}
	else
		return -1;
}

//usuwa element na pozycji "i" i zwraca jego wartosc
int SortedArrayList::erase(int i) {
	int temp = elements[i];
	for(int z = i; z <= size; z++) {
		//cout << i << endl;
		elements[z] = elements[z+1];
		elements[size] = -1;

	}
	size--;
	return temp;
}

int SortedArrayList::find(int x) {
	for(int i=0; i<size; i++) {
		if(elements[i] == x) {
			return i;
		}
	}
	return -1;
}

//usuwa wszystkie elementy rowne x
void SortedArrayList::remove(int x) {

	while(find(x) != -1) {
		erase(find(x));
	}
}

//usuwa sasiadujace duplikaty
void SortedArrayList::unique() {
	for(int i = 0; i<size; i++ ) {
		if(elements[i] == elements[i+1])  {
			//cout << i << endl;
			erase(i);
			i--;
		}
	}
}

const int SortedArrayList::getElement(const int i) const
{
	return elements[i];
}

SortedArrayList SortedArrayList::merge(const SortedArrayList& a,   const SortedArrayList& b) {

	SortedArrayList c;

	int max = a.size;
	for(int i = 0; i<max; i++) {
		c.push(a.getElement(i));
	}

	max = cc(b).size;
	for(int i = 0; i<max; i++) {
		c.push(b.getElement(i));
	}
	return c;
}
