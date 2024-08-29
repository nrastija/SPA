#include <iostream>
using namespace std;

char* polje;

void Merge (int mali, int srednji, int veliki)
{
	int h, i, j, k, b[100];
	h=i=mali;
	j=srednji+1;
	
	while ((h<=srednji) && (j<=veliki))
	{
		if (polje[h] <= polje[j])
		{
			b[i] = polje[h];
			h++;
		}
		else
		{
			b[i] = polje[j];
			j++;
		}
		i++;
	}
	if (h>srednji)
	{
		for (k=j; k<=veliki; k++)
		{
			b[i] = polje[k];
			i++;
		}
	}
	else
	{
		for (k=h; k<=srednji; k++)
		{
			b[i] = polje[k];
			i++;
		}
	}
	for (k=mali; k<=veliki; k++) polje[k] = b[k];
}

void MergeSort (int mali, int veliki)
{
	int srednji;
	if (mali <veliki)
	{
		srednji = (mali+veliki)/2;
		MergeSort (mali, srednji);
		MergeSort (srednji+1, veliki);
		Merge (mali, srednji, veliki);
	}
}


int main ()
{
	int N;
	
	cout << "Unesite broj slova u polju: " << endl;
	do {
		cin >> N;
	} while (N<1 || N>100);

	polje = new char[N];

	cout << "Unesite slova: " << endl;
	for (int i=1; i<=N; i++) cin >> polje[i];


	MergeSort (1, N);

	cout << "Sortirana slova merge sortom: " << endl;
	for (int i=1; i<=N; i++) cout << polje[i] << endl;




	cout << endl;
	system ("pause");
	return 0;
}
