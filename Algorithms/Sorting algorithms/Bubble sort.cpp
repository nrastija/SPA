#include <iostream>
#include <ctime>
using namespace std;

int main ()
{
	
	srand(time(0));
	rand();
	
	int N;
	do{
		cin >> N;
	} while (N<1);
	
	int polje[N];
	
	for (int i=0; i<N; i++) polje[i] = rand();

	//Bubblesort
	
	while(true)
	{
		bool zamjena = false;
		for (int j=0; j<N-1; j++)
			if (polje[j] > polje[j+1])
			{
				zamjena = true;
				int temp = polje[j];
				polje[j] = polje[j+1];
				polje[j+1] = temp;
			}
		if (!zamjena) break;
	}

	cout << "Sortirani brojevi bubble sortom: \n";
	for (int i=0; i<N; i++) cout << polje[i] << endl;



	cout << endl;
	system ("pause");
	return 0;
}
