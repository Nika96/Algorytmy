#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortedArrayList.h"
#include "sortedLinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {

	SortedLinkedList sl1, sl2, sl3;
	SortedArrayList sa1, sa2, sa3;
	//gdy po ./merging nie bd argumentu to program bd pobiera 4 linijki
	if(argc == 1) {

		int l1, l2;


		cin>>l1;
		//cout<<l1<<endl;
		for(int i=0;i<l1;i++)
		{
			cin>>l2;
			//cout<<l2<<endl;
			sa1.push(l2);
			sl1.push(l2);
		}

		//cout<<l1<<endl;
		cin>>l1;
		for(int i=0;i<l1;i++)
		{
			cin>>l2;
			//cout<<l2<<endl;
			sa2.push(l2);
			sl2.push(l2);
		}
	}
	else
	{
		srand(time(NULL));
		int size = atoi(argv[1]);
		int size1 = rand()%size;
		int size2 = size - size1;
		for(int i=0; i<size1;i++)
		{
			sa1.push(rand());
			sl1.push(rand());
		}

		for(int i=0; i<size2; i++)
		{
			sa2.push(rand());
			sl2.push(rand());
		}
	}

	sa3 = SortedArrayList::merge(sa1, sa2);
	sl3 = SortedLinkedList::merge(sl1, sl2);

	cout<<endl<<"sa3:"<<endl<<endl;
	sa3.print();
	cout<<endl<<"sl3:"<<endl<<endl;
	sl3.print();

	sa3.unique();//aaaaaaa
	sl3.unique();

	cout<<endl<<"sa3 unique:"<<endl<<endl;
	sa3.print();
	cout<<endl<<"sl3 unique:"<<endl<<endl;
	sl3.print();
}
