#include <bits/stdc++.h>
#define sz(x) (x).size()

using namespace std;

struct Point
{
	int x;
	int y;
};

bool operator<(const Point& p1, const Point& p2) {
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}


int cross(const Point& p1, const Point& p2, const Point& p3) {
	int dx1 = p2.x - p1.x;
	int dx2 = p3.x - p2.x;
	int dy1 = p2.y - p1.y;
	int dy2 = p3.y - p2.y;

	return dx1*dy2 - dx2*dy1;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (n == 0)
			break;

		set<Point> points;
		for (int i = 0; i < n; ++i) {
			Point p; cin >> p.x >> p.y;
			points.insert(p);
		}

		if (sz(points) < 3) {
			cout << sz(points) << '\n';
			for (const auto& p : points) {
				cout << p.x << ' ' << p.y << '\n';
			}
			continue;
		}


		vector<Point> convex1;
		set<Point>::iterator it;
		for (it = points.begin(); it != points.end(); ++it) {
			while (sz(convex1) > 1 
				&& cross(convex1[sz(convex1)-2], convex1[sz(convex1)-1], (*it)) <= 0) {
				convex1.pop_back();
			}
			convex1.push_back(*it);
		}

		vector<Point> convex2;
		auto rit = points.rbegin();
		for (; rit != points.rend(); ++rit) {
			while (sz(convex2) > 1
				&& cross(convex2[sz(convex2)-2], convex2[sz(convex2)-1], (*rit)) <= 0) {
				convex2.pop_back();
			}
			convex2.push_back(*rit);
		}


		cout << sz(convex1) + sz(convex2) - 2 << '\n';

		for (int i = 1; i < sz(convex1); ++i)
			cout << convex1[i].x << ' ' << convex1[i].y << '\n';

		// cout << "--\n";

		for (int i = 1; i < sz(convex2); ++i)
			cout << convex2[i].x << ' ' << convex2[i].y << '\n';

	}

	return 0;
}