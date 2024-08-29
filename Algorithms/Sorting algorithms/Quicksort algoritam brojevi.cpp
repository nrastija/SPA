#include <iostream>
#include <iomanip>
using namespace std;

void QuickSort (int lijevi, int desni, int niz[])
{
	int i= lijevi;
	int j= desni;
	int pivot = niz[(lijevi+desni)/2];
	while (i<=j)
		{
		while (niz[i] < pivot) i=i+1;
		while (pivot < niz[j]) j=j-1;
		
		if (i<=j){
			int temp = niz[i];
			niz[i] = niz[j];
			niz[j] = temp;
			i = i+1;
			j = j-1;
		}
	}
	if (lijevi < j) QuickSort (lijevi, j, niz);
	if (i < desni) QuickSort (i, desni, niz);
}


int main ()
{
	int N;
	
	cout << "Unesite broj elemenata: \n";
	do{
		cin >> N;
	} while (N<1);
	
	int niz[N];
	
	cout << "Unesite elemente: \n";
	
	for (int i=1; i<N; i++)
		{
			cin >> niz[i];
		}

	cout << endl;
	QuickSort (1, N, niz);
	
	cout << "Sortirana polja quicksortom: " << endl;
	for (int i=1; i<N; i++)
		{
			cout << niz[i] << endl;
		}





	cout << endl;
	system ("pause");
	return 0;
}
