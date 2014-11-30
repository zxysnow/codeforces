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

string s[3];
const int n = 3;

bool win(char c) {
	bool win = false;
	for(int i=0; i<n; i++) {
		if( s[i][0] == c && s[i][0] == s[i][1] && s[i][1] == s[i][2] )
			return true;
	}
	for(int i=0; i<n; i++) {
		if( s[0][i] == c && s[0][i] == s[1][i] && s[1][i] == s[2][i] )
			return true;
	}
	if( s[0][0] == c && s[1][1] == c && s[2][2] == c )
		return true;
	if( s[0][2] == c && s[1][1] == c && s[2][0] == c )
		return true;
	return false;
}
int main() {
	int x = 0, o = 0;
	for(int i=0; i<n; i++) {
		cin >> s[i];
		for(int k=0; k<s[i].size(); k++) {
			switch( s[i][k] ) {
				case '0' : o++; break;
				case 'X' : x++; break;
			}
		}

	}
	if( o > x || abs(x - o) >= 2 ) {
		cout << "illegal" << endl;
		return 0;
	}
	if( win('0') && win('X') ) {
		cout << "illegal" << endl;
		return 0;
	}
	if( win('0') ) {
		if( x > o ) {
			cout << "illegal" << endl;
			return 0;
		}
		cout << "the second player won" << endl;
		return 0;
	}
	if( win('X') ) {
		if( x == o ) {
			cout << "illegal" << endl;
			return 0;
		}
		cout << "the first player won" << endl;
		return 0;
	}
	if( o + x == 9 ) {
		cout << "draw" << endl;
		return 0;
	}

	if( o == x ) {
		cout << "first" << endl;
	} else {
		cout << "second" << endl;
	}

	return 0;
}
