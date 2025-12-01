#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Patuljak{
private:
    string ime;
    int brzina;
public:
    Patuljak(string ime, int brzina){
        this->ime=ime;
        this->brzina=brzina;
    }
    int get_brzina() const{
        return brzina;
    }
    void set_brzina(int nova){
        brzina = nova;
    }
};

class MinArray{
private:
    vector<int> brzine;
public:
    void push(int value){
        brzine.push_back(value);
    }
    int front() const{
        int najmanji=brzine[0];
        for(int i=0;i<brzine.size();i++){
            if(najmanji>brzine[i]){
                najmanji=brzine[i];
            }
        }
        return najmanji;
    }
    void minify(){
        for(int i=0;i<brzine.size();i++){
            if(brzine[0]>brzine[i]){
                swap(brzine[0],brzine[i]);
            }
        }
    }
    size_t size() const{
        return brzine.size();
    }
    vector<int>& get_vector(){
        return brzine;
    }
};

int main() {
    vector<Patuljak> patuljci = {
        {"Srecko", 6}, {"Ljutko", 4}, {"Stidljivko", 3},
        {"Pospanko", 5}, {"Kihavko", 2}, {"Glupko", 7},
        {"Uco", 1}
    };

    MinArray arr;
    for (const auto& p : patuljci) {
        arr.push(p.get_brzina());
    }

    for(int krug=1; krug<=3; krug++){
        arr.minify();
        cout << "Krug " << krug << ": Najsporija brzina = " << arr.front() << endl;
        int nova;
        cout << "Unesite novu brzinu najsporijeg patuljka: ";
        cin >> nova;
        arr.get_vector()[0] = nova;
    }
    arr.minify();
    cout<<"najsporija brzina nakon utrke: "<<arr.front();

    return 0;
}

