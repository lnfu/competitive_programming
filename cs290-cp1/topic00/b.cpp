// volleyball scoring

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        int serve = 0; // 0 for A; 1 for B
        int A = 0;
        int B = 0;
        bool end = false;
        cout << "Match " << i + 1 << ": ";
        for (int j = 0; j < S; j++) {
            char temp;
            cin >> temp;
            if (temp == 'A' && serve == 0)
                A++;
            
            if (temp == 'B' && serve == 1)
                B++;

            if (!end && A >= 15 && A - B >= 2) {
                cout << "Team A has won the match with a score of "
                     << A << "-" << B << ".\n";
                end = true;
            }

            if (!end && B >= 15 && B - A >= 2) {
                cout << "Team B has won the match with a score of "
                     << A << "-" << B << ".\n";
                end = true;
            }
            
            serve = (temp == 'A' ? 0 : 1);
        }

        if (!end)
            cout << "The score is " << A << "-" << B << ".\n";
        
    }
    return 0;
}