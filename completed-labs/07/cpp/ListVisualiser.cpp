#include "SLList.hpp"
#include "ListVisualiser.hpp"
#include <iostream>
using namespace std;
ListVisualiser::ListVisualiser(SLList *a) {

	mySLList = a;
}

void ListVisualiser::visualise() {  
	for (int i = 0; i < mySLList->length(); i++)
	{
		if (mySLList->nthRest(i)->rest() != SLList::NIL)
		{
			cout << "[*|*]->	";
		}
		else
		{
			cout << "[*|/]";
		}
	}
	cout << endl;

	
	for(int j = 0; j < mySLList->length(); j++)
	{
		cout << " |	";
	}
	
	cout << endl;

	for (int k = 0; k < mySLList->length(); k++)
	{
		cout << " " << mySLList->nth(k) << "	";
	}

	
	

}
