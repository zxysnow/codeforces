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

const int MAX = 5010;
class Card {
	public:
		int w, h;
		int id;
	bool operator <(const Card& tmp) const {
		if( w == tmp.w )
			return h < tmp.h;
		return w < tmp.w;
	}
};
Card card[MAX];
int dp[MAX];
int pre[MAX];

void print(int pos) {
	if( pos == -1 )
		return ;
	print(pre[pos]);
	cout << card[pos].id << ' ';
}

void DP(int n) {
	memset(pre, -1, sizeof(pre));
	for(int i=0; i<n; i++)
		dp[i] = 1;
	for(int i=1; i<n; i++) {
		int w = card[i].w;
		int h = card[i].h;
		for(int k=0; k<i; k++)
			if( dp[i] < dp[k] + 1 && card[k].w < w && card[k].h < h ) {
				dp[i] = dp[k] + 1;
				pre[i] = k;
			}
	}
	int ans = 1, pos = 0;
	for(int i=0; i<n; i++)
		if( ans < dp[i] )
			ans = dp[pos = i];
	cout << ans << endl;
	print(pos);	
}

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	int m = 0, tw, th;
	for(int i=0; i<n; i++) {
		cin >> tw >> th;
		if( tw > w && th > h ) {
			card[m].w = tw;
			card[m].h = th;
			card[m].id = i + 1;
			m++;
		}
	}
	if( m == 0 ) {
		cout << "0" << endl;
		return 0;
	}

	sort(card, card+m);
	
	DP(m);


	return 0;
}
