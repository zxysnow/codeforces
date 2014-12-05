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

const int MAX = 100010;
int t[MAX];
int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> t[i];

	int a = 0, b = n-1;
	int sa = t[0], sb = t[n-1];
	while( a < b - 1 ) {
		if( sa <= sb ) {
			a++;
			sa += t[a];
			continue;
		}
		b--;
		sb += t[b];
	}
	cout << a + 1 << ' ' << n - a - 1 << endl;

	return 0;
}
