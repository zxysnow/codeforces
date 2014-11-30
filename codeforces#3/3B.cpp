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
class lorry {
	public :
		int id;
		int v;
	bool operator<(const lorry& a) const{
		return v > a.v;
	}
};

vector<lorry> v1;
vector<lorry> v2;
int f1[MAX];
int f2[MAX];

void solve(int v) {
	for(int i=1; i<v1.size()+1; i++)
		f1[i] = f1[i-1] + v1[i-1].v;
	for(int i=1; i<v2.size()+1; i++)
		f2[i] = f2[i-1] + v2[i-1].v;

	int ans = 0;
	int n1 = 0, n2 = 0;
	for(int i=0; i<=min((int)v2.size(), v/2); i++) {
		int p = min((int)v1.size(), v - 2*i);
		int c = f2[i] + f1[p];
		if( c > ans ) {
			ans = c;
			n1 = p;
			n2 = i;
		}
	}
	cout << ans << endl;
	for(int i=0; i<n1; i++)
		cout << v1[i].id << ' ';
	for(int i=0; i<n2; i++)
		cout << v2[i].id << ' ';
}
int main() {
	int n, v;
	cin >> n >> v;
	for(int i=1; i<=n; i++) {
		int type;
		lorry tmp;
		tmp.id = i;
		cin >> type >> tmp.v;
		if( type == 1 )
			v1.push_back( tmp );
		else
			v2.push_back( tmp );
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	solve(v);

	return 0;
}
