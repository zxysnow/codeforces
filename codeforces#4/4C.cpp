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

map<string, int > name;

int main() {
	int n;
	string s;
	cin >> n;
	while( n-- ) {
		cin >> s;
		if( name.count(s) == 0 ) {
			name[s] = 1;
			cout << "OK" << endl;
		} else {
			cout << s << name[s] << endl;
			name[s]++;
		}
	}

	return 0;
}
