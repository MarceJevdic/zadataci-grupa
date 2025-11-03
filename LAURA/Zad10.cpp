#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/* Napišite funkciju koja u rečenici nakon svakog samoglasnika doda slovo ’p’ i sam samoglasnik. Koristite funkcije STL-a find, insert.
  "Ja sam dobro"-> "Japa sapam dopobropo" */
// ne radi nikako a ni chat ga ne zna napravit
void funkcija(string& s) {
   auto it = s.begin();
   while(it != s.end()) {
       it = find_if(it, s.end(), [](char c){
           return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                  c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
       });

       if(it != s.end()){
           char samoglasnik=*it;
           it=s.insert(it+1,'p');
           ++it;
           it=s.insert(it +1,samoglasnik);
           ++it;
       }
       else break;
   }
   cout << s << endl;
}

int main() {
   string s = "Ja sam dobro";
   funkcija(s);
   return 0;
}
