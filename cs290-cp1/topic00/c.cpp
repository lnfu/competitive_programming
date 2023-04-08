// oh, craps

#include <bits/stdc++.h>

using namespace std;

int main() {
    int count = 0;
    while (true) {
        int n;
        vector<int> seq;
        while (cin >> n) {
            if (n == 0)
                break;
            seq.push_back(n);
        }
        if (seq.size() == 0)
            break;
        count++;
        cout << "Sequence " << count << ": ";


        // 7, 11
        // 2, 3, 12
        // 4, 5, 6, 8, 9, 10
        int score = 0;
        for (int i = 0; i < seq.size(); i++) {
            switch(seq[i]) {
                case 7:
                case 11:
                    score++;
                    break;
                case 2:
                case 3:
                case 12:
                    score--;
                    break;
                case 4:
                case 5:
                case 6:
                case 8:
                case 9:
                case 10:
                    for (int j = i + 1; j < seq.size(); j++) {
                        if (seq[j] == 7) {
                            score--;
                            break;
                        }
                        if (seq[j] == seq[i]) {
                            score++;
                            break;
                        }
                    }
            }
        }
        if (score == 0)
            cout << "Break even.\n";
        if (score > 0)
            cout << "Win of $" << score << ".\n";
        if (score < 0)
            cout << "Loss of $" << score << ".\n";
    }
    return 0;
}