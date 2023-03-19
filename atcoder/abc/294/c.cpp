#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }

    vector<int> resultA;
    vector<int> resultB;
    int walkA = 0;
    int walkB = 0;
    int count = 1;
    while (walkA < A.size() && walkB < B.size()) {
        if (A[walkA] < B[walkB]) {
            resultA.push_back(count);
            walkA++;
        } else {
            resultB.push_back(count);
            walkB++;
        }

        count++;
    }
    while (walkA < A.size()) {
        resultA.push_back(count);
        count++;
        walkA++;
    }
    while (walkB < B.size()) {
        resultB.push_back(count);
        count++;
        walkB++;
    }

    for (const auto& r : resultA)
        cout << r << ' ';
    cout << endl;
    for (const auto& r : resultB)
        cout << r << ' ';
    cout << endl;

    return 0;
}