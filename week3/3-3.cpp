#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;     using std::cout;
using std::endl;    using std::sort;
using std::string;  using std::vector;

int main() {
    vector<string> words;
    string x;

    while (cin >> x) {
        words.push_back(x);
    }

    typedef vector<string>::size_type vec_sz;
    vec_sz size = words.size();

    if (size == 0) {
        return 1;
    }

   
    sort(words.begin(), words.end());

 
    int count = 1;

  
    for (vec_sz i = 1; i < size; ++i) {
        if (words[i] == words[i - 1]) { 
            ++count;
        }
        else {
          
            cout << words[i - 1] << " " << count << endl;
            count = 1;
        }
    }
    
    cout << words[size - 1] << " " << count << endl;

    return 0;
}

