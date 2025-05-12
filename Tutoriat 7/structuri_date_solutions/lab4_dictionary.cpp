#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string line;
    cout << "Introduceti cuvintele separate prin spatiu:\n";
    getline(cin, line);
    istringstream in(line);
    map<string,int> freq;
    string w;
    while (in >> w) {
        transform(w.begin(), w.end(), w.begin(), ::tolower);
        freq[w]++;
    }
    cout << "Dicționar (cuvant : frecventa):\n";
    for (auto& [cuv, cnt] : freq)
        cout << cuv << " : " << cnt << "\n";
    return 0;
}
