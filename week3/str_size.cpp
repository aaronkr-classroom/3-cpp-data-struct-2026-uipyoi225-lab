#include<iostream>
#include<string>

using namespace std;
int main(void) {
	cout << "enter all words, thenEOF";
	string word;
	string max = "";
	string min = "";
	while (cin >> word) {
		if (min.size() == 0)min = word;
		if (max.size() == 0)max = word;

		if (word.size() < min.size())min = word;
		else if (word.size() > max.size())max = word;
	}
	cout << "min word: " << min << "size: " << min.size() << endl <<
		"max word: " << max << "size: " << max.size() << endl;

	return 0;
}