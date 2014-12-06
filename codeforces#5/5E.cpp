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

const int MAX = 1000010;
vector<int> a;
int l[MAX];
int r[MAX];

long long solve(int n) {
	vector<int>::iterator highest = max_element(a.begin(), a.end());
	vector<int> num(highest, a.end());
	num.reserve(n);
	copy(a.begin(), highest, num.end());

	vector<int> left(n, -1);
	for(int i=1; i<n; i++) {
		int p = i - 1;
		while( num[i] > num[p] )
			p = left[p];
		if( num[i] == num[p] )
			left[i] = left[p];
		else
			left[i] = p;
	}

	vector<int> right(n, n);
	vector<int> same(n, 0);
	for(int i=n-2; i>=0; i--) {
		int p = i + 1;
		while( p < n && num[i] > num[p] )
			p = right[p];

		if(p >= n) {
			right[i] = p;
			continue;
		}

		if( num[i] == num[p] ) {
			right[i] = right[p];
			same[i] = same[p] + 1;
		} else {
			right[i] = p;
			same[i] = 0;
		}
	}

	long long ans = 0;
	for(int i=0; i<n; i++) {
		if( left[i] >= 0 )
			ans++;
		if( right[i] < n )
			ans++;
		if( right[i] >= n && left[i] > 0 )
			ans++;
		ans += same[i];
	}
	return ans;
}

int main() {
	int n;
	int tmp;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	
	cout << solve(n) << endl;

	return 0;
}
