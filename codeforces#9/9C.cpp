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

int n;
int ans;
void DFS(int x) {
	if( x > n )
		return ;
	ans++;
	DFS(x * 10);
	DFS(x * 10 + 1);
}
int main() {
	cin >> n;
	ans = 0;
	DFS(1);
	cout << ans << endl;

	return 0;
}
