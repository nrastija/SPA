#include <iostream>
#include <ctime>
#include <cstdlib>

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

	//Insertion sort
	for (int i=1; i<N; i++)
	{
		int j = i-1;
		int pom = polje[i];
		while (j>=0 && polje[j]>pom)
		{
			polje[j+1] = polje[j];
			j--;
		}
		polje[j+1] = pom;
	}

	cout << "Polje brojeva sortirano insertion sortom: \n";
	for (int i=0; i<N; i++) cout << polje[i] << endl;
	
	cout << endl;
	system ("pause");
	return 0;
}
