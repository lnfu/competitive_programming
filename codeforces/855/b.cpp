#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<char, int> count;
        int ans = 0;
        while (n--) {
            char c;
            cin >> c;
            if (isupper(c) && count[tolower(c)] > 0) {
                ans++;
                count[tolower(c)]--;
                continue;
            } 
            if (islower(c) && count[toupper(c)] > 0) {
                ans++;
                count[toupper(c)]--;
                continue;
            }
            count[c]++;
        }
        int curr = 'A';
        while (k--) {
            if (curr > 'Z') {
                break;
            }
            if (count[curr] >= 2) {
                ans++;
                count[curr] -= 2;
                continue;
            }
            if (count[curr+32] >= 2) {
                ans++;
                count[curr+32] -= 2;
                continue;
            }
            curr++;
            k++;
        }
        cout << ans << endl;
    }
    return 0;
}