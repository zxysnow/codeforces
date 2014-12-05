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

const int MAX = 110;

string s[MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool used[30];

int solve(int n, int m, char c) {
	int x, y;
	int ans = 0;
	for(int i=0; i<n; i++)
		for(int k=0; k<m; k++)
			if( s[i][k] == c ) {
				for(int j=0; j<4; j++) {
					x = i + dx[j];
					y = k + dy[j];
					if( x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '.' 
							&& s[x][y] != c ) {
						if( !used[s[x][y] - 'A'] ) {
							ans++;
							used[s[x][y] - 'A'] = true;
						}
					}
				}
			}
	return ans;
}

int main() {
	int n, m;
	char clr;
	cin >> n >> m >> clr;
	for(int i=0; i<n; i++)
		cin >> s[i];

	int ans = solve(n, m, clr);
	cout << ans << endl;

	return 0;
}
