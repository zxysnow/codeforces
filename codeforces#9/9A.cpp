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

int main() {
    int w,y,dot;
	cin >> y >> w ;
    int x = y > w ? y : w;
    int pos = 0;
    for(int i=6; i>=x; i--)
    	pos++;
    switch(pos)
    {
		case 0 : cout << "0/1"; break;
		case 1 : cout << "1/6"; break;
		case 2 : cout << "1/3"; break;
		case 3 : cout << "1/2"; break;
		case 4 : cout << "2/3"; break;
		case 5 : cout << "5/6"; break;
		case 6 : cout << "1/1"; break;
	}
	return 0;
}
