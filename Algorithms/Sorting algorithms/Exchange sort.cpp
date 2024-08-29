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
	
	//Exchange sort
	
	for (int i=N-1; i>0; i--)
		for (int j=0; j<i; j++)
			if (polje[j] > polje[i])
			{
				int temp = polje[i];
				polje[i] = polje[j];
				polje[j] = temp;
			}

	cout << "Sortirani brojevi exchange sortom: \n";
	for (int i=0; i<N; i++) cout << polje[i] << endl;

	cout << endl;
	system ("pause");
	return 0;
}
