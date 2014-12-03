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

const int MAX = 1010;
string s[MAX];

void print(char c, int n) {
	for(int i=0; i<n; i++)
		cout << c ;
}

int main() {
	int max_len = 0;
	int n = 0;
	bool left = true;
	while( getline(cin, s[n]) ) {
		if( s[n].length() > max_len )
			max_len = s[n].length();
		n++;
	}
	print('*', max_len + 2);
	cout << endl;
	for(int i=0; i<n; i++) {
		int len = s[i].length();
		int space = (max_len - len) / 2;
		if( (max_len - len) % 2 == 1 ) {
			if( !left )
				space++;
			left ^= 1;
		}
		print('*', 1);
		print(' ', space);
		cout << s[i];
		print(' ', max_len - len - space);
		print('*', 1);
		cout << endl;
	}
	print('*', max_len + 2);
	return 0;
}
