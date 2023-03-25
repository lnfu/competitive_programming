#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> count(10, 0);

bool isHappy() {
    for (const auto& num : count) {
        if (num % 2 == 1)
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    for (const auto& c : s)
        count[c-'0']++;
    
    int ans = 0;
    int l = 0;
    int r = s.size() - 1;
    while (true) {
        ;
    }
    

    return 0;
}