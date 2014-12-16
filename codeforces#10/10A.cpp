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

class Time {
	public :
		int l, r;
};
const int MAX = 110;
Time t[MAX];

int main() {
	int n, p1, p2, p3, t1, t2;
	int ans = 0;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	for(int i=0; i<n; i++) {
		cin >> t[i].l >> t[i].r;
		ans += (t[i].r - t[i].l) * p1;
	}
	
	for(int i=1; i<n; i++) {
		int tmp = t[i].l - t[i-1].r;
		if( tmp > t1 ) {
			ans += p1 * t1;
			tmp -= t1;
		} else {
			ans += tmp * p1;
			continue;
		}
		if( tmp > t2 ) {
			ans += p2 * t2;
			tmp -= t2;
		} else {
			ans += tmp * p2;
			continue;
		}
		ans += tmp * p3;
	}
	cout << ans << endl;
	return 0;
}
