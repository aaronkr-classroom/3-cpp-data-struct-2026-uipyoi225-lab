#include <iostream>
#include <string>
#include <vector>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

int main() {
    vector<string> words;
    string x;

   
    while (cin >> x) {
        words.push_back(x);
    }

    typedef vector<string>::size_type vec_sz;
    vec_sz size = words.size();

    if (size == 0) return 1;

    
    string::size_type minlen = words.size();
    string::size_type maxlen = words.size();

    for (vec_sz i = 1; i < size; ++i) {
        
        if (words[i].size() < minlen) {
            minlen = words[i].size();
        }
 
        if (words[i].size() > maxlen) {
            maxlen = words[i].size();
        }
    }

   
    cout << minlen << endl;
    cout << maxlen << endl;

    return 0;
}