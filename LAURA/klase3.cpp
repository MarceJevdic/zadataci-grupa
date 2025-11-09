#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*Napišite klasu Temperature koja predstavlja temperaturu. Klasa treba imati privatni
 član celsius koji sprema temperaturu u Celzijevim stupnjevima. Klasa može imati privatni član za ime, ako želimo nekoj temperaturi dati ime (ne moramo).
 (a) Implementirajte funkciju to_fahrenheit() koja pretvara temperaturu iz Celzijusa u
 Fahrenheit. Formula: F = C × 9/5 + 32
 (b) Implementirajte funkciju to_kelvin() koja pretvara temperaturu iz Celzijusa u Kelvin. Formula: K = C + 273.15
 (c) Implementirajte funkciju set_from_fahrenheit() koja postavlja temperaturu na temelju vrijednosti Fahrenheita. Formula: C = (F - 32) × 5/9
 (d) Implementirajte funkciju set_from_kelvin() koja postavlja temperaturu na temelju
 vrijednosti Kelvina. Formula: C = K - 273.15
 (e) Implementirajte funkciju print_all_scales() koja ispisuje temperaturu u sva tri
 sustava.*/
class Temperature{
private:
    double celsius;
public:
    
    Temperature(double c){
        celsius=c;
    }
    
    double to_fahrenheit()const{
        double F;
        F= celsius * 9.0/5.0 + 32;
        return F;
    }
    
    double to_kelvin()const{
        double K = celsius + 273.15;
        return K;
    }
    
    double set_from_fahrenheit(double F){
        celsius = (F - 32) * 5/9;
        return celsius;
    }
    
    double set_from_kelvin(double K){
        celsius = K - 273.15;
        return celsius;
    }
    void print_all_scales()const{
        double F= to_fahrenheit();
        double K=to_kelvin();
        cout<<"Temp i celzijusima: "<<celsius<<endl;
        cout<<"Temp u F: "<<F<<endl;
        cout<<"Temp u K: "<<K<<endl;
    }
};
int main(){
    Temperature t1(25);
    t1.print_all_scales();
    Temperature t2(40);
    t2.print_all_scales();
    
    return 0;
}
