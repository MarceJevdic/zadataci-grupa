#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*Napišite klasu Student s privatnim članovima name, grades (vector ocjena). Implementirajte:
 · void add_grade(int grade) - dodaje ocjenu
 · double average() const - računa prosjek
 · bool passed() const - provjerava je li prosjek >= 2.0
 U main funkciji napravite vektor studenata i izbrojite koliko studenata je položilo.*/
class Student{
private:
    string name;
    vector<int>ocjene;
public:
    Student(string s, vector<int>o){
        name=s;
        ocjene=o;
    }
    void add_grade(int ocjena){
        ocjene.push_back(ocjena);
    }
    double average()const{
        double zbroj=0.0;
        for (int i : ocjene){
            zbroj+=i;
        }
        return (zbroj/ocjene.size());
    }
    bool passed()const{
        double prosjek=average();
        return(prosjek>=2.0);
    }
};
int main(){
    vector<Student>studenti={
        Student ("Ana",{1,2,4}),
        Student ("Luka",{2,3,4}),
        Student ("Laura",{1,1,1})
    };
    
    int brojac=0;
    for(Student s : studenti){
        if(s.passed()){
            brojac++;
        }
    }
    cout<<"Broj studenata koji su polozili: "<<brojac<<endl;;
    
    return 0;
}
