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


long long egcd(long long a, long long b, long long &x, long long &y) {
	long long d;
	if( b == 0 ) {
		x = 1ll;
		y = 0ll;
		return a;
	} else {
		d = egcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
}
int main() {
	long long a, b, c;
	long long x, y;
	
	cin >> a >> b >> c;

	long long g = egcd(a, b, x, y);
	if( c % g == 0 )
		cout << x * (-c / g) << ' ' << y * (-c / g);
	else
		cout << -1 << endl;
	return 0;
}

