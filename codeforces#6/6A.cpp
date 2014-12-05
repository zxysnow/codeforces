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

int a[4];
int n = 4;

int triangle() {
	int tri = 0;
	int seg = 0;
	
	sort(a, a+4);
	for(int i=0; i<4; i++)
		for(int k=i+1; k<4; k++)
			for(int j=k+1; j<4; j++) {
				if( a[i] + a[k] > a[j] && a[k] - a[i] < a[j] )
					tri++;
				if( a[i] + a[k] == a[j] )
					seg++;
			}
	if( tri ) return 1;
	if( seg ) return 2;
	return 0;
}
int main() {
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int ans = triangle();
	if( ans == 1 ) {
		cout << "TRIANGLE" << endl;
	} else if( ans == 2 ) {
		cout << "SEGMENT" << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
