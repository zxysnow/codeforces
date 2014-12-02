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
	string s;
	int ans = 0;
	int num = 0;
	while( getline(cin, s) ) {
		if( s[0] == '+' ) {
			num++;
			continue;
		} 
		if( s[0] == '-' ) {
			num--;
			continue;
		}
		ans += num * (s.length() - s.find_first_of(":") - 1);
	}
	cout << ans << endl;
	return 0;
}
