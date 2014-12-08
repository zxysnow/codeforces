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

const int MAX = 8;
string s[MAX];
int cal1(int n) {
	int ans = 0;
	for(int i=0; i<n; i++) {
		int flag = true;
		for(int k=0; k<n; k++)
			if( s[i][k] == 'W' )
				flag = false;
		if( flag )
			ans++;
	}
	return ans;
}

int cal2(int n) {
	int ans = 0;
	for(int i=0; i<n; i++) {
		int flag = true;
		for(int k=0; k<n; k++)
			if( s[k][i] == 'W' )
				flag = false;
		if( flag )
			ans++;
	}
	return ans;
}
int main() {
	int n = 8;
	for(int i=0; i<n; i++)
		cin >> s[i];

	int c = cal1(n), r = cal2(n);
	if( c == 8 && r == 8 )
		cout << 8 << endl;
	else
		cout << c + r << endl;

	return 0;
}
