#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int FibonaccijevClan(int brojclana);

int FibonaccijevClan(int brojclana){
	if (brojclana < 3)
		return 1;
	else{
		int finClan = FibonaccijevClan (brojclana-1) + FibonaccijevClan(brojclana-2);
		return finClan;
	}
}

int main ()
{
	int N;
	
	do{
		cin >> N;
	} while (N<1);
	for (int i=1; i<= N; i++)
	{
		int FibClan = FibonaccijevClan(i);
		cout << "a" << i << " = " << FibClan << endl;
	}
	cout << endl;
	system ("pause");
	return 0;
}


