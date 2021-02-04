#include <iostream>
#include "learner.cpp"
#include <sstream>

int main() {
    Learner learner;
    vector<string> words;
    for(int i = 0; i < 100000; i++) {
         words.push_back(to_string(i));
    }
    learner.Learn(words);
    cout << "lskdfa;lsdfkja;slkdfj";
    cout << "=== known words ===\n";

    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
}