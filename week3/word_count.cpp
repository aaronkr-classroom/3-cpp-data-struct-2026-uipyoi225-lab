#include <algorithm>
#include <ios>
#include <iostream>
#include<string>
#include <vector>

using namespace std;
int main(void) {
	cout << "enter all worlds, then EOF:";
	vector<string>words;

	string word;
	while (cin >> word) {
		words.push_back(word);
	}
	//{word:count} Ãâ·Â
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << ":" <<
			count(words.begin(), words.end(), words[i]) << endl;

	}
	cout << "words: " << words.size();
	return 0;
}