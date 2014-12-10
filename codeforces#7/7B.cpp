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

const int MAX = 110;
int ops, n;
class Block {
	public:
		int pos;
		int size;
		bool exist;
		bool operator<(const Block& tmp) const {
			return pos < tmp.pos;
		}
};
vector<Block> free_block;
Block used[MAX];
int pos[MAX];
int find_free(int size) {
	int pos = MAX;
	int ind = MAX;
	for(int i=0; i<free_block.size() ;i++)
		if( free_block[i].size >= size && free_block[i].pos < pos ) {
			pos = free_block[i].pos;
			ind = i;
		}
	return ind;
}
void merge() {
	for(int i=0; i<free_block.size()-1; i++) {
		for(int k=i+1; k<free_block.size(); k++) {
			if( free_block[i].pos + free_block[i].size == free_block[k].pos ) {
				free_block[i].size += free_block[k].size;
				free_block.erase(free_block.begin() + k);
				break;
			}
			if( free_block[k].pos + free_block[k].size == free_block[i].pos ) {
				free_block[i].pos = free_block[k].pos;
				free_block[i].size += free_block[k].size;
				free_block.erase(free_block.begin() + k);
				break;
			}

		}
	}
}
int main() {
	int num, index = 0, fid = 1, uid = 0;
	string op;
	cin >> ops >> n;
	Block tmp;
	tmp.pos = 0;
	tmp.size = n;
	free_block.push_back( tmp );
	memset(pos, -1, sizeof(pos));
	while( ops-- ) {
		cin >> op;
		if( op[0] == 'a' ) {
			cin >> num;
			int ind = find_free(num);
			if( ind == MAX ) {
				cout << "NULL" << endl;
			} else {
				used[uid] = free_block[ind];
				used[uid].exist = true;
				used[uid].size = num;
				pos[used[uid].pos] = uid;
				if( free_block[ind].size - num > 0 ) {
					free_block[ind].size -= num;
					free_block[ind].pos = free_block[ind].pos + num;
				} else {
					free_block.erase(free_block.begin() + ind);
				}
				cout << ++uid << endl;
			}
		}
		if( op[0] == 'e' ) {
			cin >> num;
			num--;
			if( num >= 0 && num < uid && used[num].exist ) {
				used[num].exist = false;
				pos[used[num].pos] = -1;
				free_block.push_back( used[num] );
				merge();
			} else {
				cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
			}
		}
		if( op[0] == 'd' ) {
			int st = 0;
			int pp[MAX];
			memset(pp, -1, sizeof(pp));
			for(int i=0; i<n; i++) {
				if( pos[i] != -1 ) {
					int id = pos[i];
					used[id].pos = st;
					st += used[id].size;
					pp[used[id].pos] = id;
				}
			}
			memcpy(pos, pp, sizeof(pp));
			free_block.clear();
			tmp.pos = st;
			tmp.size = n - st;
			free_block.push_back( tmp );
		}
	}
	return 0;
}
