#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
	srand(time(0));
	rand();

	int N;
	do {
		cin >> N;
	} while (N<1);
	
	int polje[N];

	for (int i=0; i<N; i++) polje[i] = rand();

	//Selection sort
	for (int i=N-1; i>0; i--)
	{
		int max=0;
		for (int j=1; j<=i; j++) // j<=i, ne j<=N!!
			if (polje[j] > polje[max]) max = j;
		if (max==i) continue;
		int temp = polje[i];
		polje[i] = polje[max];
		polje[max] = temp;
	}
	
	

	cout << "Brojevi sortirani selection sortom: \n";
	for (int i=0; i<N; i++)cout << polje[i] << endl;
	
	cout << endl;
	system ("pause");
	return 0;
}
