/*Definiraj klasu Cocktail koja predstavlja koktel u baru. Koktel ima naziv (string), volu-
men u mililitrima (int), postotak alkohola (double) i cijenu (double).
(a) Implementirajte member funkciju set_data() koja prima sve atribute kao parametre
i postavlja ih. Razmislite trebaju li parametri biti proslijeđeni po vrijednosti ili
referenci.
(b) Implementirajte member funkciju is_alcoholic() koja vraća true ako koktel sadrži
alkohol. Smatrajte da je koktel alkoholni ako ima više od 0% alkohola
(c) Implementirajte member funkciju price_per_ml() koja računa cijenu po mililitru. Pa-
zite na dijeljenje s nulom!
(d) Implementirajte member funkciju print_info() koja ispisuje sve informacije o kok-
telu u preglednom formatu
·napravite vektor od 5 koktela,
·postavite im vrijednosti koristeći set_data() funkciju,
·pronađite i ispišite sve bezalkoholne koktele,
·pronađite koktel s najboljom cijenom po mililitru (najjeftiniji),
·ispišite sve koktele sortirane po postotku alkohola od najmanjeg prema najvećem,
koristite sort s lambdom.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Cocktail{
    private:
        string naziv;
        int volumen;
        double postotak;
        double cijena;
    public:
        void set_data(const string& naziv,int volumen,double postotak,double cijena){
            this->naziv=naziv;
            this->volumen=volumen;
            this->postotak=postotak;
            this->cijena=cijena;
        }
        bool is_alcoholic(){
            if(postotak>0.0){
                return true;
            }
            else
                return false;
        }
        double price_per_ml() const{
            if(volumen==0){return 0;}
            return cijena/volumen;
        }
        void print_info() const{
            cout<<"Naziv: "<<naziv<<" - ";
            cout<<"Volumen: "<<volumen<<"ml - ";
            cout<<"Postotak alkohola: "<<postotak<<"%"<<endl;
            cout<<"Cijena: "<<cijena<<"EUR"<<" - ";
            cout<<"Cijena po ml: "<<price_per_ml()<<"EUR/ml"<<endl<<endl;
        }
        double get_postotak() const{
            return postotak;
        }
};
int main(){
    vector<Cocktail> kokteli(6);
    kokteli[0].set_data("Mojito",300,10.5,8.50);
    kokteli[1].set_data("Pina Colada",350,12.0,9.80);
    kokteli[2].set_data("Shirley Temple",250,0.0,6.50);
    kokteli[3].set_data("Virgin Mojito",300,0.0,7.20);
    kokteli[4].set_data("Margarita",280,15.0,10.20);
    kokteli[5].set_data("Long Island Iced Tea",400,22.0,12.50);
    cout<<" === SVI KOKTELI === "<<endl;
    for(int i=0;i<kokteli.size();i++){
        kokteli[i].print_info();
    }
    cout<<" === BEZALKOHOLNI KOKTELI === "<<endl;
    for(int i=0;i<kokteli.size();i++){
        if(kokteli[i].is_alcoholic()==false){
            kokteli[i].print_info();
        }
    }
    cout<<"=== NAJJEFTINIJI KOKTEL PO MILILITRU ==="<<endl;
    int indeks=0;
    double najjeftiniji=2.000;
    for(int i=0;i<kokteli.size();i++){
        if(kokteli[i].price_per_ml()<najjeftiniji){
            najjeftiniji=kokteli[i].price_per_ml();
            indeks=i;
        }
    }
    kokteli[indeks].print_info();
    cout<<" === KOKTELI SORTIRANI PO ALC% ==="<<endl;
    sort(kokteli.begin(),kokteli.end(),[](const Cocktail& a, const Cocktail& b) {
        return a.get_postotak() < b.get_postotak();
    });
    for(int i=0;i<kokteli.size();i++){
        kokteli[i].print_info();
    }
    return 0;
}
