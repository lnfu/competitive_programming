// bytecoin happiness

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> priceGroup;
    priceGroup.reserve(N);
    for (int i = 0; i < N; i++) {
        int price;
        cin >> price;
        priceGroup.push_back(price);
    }

    long long originSum = 0;
    vector<int> diffGroup(N, 0);
    diffGroup.reserve(N);
    diffGroup[0] = 0;
    for (int i = 1; i < N; i++) {
        diffGroup[i] = priceGroup[i] - priceGroup[i-1];

        long long temp = ((long long)diffGroup[i])*((long long)diffGroup[i]);
        if (diffGroup[i] < 0)
            temp *= ((long long)diffGroup[i]);

        originSum += temp;
    }

    long long ans = LLONG_MIN;
    for (int i = 1; i < N - 1; i++) {
        long long sum = originSum;

        long long temp;

        temp = ((long long)diffGroup[i])*((long long)diffGroup[i]);
        if (diffGroup[i] < 0)
            temp *= ((long long)diffGroup[i]);
        sum -= temp;

        temp = ((long long)diffGroup[i+1])*((long long)diffGroup[i+1]);
        if (diffGroup[i+1] < 0)
            temp *= ((long long)diffGroup[i+1]);
        sum -= temp;

        long long newTemp = diffGroup[i] + diffGroup[i+1];
        if (newTemp < 0)
            newTemp = newTemp * newTemp * newTemp;
        else
            newTemp = newTemp * newTemp;
        sum += newTemp;
        
        if (sum > ans) {
            ans = sum;
        }
    }

    cout << ans << endl;

    return 0;
}