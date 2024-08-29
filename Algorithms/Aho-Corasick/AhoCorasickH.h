#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>

class Aho {
    struct Cvor {
        std::unordered_map<char, int> djeca {};
        int roditelj = -1;
        int sufiks_link = -1;
        int link_kraj = -1;
        int ID_rijeci = -1;
        char roditeljski_znak;
        bool list = false;
    };

    std::vector<Cvor> trie;
    std::vector<int> duljine_rijeci;
    int velicina;
    int korijen;
    int ID_rijeci; 

public:
    Aho()
        : trie{}, duljine_rijeci{}, velicina{0}, korijen{0}, ID_rijeci{0}
    {
        trie.push_back(Cvor{});
        ++velicina;
    }

    void dodaj_rijec(const std::string& rijec)
    {
        int trenutni_cvor = korijen;

        for (char slovo : rijec)
        {
            if (trie[trenutni_cvor].djeca.find(slovo) == trie[trenutni_cvor].djeca.end())
            {
                trie.push_back(Cvor{});

                trie[velicina].roditelj = trenutni_cvor;
                trie[velicina].roditeljski_znak = slovo;
                trie[trenutni_cvor].djeca[slovo] = velicina;
                velicina++;
            }

            trenutni_cvor = trie[trenutni_cvor].djeca[slovo];
        }

        trie[trenutni_cvor].list = true;
        trie[trenutni_cvor].ID_rijeci = ID_rijeci;
        duljine_rijeci.push_back(rijec.size());

        ++ID_rijeci;
    }

    void pripremi()
    {
        std::queue<int> red_cvorova {};
        red_cvorova.push(korijen);

        while (!red_cvorova.empty())
        {
            int trenutni_cvor = red_cvorova.front();
            red_cvorova.pop();

            RacunajSufiksLink(trenutni_cvor);

            for (const auto& par : trie[trenutni_cvor].djeca)
                red_cvorova.push(trie[trenutni_cvor].djeca[par.first]);
        }
    }

    int obradi(const std::string& tekst)
    {
        int trenutno_stanje = korijen;
        int rezultat = 0;

        for (int j = 0; j < tekst.size(); j++)
        {
            while (true)
            {
                if (trie[trenutno_stanje].djeca.find(tekst[j]) != trie[trenutno_stanje].djeca.end())
                {
                    trenutno_stanje = trie[trenutno_stanje].djeca[tekst[j]];
                    break;
                }

                if (trenutno_stanje == korijen) break;

                trenutno_stanje = trie[trenutno_stanje].sufiks_link;
            }

            int provjera_stanja = trenutno_stanje;

            while (true)
            {
                provjera_stanja = trie[provjera_stanja].link_kraj;

                if (provjera_stanja == korijen) break;

                ++rezultat;
                int indeks_podudaranja = j + 1 - duljine_rijeci[trie[provjera_stanja].ID_rijeci];

                std::cout << "Podudaranje na indeksu " << indeks_podudaranja << ": ";
                std::cout << tekst.substr(indeks_podudaranja, duljine_rijeci[trie[provjera_stanja].ID_rijeci]) << std::endl;

                provjera_stanja = trie[provjera_stanja].sufiks_link;
            }
        }

        return rezultat;
    }

private:
    void RacunajSufiksLink(int cvor)
    {
        if (cvor == korijen)
        {
            trie[cvor].sufiks_link = korijen;
            trie[cvor].link_kraj = korijen;
            return;
        }

        if (trie[cvor].roditelj == korijen)
        {
            trie[cvor].sufiks_link = korijen;

            if (trie[cvor].list) 
                trie[cvor].link_kraj = cvor;
            else 
                trie[cvor].link_kraj = trie[trie[cvor].sufiks_link].link_kraj;

            return;
        }

        int trenutni_bolji_cvor = trie[trie[cvor].roditelj].sufiks_link;
        char znak_cvor = trie[cvor].roditeljski_znak;

        while (true)
        {
            if (trie[trenutni_bolji_cvor].djeca.find(znak_cvor) != trie[trenutni_bolji_cvor].djeca.end())
            {
                trie[cvor].sufiks_link = trie[trenutni_bolji_cvor].djeca[znak_cvor];
                break;
            }

            if (trenutni_bolji_cvor == korijen)
            {
                trie[cvor].sufiks_link = korijen;
                break;
            }

            trenutni_bolji_cvor = trie[trenutni_bolji_cvor].sufiks_link;
        }

        if (trie[cvor].list) 
            trie[cvor].link_kraj = cvor;
        else 
            trie[cvor].link_kraj = trie[trie[cvor].sufiks_link].link_kraj;
    }
};