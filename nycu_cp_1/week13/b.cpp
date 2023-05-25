#include <bits/stdc++.h>
#define x first
#define y second
#define pdd pair<double, double>
#define sz(x) (x).size()

using namespace std;


double cross(pdd v1, pdd v2) {
	return v1.x*v2.y - v1.y*v2.x;
}

pdd diff(pdd p1, pdd p2) {
	return {p2.x - p1.x, p2.y - p1.y};
}

double area(pdd p1, pdd p2, pdd p3) {
	return cross(diff(p1, p2), diff(p1, p3));
}

int main() {
	int N; cin >> N;
	set<pdd> points;
	for (int i = 0; i < N; ++i) {
		double x, y; cin >> x >> y;
		points.insert({x, y});
	}

	// convex hull
	vector<pdd> convex;
	map<pdd, bool> used;
	auto iter = points.begin();
	for (; iter != points.end(); iter++) {
		auto curr = (*iter);
		while (sz(convex) >= 2 && 
			   area(convex[sz(convex)-2], convex[sz(convex)-1], curr) <= 0) {
			if (area(convex[sz(convex)-2], convex[sz(convex)-1], curr) < 0) {
				used[convex[sz(convex)-1]] = false;
			}
			convex.pop_back();
		}
		convex.push_back(curr);
		used[curr] = true;
	}

	used[*convex.begin()] = false; // 要繞回一圈才能確保是 convex hull!

	auto riter = points.rbegin();
	for (; riter != points.rend(); riter++) {
		auto curr = (*riter);
		if (used[curr])
			continue;

		while (sz(convex) >= 2 && 
			   area(convex[sz(convex)-2], convex[sz(convex)-1], curr) <= 0) {
			convex.pop_back();
		}
		convex.push_back(curr);
	}



	int n = sz(convex);
	double answer2 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int k = (i + 2) % n;
			while (area(convex[i], convex[j], convex[k]) <
				   area(convex[i], convex[j], convex[(k+1)%n]))
				k = (k + 1) % n;
			if (area(convex[i], convex[j], convex[k]) > answer2)
				answer2 = area(convex[i], convex[j], convex[k]);
		}
	}
	printf("%.5lf\n", answer2 / 2);

	return 0;
}




