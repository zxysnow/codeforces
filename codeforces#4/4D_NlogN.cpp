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
			return h > tmp.h;
		return w < tmp.w;
	}
	bool operator==(const Card& tmp) const {
		return h == tmp.h && w == tmp.w;
	}
};
Card card[MAX];
int c[MAX];
int id[MAX];
int pre[MAX];
void print(int k) {
	if( k == -1 )
		return ;
	print( pre[k] );
	cout << card[k].id << ' ';
}

void DP(int n) {
	memset(pre, -1, sizeof(pre));
	int cn = 1;
	c[0] = card[0].h;
	id[0] = 0;
	for(int i=1; i<n; i++) {
		int h = card[i].h, pos;
		pos = upper_bound(c, c+cn, h) - c;
		if( pos >= 1 && c[pos-1] == h )
			continue;
		c[pos] = h;
		if( pos > 0 )
			pre[i] = id[pos-1];
		id[pos] = i;
		if( pos == cn )
			cn++;
	}
	cout << cn << endl;
	print( id[cn-1] );
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
	m = unique(card, card+m) - card;
	DP(m);


	return 0;
}
