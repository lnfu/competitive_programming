#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> prev(4, 0);
    double min_time = 21.0;
    double max_time = 0.0;
    double accu_time = 0.0;


    for (int i = 0; i < 4; i++) {
        double temp;
        cin >> temp;
        prev[i] = temp;
        if (temp < min_time)
            min_time = temp;
        if (temp > max_time)
            max_time = temp;
        accu_time += temp;
    }
    double t;
    cin >> t;

    double possible = t * 3 + min_time + max_time -  accu_time;
    if (accu_time - min_time <= t * 3)
        cout << "infinite";
    else if (possible >= min_time) {
        cout << possible;
    }
    else
        cout << "imposible";

    return 0;
}