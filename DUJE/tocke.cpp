#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Point{
    private:
        double x;
        double y;
    public:
        Point(double x,double y){
            this->x=x;
            this->y=y;
        }
        double distance_to_origin() const{
            return sqrt(x*x+y*y);
        }
        int compare(const Point& other) const{
            double t1=distance_to_origin();
            double t2=other.distance_to_origin();
            if(t1>t2) return 1;
            else if(t1<t2) return -1;
            else return 0;
        }
        double get_x() const { return x; }
        double get_y() const { return y; }

};
int main(){
    vector<Point> tocke{
        Point(1.2,4.3),
        Point(3.3,2.2),
        Point(1.8,6.7),
        Point(1.1,2.9)
    };
    Point najbliza=tocke[0];
    for(auto& s : tocke){
        if(s.compare(najbliza)==-1){
            najbliza=s; 
        }
    }
    cout<<"Tocka najbliza ishodistu: ("<<najbliza.get_x()<<","<<najbliza.get_y()<<")"<<endl<<endl;
    sort(tocke.begin(),tocke.end(),[](const Point& p1,const Point& p2){
        return p1.distance_to_origin()<p2.distance_to_origin();
    });
    cout<<"Tocke sortirane po udaljenosti od ishodista: "<<endl;
    for(auto& f : tocke){
        cout<<endl;
        cout << "(" << f.get_x() << ", " << f.get_y() << ")" << endl;
    }

    return 0;
}
