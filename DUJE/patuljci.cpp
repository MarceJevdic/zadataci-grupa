#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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
            int temp=0;
            for(int i=0;i<brzine.size();i++){
                if(brzine[0]>brzine[i]){
                    swap(brzine[0],brzine[i]);
                }
            }
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

    arr.minify(); // stavi najmanju brzinu na početak
    cout << "Najmanja brzina nakon minify: " << arr.front() << endl;

    return 0;
}
