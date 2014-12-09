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

const int MAX = 30;
const int INF = INT_MAX;
const int M = 16;
int n, a, b;
int dp[MAX][MAX][MAX];
int x[MAX][MAX][MAX], y[MAX][MAX][MAX];
int v[MAX];

void print(int dep, int a, int b) {
	if( dep == 1 )
		return ;
	int aa = x[dep][a][b], bb = y[dep][a][b];
	print(dep - 1, aa, bb);
	for(int i=0; i<dp[dep][a][b] - dp[dep-1][aa][bb]; i++)
		cout << dep << ' ';
}

int main() {
	cin >> n >> a >> b;
	for(int i=0; i<n; i++)
		cin >> v[i], v[i]++;

	for(int i=0; i<=n; i++)
		for(int k=0; k<=M; k++)
			for(int j=0; j<=M; j++)
				dp[i][k][j] = INF;
	dp[1][v[0]][v[1]] = 0;
	for(int i=1; i<n-1; i++) {
		for(int k=0; k<=v[i-1]; k++) {
			for(int j=0; j<=v[i]; j++) {
				if( dp[i][k][j] == INF )
					continue;
				int from = (k + b - 1) / b;
				int to = max(from, max((j + a - 1) / a,  (v[i+1] + b - 1) / b));
				for(int hit=from; hit<=to; hit++) {
					int p1 = max(0, j - a * hit);
					int p2 = max(0, v[i+1] - b * hit);
					if( dp[i+1][p1][p2] > dp[i][k][j] + hit ) {
						dp[i+1][p1][p2] = dp[i][k][j] + hit;
						x[i+1][p1][p2] = k;
						y[i+1][p1][p2] = j;
					}
				}
			}
		}
	}
	cout << dp[n-1][0][0] << endl;
	print(n-1, 0, 0);
	return 0;
}

