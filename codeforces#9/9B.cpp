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

double sx,sy,vb,vs;
double compute(double x,double y)
{
	return sqrt((x - sx)*(x - sx) + sy*sy)/vs;
}
int main(void)
{
    int n;
    double x[101],t[101];
    cin >> n >> vb >> vs;
    for(int i=1; i<=n; i++)
    	cin >> x[i];
    cin >> sx >> sy;
	for(int i=1; i<=n; i++)
		t[i] = x[i]/vb + compute(x[i],0);
	double min = t[2];
	int pos = 2;
	for(int i=2; i<=n; i++)
		if( t[i] <= min )
		{
			pos = i;
			min = t[i];
		}
	cout << pos ;
    return 0;
}
