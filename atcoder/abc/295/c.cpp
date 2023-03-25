#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    map<int, int> sock;
    int ans = 0;
    cin >> N;
    while (N--) {
        int temp;
        cin >> temp;
        if (sock[temp] > 0) {
            sock[temp]--;
            ans++;
        } else {
            sock[temp]++;
        }
    }
    cout << ans << endl;
    return 0;
}