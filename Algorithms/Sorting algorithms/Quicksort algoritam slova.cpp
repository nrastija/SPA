#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void QuickSort (int lijevi, int desni, char polje[])
{
	int i = lijevi;
	int j = desni;
	int pivot = polje[(lijevi+desni)/2];
	
	while (i<=j)
	{
		while (polje[i]< pivot) i++;
		while (pivot < polje[j]) j--;
		
		if (i<=j)
		{
			char temp = polje[i];
			polje[i] = polje[j];
			polje[j] = temp;
			i++;
			j--;
		}
	}
	if (lijevi < j) QuickSort (lijevi, j, polje);
	if (i < desni) QuickSort (i, desni, polje);
}

int main ()
{

	int N;
	
	srand(time(0));
	rand();
	
	do{
		cin >>N;
	}while (N<1);

	char polje[N];
	
	for (int i=1; i<=N; i++) polje[i] = 'a' + rand()%26;

	QuickSort(1, N, polje);

	cout << "Slova sortirana Quicksortom: \n";
	for (int i=1; i<=N; i++) cout << polje[i] << endl;




	cout << endl;
	system ("pause");
	return 0;
}
