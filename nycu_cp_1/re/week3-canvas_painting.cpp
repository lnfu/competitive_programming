#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;
        while (N--) {
            unsigned long long temp; cin >> temp;
            pq.push(temp);
        }

        unsigned long long count = 0;
        while (pq.size() > 1) {
            unsigned long long a = pq.top(); pq.pop();
            unsigned long long b = pq.top(); pq.pop();
            count += (a + b);
            pq.push(a + b);
        }

        cout << count << '\n';
    }
    return 0;
}