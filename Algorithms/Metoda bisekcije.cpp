#include <iostream>
using namespace std;

#define EP 0.01
double funkcija (double x){
	return x*x*x - x*x + 2; // x^3 - x^2 +2
}

void bisekcija (double a, double b)
{
	if (funkcija(a) * funkcija(b) >= 0)
	{
		cout << "Niste unijeli dobar a i b \n ";
		return;
	}
	double c = a;
	while ((b-a) >= EP) 
	{
	c=(a+b)/2;
	if (funkcija(c)==0.0) break;
	
	else if (funkcija(c)*funkcija(a)<0) b=c;
	else a = c;
	}
	cout << "Korijen broja je: " << c;
	

}

int main ()
{
	
	double A,B;
	cin >> A >> B;

	bisekcija (A,B);






	cout << endl;
	system ("pause");
	return 0;
}
