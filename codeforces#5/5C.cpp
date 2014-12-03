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

const int MAX = 1000010;
string s;
stack<int> st;
int dp[MAX];
int main() {
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		if( s[i] == '(' ) {
			st.push(i+1);
		} else if( !st.empty() ) {
			int t = st.top();
			st.pop();
			dp[i+1] = dp[t-1] + i + 1 - t + 1;
		}
	}
	int max_len = 0;
	int num = 1;
	for(int i=1; i<=s.size(); i++)
		if( dp[i] > max_len) {
			max_len = dp[i];
			num = 1;
		} else if(dp[i] == max_len)
			num++;
	if( max_len == 0 )
		num = 1;
	cout << max_len << ' ' << num << endl;
	return 0;	
}
