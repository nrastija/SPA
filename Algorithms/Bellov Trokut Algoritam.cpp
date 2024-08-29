#include <iostream>
using namespace std;

int BellovTrokut (int N)
{
	int bell[N+1][N+1];
	bell[0][0]=1;
	for (int i=1; i<=N; i++)
	{
		bell[i][0] = bell[i-1][i-1];
		
		for (int j=1; j<=i;j++)
			bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
	}
	return bell[N][0];
}

int main ()
{
	int N;
	
	cout << "Unesite broj clanova Bellovog trokuta: \n";
	do
	{
		cin >> N;
	} while (N<1);
	
	for (int i=0; i<=N; i++)
	{
		cout << BellovTrokut (i) << endl;
	}
	
	

	cout << endl;
	system ("pause");
	return 0;
}
