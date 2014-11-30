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

string s;
const int MAX = 5 * 10010;
class Cost {
	public:
		int lc, rc;
};

Cost cost[MAX];
typedef pair<int, int> pii;
priority_queue< pii > q;

bool solve(int n) {
	int id = 0;
	long long sum = 0;
	int now = 0;
	for(int i=0; i<s.size(); i++) {
		if( s[i] == '(' )
			now++;
		else
			now--;
		if( s[i] == '?' ) {
			s[i] = ')';
			sum += cost[id].rc;
			q.push(make_pair(cost[id].rc - cost[id].lc, i));
			id++;
		}
		if( now < 0 ) {
			if( q.empty() )
				return false;
			pii tmp = q.top();
			q.pop();
			s[tmp.second] = '(';
			sum -= tmp.first;
			now += 2;
		}
	}
	if( now != 0 )
		return false;
	cout << sum << endl << s << endl;
	return true;
}
int main() {
	cin >> s;
	int now = 0;
	int c1, c2;
	int id = 0;
	while( cin >> cost[id].lc >> cost[id].rc ) {
		id++;
	}
	if( !solve(id) )
		cout << "-1" << endl;
	return 0;
}
