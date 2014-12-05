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

int main() {
	int a[4];
	for(int i=0; i<4; i++)
		cin >> a[i];
	sort(a, a+4);
	int ans = min(a[3] - a[2] - a[1], a[2] - a[1] - a[0]);
	if( ans < 0 )
		cout << "TRIANGLE";
	if( ans == 0 )
		cout << "SEGMENT";
	if( ans > 0 )
		cout << "IMPOSSIBLE";

	return 0;
}
