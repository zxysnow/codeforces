#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;


class point {
	public:
		double x, y;
};
class circle {
	public:
		point c;
		double r;
};

const double eps = 1e-6;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
double disp2p(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cost(circle *c, point p) {
	double ang[3];
	for(int i=0; i<3; i++)
		ang[i] = disp2p(c[i].c, p) / c[i].r;
	double rst = 0;
	for(int i=0; i<3; i++) {
		double diff = ang[i] - ang[(i+1)%3];
		rst += diff * diff;
	}
	return rst;	
}

int main() {
	circle c[3];
	for(int i=0; i<3; i++)
		cin >> c[i].c.x >> c[i].c.y >> c[i].r;
	
	point ans;
	double x = 0, y = 0;
	for(int i=0; i<3; i++) {
		x += c[i].c.x;
		y += c[i].c.y;
	}
	ans.x = x / 3;
	ans.y = y / 3;
	double step = 1;
	double err = cost(c, ans);
	for(int i=0; i<1000000; i++) {
		if( err <= eps )
			break;
		bool flag = false;
		for(int k=0; k<4; k++) {
			point tmp;
			tmp.x = ans.x + step * dx[k];
			tmp.y = ans.y + step * dy[k];

			double cc = cost(c, tmp);
			if( err > cc ) {
				err = cc;
				ans = tmp;
				flag = true;
			}
		}
		if( !flag )
			step /= 2;
	}
	
	if( cost(c, ans) <= eps )
		cout << fixed << setprecision(5) << ans.x << ' ' << ans.y << endl;


	return 0;
}
