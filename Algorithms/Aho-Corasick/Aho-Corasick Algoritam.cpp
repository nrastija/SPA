#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "AhoCorasickH.h"

using namespace std;


int main()
{
    vector<string> rjecnik {"izazov", "dzungla", "pustolovstvo", "algoritam", "svjetlo", "rijec", "Aho-Corasick"};
			
	Aho aho_trie {};

	ifstream datoteka("Test_tekst.txt");

	for (auto& rijec : rjecnik)
	    {
		aho_trie.dodaj_rijec(rijec);
			
	    aho_trie.pripremi();
		}
			
		string tekst;
		char ch;
		
		while (datoteka.get(ch)) tekst += ch;
    	
    
	datoteka.close();
	
	cout << tekst << endl;

    int podudaranja = aho_trie.obradi(tekst);
    
    cout << "Ukupno podudaranja: " << podudaranja << endl;
    
    return 0;
}