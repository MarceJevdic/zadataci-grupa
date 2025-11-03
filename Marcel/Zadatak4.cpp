#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*Napišite funkciju koja provjerava je li jedna rečenica palindrom (ignoriraju se praznine
i znakovi interpunkcije).
*/

void funkcija(string& recenica) {
	string novi;
	
	auto it = remove_if(recenica.begin(), recenica.end(), [](char c) {
		return (ispunct(c) || c == ' ');
		});

	recenica.erase(it, recenica.end());
	novi = recenica;

	reverse(novi.begin(), novi.end());

	if (novi == recenica) {
		cout << "palindrom je";
	}
	else {
		cout << "nije palindrom";
	}
	


}


int main() {
	string recenica = "Marko . okraM";
	funkcija(recenica);

	return 0;
}