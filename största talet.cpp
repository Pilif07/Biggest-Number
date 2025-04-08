#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

void biggestNum(vector<vector<char>> vec) {
	bool modified;

	do {
		modified = false; //om modified är false i slutet av while-loopen har ingenting ändrats och därför kan den brytas

		for (int arrNumber = 0; arrNumber < vec.size() - 1; arrNumber++) {	
			int index = 0;
			bool doNotSwap = false;	//kollar om två tal har bytt platts eller inte

			while (index < vec[arrNumber].size() || index < vec[arrNumber + 1].size()) {

				if (vec[arrNumber].size() > index && vec[arrNumber + 1].size() > index && vec[arrNumber][index] != vec[arrNumber + 1][index]) {
					if (vec[arrNumber][index] < vec[arrNumber + 1][index]) {
						vec[arrNumber].swap(vec[arrNumber + 1]);
						modified = doNotSwap = true;
					}
					else doNotSwap = true;
				}
				if (doNotSwap == false && vec[arrNumber].size() - 1 == index && vec[arrNumber].size() > vec[arrNumber + 1].size()) {
					for (int i = index; i < vec[arrNumber].size(); i++) {	//går genom värden för arr[arrNumber] men börjar på index-värdet
						for (int u = 0; u < vec[arrNumber + 1].size(); u++) {	//går genom värden för arr[arrNumber + 1]
							if (vec[arrNumber][i] < vec[arrNumber + 1][u]) {
								vec[arrNumber].swap(vec[arrNumber + 1]);
								modified = doNotSwap = true;
								i = vec[arrNumber].size();
								break;
							}
							else if (vec[arrNumber][i] > vec[arrNumber + 1][u]) { //för att kunna bryta de nesslade looparna och för att programmet inte ska byta platts på talen
								doNotSwap = true;
								i = vec[arrNumber].size();
								break;
							}
						}
					}
				}
				if (doNotSwap == false && vec[arrNumber].size() - 1 == index && vec[arrNumber].size() < vec[arrNumber + 1].size()) {
					for (int i = index; i < vec[arrNumber + 1].size(); i++) {	//går genom värden för arr[arrNumber + 1] men börjar på index-värdet
						for (int u = 0; u < vec[arrNumber].size(); u++) {	//går genom värden för arr[arrNumber]
							if (vec[arrNumber][u] < vec[arrNumber + 1][i]) {
								vec[arrNumber].swap(vec[arrNumber + 1]);
								modified = doNotSwap = true;
								i = vec[arrNumber + 1].size();
								break;
							}
							else if (vec[arrNumber][u] > vec[arrNumber + 1][i]) {
								doNotSwap = true;
								i = vec[arrNumber + 1].size();
								break;
							}
						}
					}
				}
				if (doNotSwap == true) {
					break;
				}
				if ((index < vec[arrNumber].size() && index < vec[arrNumber + 1].size()) && vec[arrNumber][index] == vec[arrNumber + 1][index]) index++;
				else break;
			}
		}
	} while (modified == true);

	for (int i = 0; i < vec.size(); i++) {	//skriver ut det färdiga talet
		for (int walla = 0; walla < vec[i].size(); walla++) {
			cout << vec[i][walla];
		}
		cout << ' ';//för att göra det lätt att dubbelkolla om det stämmer. ta bort för att sätta ihop
	}
}

int main() {
	cout << "skriv in dina ord/tal med enter efter varje och skriv 'stopp' när du är klar:" << endl;
	int numOfInputs = 0;
	vector<vector<char>> twoDVec;
	while (true) {
		string inputText;
		cin >> inputText;
		if (inputText == "stopp") {
			cout << endl << "du matade in '" << numOfInputs << "' tal. " << endl;
			break;
		}
		int numberLength = 0;
		twoDVec.push_back({}); //
		for (char c : inputText) {
			twoDVec[numOfInputs].push_back(inputText[numberLength]);
			numberLength++;
		}
		numOfInputs++;
	}
	biggestNum(twoDVec);
	return 0;	
}
