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

typedef pair<int,int> pii;
string str;
const int MAX = 210;
const int N = 100;
class STEP {
	public:
		int x, y, step;
};
bool m[MAX+10][MAX+10];
int c[MAX][MAX];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

queue< STEP  > q;
int BFS(int tx, int ty, int fx, int fy) {
	STEP s;
	s.x = tx; s.y = ty; s.step = 0;
	q.push( s );
	m[tx][ty] = false;
	while( !q.empty() ) {
		s = q.front();
		q.pop();
		int x = s.x, y = s.y;
		int step = s.step;
		if( x == fx && y == fy && step < str.size() )
			return true;
		if( x == fx && y == fy )
			continue;
		for(int i=0; i<4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if( m[xx][yy] ) {
				s.x = xx, s.y = yy;
				s.step = step + 1;
				q.push(s);
				m[xx][yy] = false;
			}
		}
	}
	return false;
}
bool solve() {
	int lr = 0;
	int ud = 0;
	m[N][N] = true;
	for(int i=0; i<str.size(); i++) {
		switch(str[i]) {
			case 'U' : ud++; break;
			case 'D' : ud--; break;
			case 'L' : lr++; break;
			case 'R' : lr--; break;
		}
		m[ud + N][lr + N] = true;
	}

	return BFS(N, N, ud+N, lr+N);
}
int main() {
	cin >> str;

	if( solve() )
		cout << "BUG" << endl;
	else
		cout << "OK" << endl;
	return 0;
}
