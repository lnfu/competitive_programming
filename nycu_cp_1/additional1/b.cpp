#include <bits/stdc++.h>

using namespace std;

int main() {
    string flag;
    int day = 0;
    while (cin >> flag) {
        if (flag == "OPEN") {
            day++;
            map<string, int> enter_time;
            map<string, int> price;

            while (cin >> flag) {
                if (flag == "CLOSE") {
                    // print results
                    cout << "DAY " << day << '\n';
                    for (const auto& [key, value] : price) {
                        cout << key << " $" << value / 10 << '.' << value % 10 << "0\n";
                    }
                    cout << '\n';
                    break;
                }

                // main
                if (flag == "ENTER") {
                    string name;
                    int time;
                    cin >> name >> time;
                    enter_time[name] = time;
                }

                if (flag == "EXIT") {
                    string name;
                    int time;
                    cin >> name >> time;
                    price[name] += (time - enter_time[name]);
                }
            }
        }
    }
    return 0;
}