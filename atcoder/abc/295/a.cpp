#include <string>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        if (str == "and" || str == "not" || str == "that" || str == "the" || str == "you") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}