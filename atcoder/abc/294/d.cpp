#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> status(N, 0); // not been called
    for (int i = 0; i < Q; i++) {
        int e;
        cin >> e;
        switch(e) {
            case 1:
                for (int j = 0; j < N; j++) {
                    if (status[j] == 0) {
                        status[j] = 1;
                        break;
                    }
                }
                break;
            case 2:
                int id;
                cin >> id;
                status[id-1] = 2;
                break;
            case 3:
                for (int j = 0; j < N; j++) {
                    if (status[j] == 1) {
                        cout << j + 1 << '\n';
                        break;
                    }
                }
                break;
        }
    }
    return 0;
}