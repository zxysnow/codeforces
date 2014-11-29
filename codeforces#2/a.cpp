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
class NODE{
public:
	string name;
	int score;
};
NODE op[MAX];
map<string, int> name_map;
map<string, int> name_second;
int main() {
	int n;
	string name;
	int score;
	cin >> n;
	int id = 0;
	for(int i=0; i<n; i++) {
		cin >> name >> score;
		op[i].name = name;
		op[i].score = score;
		if( name_map.count(name) )
			name_map[name] += score;
		else 
			name_map.insert(make_pair(name, score));
	}

	int max_one = name_map[op[0].name];
	map<string, int>::iterator it;
	for(it = name_map.begin(); it != name_map.end(); it++) {
		if( it->second > max_one )
			max_one = it->second;
	}

	for(int i=0; i<n; i++) {
		name = op[i].name;
		score = op[i].score;
		if( name_second.count(name) )
			name_second[name] += score;
		else 
			name_second.insert(make_pair(name, score));
		if( name_second[name] >= max_one && name_map[name] == max_one ) {
			cout << name << endl;
			break;
		}
	}
	return 0;
}
