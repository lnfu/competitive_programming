#include <bits/stdc++.h>

using namespace std;

int main() {
    set<pair<int, int>> st;
    st.insert({1, 2});
    cout << st.count({1, 2}) << endl;
    cout << st.count({1, 1}) << endl;
    cout << st.count({2, 2}) << endl;
    cout << st.count({3, 4}) << endl;
    return 0;
}