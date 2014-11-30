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
	char c1, c2;
	int r1, r2;
	cin >> c1 >> r1;
	cin >> c2 >> r2;
	int dx = abs(r1 - r2);
	int dy = abs(c1 - c2);
	int ld = min(dx, dy);
	int ans = ld + dx + dy - ld - ld;
	string step = "";
	if( c2 > c1 )
		step += 'R';
	else if( c2 < c1 )
		step += 'L';

	if( r2 < r1 )
		step += 'D';
	else if( r2 > r1 )
		step += 'U';

	cout << ans << endl;
	for(int i=0; i<ld; i++)
		cout << step << endl;

	if( dx == dy )
		return 0;

	step = "";
	if( dx < dy ) {
		if( c2 > c1 )
			step += 'R';
		else if( c2 < c1 )
			step += 'L';
	}
	if( dx > dy ) {
		if( r2 > r1 ) 
			step += 'U';
		else if( r2 < r1 )
			step += 'D';
	}
	for(int i=0; i<max(dx, dy) - ld; i++)
		cout << step << endl;
	return 0;
}
