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
class NODE {
public:
	int a[2];
};

NODE node[MAX][MAX];
int a2[MAX][MAX];
int a5[MAX][MAX];
void DP(int a[MAX][MAX], int n, int id) {
	a[0][0] = node[0][0].a[id];
	for(int i=1; i<n; i++) {
		a[0][i] = a[0][i-1] + node[0][i].a[id];
		a[i][0] = a[i-1][0] + node[i][0].a[id];
	}
	for(int i=1; i<n; i++)
		for(int k=1; k<n; k++) {
			int tmp1 = a[i][k-1] + node[i][k].a[id];
			int tmp2 = a[i-1][k] + node[i][k].a[id];
			a[i][k] = min(tmp1, tmp2);
		}
}
void split(int x, NODE& node) {
	int two = 0, five = 0;
	while( x % 2 == 0 && x != 0 ) {
		two++;
		x /= 2;
	}

	while( x % 5 == 0 && x != 0 ) {
		five++;
		x /= 5;
	}
	node.a[0] = two;
	node.a[1] = five;
}

string find_way(int least[MAX][MAX], int n, int id) {
	int i = n-1;
	int k = n-1;
	string step = "";
	while( i != 0 || k != 0 ) {
		int a = i-1;
		if( a >= 0 && least[i][k] == least[a][k] + node[i][k].a[id] ) {
			step += 'D';
			i = a;
			continue;
		}
		int b = k-1;
		if( b >= 0 && least[i][k] == least[i][b] + node[i][k].a[id] ) {
			step += 'R';
			k = b;
			continue;
		}
	}
	reverse(step.begin(), step.end());
	return step;
}
int cell[MAX][MAX];
int main() {
	int n, x;
	cin >> n;
	int posx = -1, posy = -1;
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++) {
			cin >> x;
			cell[i][k] = x;
			if( x == 0 && posx == -1) {
				posx = i;
				posy = k;
			}
			split(x, node[i][k]);
		}

	DP(a2, n, 0);
	DP(a5, n, 1);
	
	int ans = min(a2[n-1][n-1], a5[n-1][n-1]);

	if( posx >= 0 && ans >= 1 || cell[0][0] == 0 || cell[n-1][n-1] == 0 ) {
		cout << 1 << endl;
		for(int i=0; i<posx; i++)
			cout << 'D';
		for(int i=0; i<posy; i++)
			cout << 'R';
		for(int i=posx+1; i<n; i++)
			cout << 'D';
		for(int i=posy+1; i<n; i++)
			cout << 'R';
		return 0;
	}
	string step;
	
	if( ans == a2[n-1][n-1] )
		step = find_way(a2, n, 0);
	else 
		step = find_way(a5, n, 1);
	cout << ans << endl;
	cout << step << endl;


	return 0;
}
