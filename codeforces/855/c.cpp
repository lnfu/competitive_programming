// unfinished
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    vector<pair<int, vector<int>>>calculate;
    vector<int>bonus;
    int hero = 0;
    bool status = true;
    for (int i = n - 1; i >= 0; i--) {
        if (input[i] == 0) {
            if (status) {
                hero++;
            } else {
                calculate.push_back({hero, bonus});
                hero = 0;
                bonus.clear();
            }
        } else {
            status = false;
            bonus.push_back(input[i]);
        }
    }
    calculate.push_back({hero, bonus});
    hero = 0;
    bonus.clear();

    for (const auto& [a, b] : calculate) {
        cout << a << ": ";
        for (const auto& bb : b) {
            cout << bb << ' ';
        }
        cout << endl;
    }

    return 0;
}