#include <iostream>
#include <cstring>
#include <vector>
#include "AhoCorasickH.h"

using namespace std;

int main()
{
    vector<string> rjecnik {"raznolikost", "povezanost", "inovacija", "perspektiva" };
			
	Aho aho_trie {};
			
	for (auto& rijec : rjecnik)
	    {
            aho_trie.dodaj_rijec(rijec);
			
	        aho_trie.pripremi();
        }

    string tekst = {"U danasnjem globaliziranom svijetu, raznolikost je kljucna rijec koja odraza bogatstvo kultura, jezika i tradicija koje zajedno oblikuju nasu planetu. Raznolikost nije samo pitanje geografske udaljenosti, vec i integracije razlicitih perspektiva koje oblikuju nasu drustvo. Kroz povijest, ljudi su se kretali iz jednog kraja svijeta u drugi, noseci sa sobom svoje price, vjerovanja i obicaje. Ova interakcija rezultirala je stvaranjem globalnog tkiva koje cini nas svijet jedinstvenim. U svakodnevnom zivotu, susrecemo se s mnogim izazovima koji proizlaze iz raznolikosti. Medutim, vazno je razumjeti da su upravo ove raznolike perspektive ono sto cini nasu drustvo zivopisnim i dinamicnim. U poslovnom svijetu, timovi koji okupljaju ljude razlicitih pozadina cesto su najinovativniji i najuspesniji. Razlicite perspektive doprinose kreativnosti i otvaraju vrata novim idejama koje bi inace ostale neotkrivene. U svjetlu ovih promjena, vazno je također naglasiti povezanost koja se javlja unatoc raznolikosti. Povezanost je most koji spaja ljude i omogucuje im da razmjenjuju ideje, resurse i iskustva. S tehnoloskim napretkom, svijet postaje sve manji, a povezanost postaje kljucna za rjesavanje globalnih izazova poput klimatskih promjena, siromastva i zdravstvenih problema. pravo u ovom kontekstu dolazi do izraza vaznost algoritama poput Aho-Corasick. Ovaj algoritam omogucuje ucinkovito pretrazivanje teksta u potrazi za određenim kljucnim rijecima. Rijeci poput 'raznolikost', 'povezanost', 'inovacija' i 'perspektiva' mogu se koristiti kao kljucne rijeci za pretragu kako bi se identificirale relevantne informacije. U zakljucku, raznolikost i povezanost predstavljaju temelj globalnog drustva. Kroz prihvacanje raznolikosti i jacanje povezanosti, mozemo stvoriti svijet u kojem se cijeni bogatstvo razlicitosti i gradi mostove izmedu ljudi diljem svijeta. Aho-Corasick algoritam samo je jedan od alata koji nam pomazu u istrazivanju i razumijevanju ovih kljucnih koncepata u danasnjem dinamicnom drustvu."};

    int podudaranja = aho_trie.obradi(tekst);
    
    cout << "Ukupno podudaranja: " << podudaranja << endl;
    
    return 0;
}