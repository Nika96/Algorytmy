#include "sortedArrayList.h"

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
	int temp = elements[i];
	for(int z = i; z <= size(); z++) {
		//cout << i << endl;
		elements[z] = elements[z+1];
		elements[size()] = -1;
	}
}

int SortedArrayList::find(int x) {
	for(int i=0; i<size(); i++) {
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
	for(int i = 0; i<size(); i++ ) {
		if(elements[i] == elements[i+1])  {
			//cout << i << endl;
			erase(i);
			i--;
		}
	}
} 

SortedArrayList SortedArrayList::merge( SortedArrayList& a,  SortedArrayList& b) {
	
	SortedArrayList c;
	//c.push(2);
	
	int temp =0;
	for(int i = 0; i<a.size(); i++) {
		temp = a.pop();
		cout << "temp w a =" << temp << endl;
		c.push(temp);
	}

	cout<<a.size();
	cout<<b.size();
	cout<<"==========="<<endl;
	for(int i = 0; i<b.size(); i++) {
		temp = b.pop();
		cout << "temp w b =" << temp << endl;
		c.push(temp);
	}
	c.print();
	return c;
}