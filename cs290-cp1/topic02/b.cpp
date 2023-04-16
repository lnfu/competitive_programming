// affine names

#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> affine;

    int n; cin >> n;

    int count = 0;
    while (n--) {
        string a, b, c; cin >> a >> b >> c;
        transform(a.begin(), a.end(), a.begin(), ::toupper);
        transform(b.begin(), b.end(), b.begin(), ::toupper);
        transform(c.begin(), c.end(), c.begin(), ::toupper);

        string a1 = a.substr(0, 1);
        string b1 = b.substr(0, 1);
        string c1 = c.substr(0, 1);

        string a3 = a.substr(0, 3);
        string b3 = b.substr(0, 3);
        string c3 = c.substr(0, 3);

        string s1 = a1 + b1 + c1 + a3;
        string s2 = a1 + b1 + c1 + b3;
        string s3 = a1 + b1 + c1 + c3;

        count += affine[a3 + a1 + b1 + c1];
        if (a3 != b3)
            count += affine[b3 + a1 + b1 + c1];
        if (a3 != c3 && b3 != c3)
            count += affine[c3 + a1 + b1 + c1];
        
        affine[s1]++;
        if (a3 != b3)
            affine[s2]++;
        if (a3 != c3 && b3 != c3)
            affine[s3]++;
    }

    cout << count << endl;

    return 0;
}