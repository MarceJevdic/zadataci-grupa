#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Rectangle{
    private:
        int duljina;
        int sirina;
        string boja;
    public:
        Rectangle(int d, int s, string boja){
            duljina=d;
            sirina=s;
            this->boja=boja;   
        }
        int povrsina() const{
            int p=duljina*sirina;
            return p;
        }
        bool unutar(int a, int b){
            if(a*b>povrsina()){
                return false;
            }
            if(a<duljina || b<sirina){
                return true;
            }
            else{
                return false;
            }
        }
        void postavi_boju(){
            cout<<"Koje boje želite da vaš pravokutnik bude?: "<<endl;
            string color;
            cin>>color;
            boja=color;
            cout<<"Vaš pravokutnik je sada "<<boja<<" boje!"<<endl;
        }
        void ispis_prav(){
            cout<<"Duljina: "<<duljina<<endl;
            cout<<"Sirina: "<<sirina<<endl;
            cout<<"Boja: "<<boja<<endl;
        }
        int get_duljina()const{
            return duljina;
        }
        int get_sirina()const{
            return sirina;
        }
        string get_boja()const{
            return boja;
        }
};
class Activity{
    private:
        string naziv;
        int potrebna_povrsina;
    public:
        Activity(string naziv, int potrebna_povrsina){
            this->naziv=naziv;
            this->potrebna_povrsina=potrebna_povrsina;
        }
        string get_naziv() const{
            return naziv;
        }
        int get_pp() const{
            return potrebna_povrsina;
        }
        void ispis_akt() const{
            cout<<"Naziv aktivnosti: "<<naziv<<endl;
            cout<<"Potrebna povrsina za aktivnost: "<<potrebna_povrsina<<endl;
        }
        Rectangle minimalni(){
            int o=1;
            int p=1;
            while((o*p)<potrebna_povrsina){
                o++;
                if((o*p)>=potrebna_povrsina){
                    break;
                }
                p++;
            }
            return Rectangle{o,p,"Nepoznata"};
        }
};
int main(){
    vector<Rectangle> pravokutnici{
        Rectangle(4,5,"plava"),
        Rectangle(6,7,"crvena"),
        Rectangle(3,3,"narancasta"),
        Rectangle(6,12,"bijela")
    };
    Activity a1("Joga",20);
    Activity a2("Ljubljene usta",6);
    Activity a3("Ples",21);
    a1.ispis_akt();
    Rectangle r1=a1.minimalni();
    int p1=r1.povrsina();
    cout<<"Minimalan pravokutnik potreban za vasu aktivnost: "<<endl;
    r1.ispis_prav();
    cout<<"\n";
    cout<<"Sve postojece prostorije koje zadovoljavaju vas kriterij: "<<endl;
    double najefikasniji=0.00;
    string nazivnajefikasnijeg;
    for(auto& s : pravokutnici){
        if(s.unutar(r1.get_duljina(),r1.get_sirina())){
            double postotak=(double)p1/s.povrsina()*100;
            s.ispis_prav();
            cout<<"efikasnost: "<<postotak<<"%\n";
            cout<<endl;
            if(postotak>najefikasniji){
                najefikasniji=postotak;
                nazivnajefikasnijeg=s.get_boja();
            }
        }
    }
    cout<<"Najefikasnija soba za vasu aktivnost "<<a1.get_naziv()<<" je ";
    cout<<nazivnajefikasnijeg<<" soba! Efikasnost: "<<najefikasniji<<"%!"<<"\n\n\n";
    a2.ispis_akt();
    Rectangle r2=a2.minimalni();
    int p2=r2.povrsina();
    cout<<"Minimalan pravokutnik potreban za vasu aktivnost: "<<endl;
    r2.ispis_prav();
    cout<<"\n";
    cout<<"Sve postojece prostorije koje zadovoljavaju vas kriterij: "<<endl;
    najefikasniji=0.00;
    for(auto& s : pravokutnici){
        if(s.unutar(r2.get_duljina(),r2.get_sirina())){
            double postotak=(double)p2/s.povrsina()*100;
            s.ispis_prav();
            cout<<"efikasnost: "<<postotak<<"%\n";
            cout<<endl;
            if(postotak>najefikasniji){
                najefikasniji=postotak;
                nazivnajefikasnijeg=s.get_boja();
            }
        }
    }
    cout<<"Najefikasnija soba za vasu aktivnost "<<a2.get_naziv()<<" je ";
    cout<<nazivnajefikasnijeg<<" soba! Efikasnost: "<<najefikasniji<<"%!"<<"\n\n\n";
    a3.ispis_akt();
    Rectangle r3=a3.minimalni();
    int p3=r3.povrsina();
    cout<<"Minimalan pravokutnik potreban za vasu aktivnost: "<<endl;
    r3.ispis_prav();
    cout<<"\n";
    cout<<"Sve postojece prostorije koje zadovoljavaju vas kriterij: "<<endl;
    najefikasniji=0.00;
    for(auto& s : pravokutnici){
        if(s.unutar(r3.get_duljina(),r3.get_sirina())){
            double postotak=(double)p3/s.povrsina()*100;
            s.ispis_prav();
            cout<<"efikasnost: "<<postotak<<"%\n";
            cout<<endl;
            if(postotak>najefikasniji){
                najefikasniji=postotak;
                nazivnajefikasnijeg=s.get_boja();
            }
        }
    }
    cout<<"Najefikasnija soba za vasu aktivnost "<<a3.get_naziv()<<" je ";
    cout<<nazivnajefikasnijeg<<" soba! Efikasnost: "<<najefikasniji<<"%!"<<"\n\n\n";
    return 0;
}
