// 3 --> 1 3
// 4 --> 2 4 1 3 --> V
// 
// 5 --> 1 4 2 5 3 --> V
// 6 --> 1 4 2 5 3 6 
// 
// 7 --> 1 5 2 6 3 7 4
// 8 --> 1 5 2 6 3 7 4 8
// 
// 9 --> 1 6 2 7 3 8 4 9 5
// 10
// 
// 取 /2 + 2 和 /2

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    if (n == 4) {
        cout << "2 4 1 3";
        return 0;
    }

    int num = 1;
    for (int i = 0; i < n; i++) {
        cout << num << ' ';
        if (i % 2 == 0) num += ((n+1)/2);
        else num -= ((n+1)/2 - 1);
    }
    return 0;
}




