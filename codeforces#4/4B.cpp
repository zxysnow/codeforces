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

const int MAX = 35;
int mint[MAX], maxt[MAX];
int ans[MAX];
int main() {
	int d, sum;
	int sum_min = 0, sum_max = 0;
	cin >> d >> sum;
	for(int i=0; i<d; i++) {
		cin >> mint[i] >> maxt[i];
		sum_min += mint[i];
		sum_max += maxt[i];
	}

	if( sum < sum_min || sum > sum_max ) {
		cout << "NO" << endl;
		return 0;
	}
	
	memcpy(ans, mint, sizeof(mint));
	sum -= sum_min;
	int i = 0;
	while( sum ) {
		int t = min(sum, maxt[i] - ans[i]);
		ans[i] += t;
		sum -= t;
		i++;
	}
	cout << "YES" << endl;
	for(int i=0; i<d; i++)
		cout << ans[i] << ' ';

	return 0;
}
