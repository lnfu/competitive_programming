#include <bits/stdc++.h>

using namespace std;

set<int> candidate;
void backtrack(int current, int num, int count) {
    if (count >= 3)
        return;
    candidate.insert(current * 10 + num);

    vector<int> nextNums;
    switch(num) {
        case 1:
            nextNums.push_back(1);
            nextNums.push_back(2);
            nextNums.push_back(3);
            nextNums.push_back(4);
            nextNums.push_back(5);
            nextNums.push_back(6);
            nextNums.push_back(7);
            nextNums.push_back(8);
            nextNums.push_back(9);
            nextNums.push_back(0);
            break;
        case 2:
            nextNums.push_back(2);
            nextNums.push_back(5);
            nextNums.push_back(8);
            nextNums.push_back(0);
            nextNums.push_back(3);
            nextNums.push_back(6);
            nextNums.push_back(9);
            break;
        case 3:
            nextNums.push_back(3);
            nextNums.push_back(6);
            nextNums.push_back(9);
            break;
        case 4:
            nextNums.push_back(4);
            nextNums.push_back(5);
            nextNums.push_back(6);
            nextNums.push_back(7);
            nextNums.push_back(8);
            nextNums.push_back(9);
            nextNums.push_back(0);
            break;
        case 5:
            nextNums.push_back(5);
            nextNums.push_back(8);
            nextNums.push_back(0);
            nextNums.push_back(6);
            nextNums.push_back(9);
            break;
        case 6:
            nextNums.push_back(6);
            nextNums.push_back(9);
            break;
        case 7:
            nextNums.push_back(7);
            nextNums.push_back(8);
            nextNums.push_back(9);
            nextNums.push_back(0);
            break;
        case 8:
            nextNums.push_back(8);
            nextNums.push_back(9);
            nextNums.push_back(0);
            break;
        case 9:
            nextNums.push_back(9);
            break;
        case 0:
            nextNums.push_back(0);
            break;
    }

    for (const auto n : nextNums) {
        backtrack(current * 10 + num, n, count + 1);
    }

}

int main() {
    for (int i = 0; i <= 9; i++)
        backtrack(0, i, 0);

    for (const auto c : candidate)
        cout << c << endl;


    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        auto it = candidate.lower_bound(k);
        int a = *it;
        int b = *(--it);

        if (abs(a - k) < abs(b - k))
            cout << a << '\n';
        else
            cout << b << '\n';
    }
    return 0;
}