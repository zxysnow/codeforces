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
	string s, a, b;
	bool atob = false, btoa = false;
	int ans = 0;
	cin >> s >> a >> b;
	int pos = s.find(a);
	if( pos != -1 && (int)s.find(b, pos + a.length()) != -1 )
			atob = true;
	
	reverse(s.begin(), s.end());
	pos = s.find(a);
	if( pos != -1 && (int)s.find(b, pos + a.length()) != -1  )
		btoa = true;

	if( atob && btoa ) 
		cout << "both" << endl;
	else if( atob )
		cout << "forward" << endl;
	else if( btoa )
		cout << "backward" << endl;
	else
		cout << "fantasy" << endl;

	return 0;
}
