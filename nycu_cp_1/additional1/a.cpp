#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, T; // 50, 500
    cin >> n >> T;
    vector<int> task_group;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp; // 100
        task_group.push_back(temp);
    }
    int sum = 0;
    int count = 0;
    for (const auto& task : task_group) {
        if (sum + task > T)
            break;
        sum += task;
        count++;
    }
    cout << count << endl;
    return 0;
}