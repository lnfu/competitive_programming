#include <bits/stdc++.h>

using namespace std;

long long fib[100001] = {0};

char judge(long long N, long long K) {
    if (N == 1)
        return 'N';
    if (N == 2)
        return 'A';

    if (K > fib[N - 2])
        return judge(N - 1, K - fib[N - 2]);
    else
        return judge(N - 2, K);
}

int main() {
    long long N, K;
    cin >> N >> K;
    fib[1] = 1;
    fib[2] = 1;
    if (N > 92) {
        N = 92;
    }
    for (int i = 3; i <= N; i++)
        fib[i] = fib[i-2] + fib[i-1];
    
    cout << judge(N, K) << endl;
    
    return 0;
}

// N, A, NA, ANA, NA ANA
// ANA NAANA, NAANA ANANAANA