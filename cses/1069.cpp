#include <iostream>
#include <string>

using namespace std;

int main() {
    char prevChar = ' ';
    int curr = 1;
    int ans = 0;
    string input;
    cin >> input;
    for (const auto& c : input) {
        if (c == prevChar)
            curr++;
        else
            curr = 1;

        if (curr > ans)
            ans = curr;

        prevChar = c;
    }
    cout << ans;
    return 0;
}