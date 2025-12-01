/*Napišite klasu Student s privatnim članovima name, grades (vector ocjena). Implementirajte:
· void add_grade(int grade) - dodaje ocjenu
· double average() const - računa prosjek
· bool passed() const - provjerava je li prosjek >= 2.0
U main funkciji napravite vektor studenata i izbrojite koliko studenata je položilo.*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student{
    private:
        string name;
        vector<int> grades;
    public:
        Student(string ime,vector<int> ocjene){
            name=ime;
            grades=ocjene;
        }
        void add_grade(int grade){
            grades.push_back(grade);
        }
        double average() const{
            int prosjek=0;
            int brojac=0;
            for(int i=0;i<grades.size();i++){
                prosjek=prosjek+grades[i];
                brojac++;
            }
            return prosjek/brojac;
        }
        bool passed() const{
            if(average()>=2.0){
                return true;
            }
            else
                return false;
        }
};
int main(){
    vector<Student> studenti = {
        Student("Marko", {3, 4, 2}),
        Student("Ana", {1, 2, 1}),
        Student("Ivan", {5, 4, 5}),
        Student("Sara", {2, 2, 2})
    };
    int broj_polozili = 0;
    for(int i=0;i<studenti.size();i++){
        if(studenti[i].passed())
            broj_polozili++;
    }
    cout << "Broj studenata koji su položili: " << broj_polozili << endl;

    return 0;
}
