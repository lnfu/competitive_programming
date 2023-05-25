#include <bits/stdc++.h>
#define N 200005

using namespace std;

struct node{
    int bg, ed;
};

bool cmp(node a , node b){            //按照结束时间排序
    if(a.ed== b.ed) return a.bg < b.bg;
    return a.ed< b.ed;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    // struct node a[n];
    vector<node> a(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> a[i].bg >> a[i].ed;

    sort(a.begin(), a.end(), cmp);
    multiset<int> endtime;         //h存放每个教室正在进行的活动的结束时间
    // endtime.clear();
    int ans = 0;
    for (int i = 0 ; i < n ; ++i){
        auto iter = endtime.lower_bound(-a[i].bg);          //是否存在某个教室的活动在i开始时间前前就结束了
        if (iter == endtime.end()){                  //如果没有在活动i开始前就结束活动的教室，就另找一个教室
            if (endtime.size() < k){
                endtime.insert(-a[i].ed- 1);
                ++ans;
            }
            continue;
        }
        endtime.erase(iter);                    //找到了某个教室活动已经结束了，活动i在这个教室进行
        endtime.insert( - a[i].ed - 1);      //更新活动的结束时间
        ++ans;
    }
    cout << ans << '\n';
}
