#include <iostream>
using namespace std;

int niz[100];

void Merge (int mali, int srednji, int veliki)
{
	int h, i, j, k, b[100];
	h=i=mali;
	j=srednji+1;
	while ((h<=srednji) && (j<=veliki))
		{
			if (niz[h] <= niz[j])
			{
				b[i] = niz[h];
				h++;
			}
			else 
			{
				b[i] = niz[j];
				j++;
			}
			i++;
		}
	if (h>srednji)
	{
		for (k=j; k<=veliki; k++)
		{
			b[i] = niz[k];
			i++;
		}
	}
	else
	{
		for (k=h; k<=srednji; k++)
		{
			b[i] = niz[k];
			i++;
		}
	}
	for (k=mali; k<=veliki; k++) niz[k] = b[k];
}

void MergeSort (int mali, int veliki)
{
	int srednji;
	if (mali < veliki)
	{
		srednji = (mali+veliki)/2;
		MergeSort (mali,srednji);
		MergeSort (srednji+1, veliki);
		Merge(mali, srednji, veliki);
	}
}

int main ()
{
	int N;
	
	cout << "Unesite broj elemenata polja: \n";
	do{
		cin >> N;
	} while (N<1 || N>100);
	
	cout << "Unesite brojeve: \n";
	for (int i=1; i<=N; i++) cin >> niz[i];


	MergeSort (1, N);

	cout << "Sortirani brojevi mergesortom: \n";
	for (int i=1; i<=N; i++) cout << niz[i] << endl;

	cout << endl;
	system ("pause");
	return 0;
}
