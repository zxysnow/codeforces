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

const int MAX = 100010;
struct Tnode{				// 一维线段树 
    int l,r;
	int vmax, vmin;
    int len() { return r - l;}
    int mid() { return MID(l,r);}
    bool in(int ll,int rr) { return l >= ll && r <= rr; }
    void lr(int ll,int rr){ l = ll; r = rr;}
};
Tnode node[MAX<<2];
int a[MAX];
void Update(int t)
{
	node[t].vmax = max(node[L(t)].vmax, node[R(t)].vmax);
	node[t].vmin = min(node[L(t)].vmin, node[R(t)].vmin);
}
void Build(int t,int l,int r)
{
	node[t].lr(l,r);
	if( node[t].len() == 1 )
	{
		node[t].vmax = node[t].vmin = a[l];
		return ;
	}
	int mid = MID(l,r);
	Build(L(t),l,mid);
	Build(R(t),mid,r);
	Update(t);
}

pair<int,int> Query(int t,int l,int r)
{
	if( node[t].in(l,r) ) {
		return make_pair(node[t].vmin, node[t].vmax);
	}
	int mid = node[t].mid();
	pair<int, int> a1, a2, ans;
	int cnt = 0;
	if( l < mid ) {
		cnt++;
		a1 = ans = Query(L(t),l,r);
	}
	if( r > mid ) {
		a2 = Query(R(t),l,r);
		if( cnt == 1 )
			ans = make_pair(min(ans.first, a2.first), max(ans.second, a2.second));
		else
			ans = a2;
	}
	return ans;
}

int get_max(int i, int n, int k, int& pos) {
	int l = i, r = n;
	while( l < r - 1) {
		int mid = MID(l ,r);
		pair<int, int> tmp = Query(1, i, mid + 1);
		if( abs(tmp.first - tmp.second) <= k )
			l = mid;
		else
			r = mid;
	}
	pos = i;
	return (l - i + 1);
	
}
int ans[MAX];
void solve(int n, int m) {
	int maxv = 0;
	int num = 0;
	for(int i=0; i<n; i++) {
		int pos;
		int tmp = get_max(i, n, m, pos);
		if( tmp > maxv ) {
			maxv = tmp;
			num = 0;
			ans[num++] = pos;
		} else if( tmp == maxv ) {
			ans[num++] = pos;
		}
	}
	
	cout << maxv << ' ' << num << endl;
	for(int i=0; i<num; i++)
		cout << ans[i] + 1 << ' ' << ans[i] + maxv << endl;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> a[i];

	Build(1, 0, n);

	solve(n, m);

	return 0;
}
