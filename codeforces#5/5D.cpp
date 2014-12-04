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

double a, v, l, d, w;

void print(double x) {
	cout << fixed << setprecision(5) << x << endl;
}
//按照只有一个上限v来
void solve1() {
	double t = v / a;
	double len = 0.5 * a * t * t;
	if( len > l ) {
		print( sqrt(2 * l / a) );
	} else {
		print( t + (l - len) / v );
	}
}

double cal(double w, double x) {
	double t = (v - w) / a;
	double len = w * t + 0.5 * a * t * t;
	if( len > x )
		return (-w + sqrt(w * w + 2 * a * x))/a;
	return t + (x - len) / v;
}
//v > w;
void solve2() {
	double t = w / a;
	double len = 0.5 * a * t * t;
	if( len > l ) {
		print( sqrt(2 * l / a) );
		return ;
	}
	//到d的时候速度还没超过w
	if( len >= d ) {
		print( cal(0, l) );
		return ;
	}

	//到d之前速度已经超过w了
	//先升到v，匀速一会儿再降到w，过了w，再加速啊加速。。。
	t = v / a;
	double t2 = (v - w) / a;
	len = 0.5 * a * t * t;
	len += w * t2 + 0.5 * a * t2 * t2;

	//升速 + 降速，还不到d，说明中间要匀速啦
	if( len <= d ) {
		print( t + t2 + (d - len) / v + cal(w, l - d)  );
		return ;
	}

	//升速 + 降速，大于d啦，说明升不到速度为v就要降啦
	//一定是等于d的时候降到w，中间没有匀速的时期

	t = w / a;
	double x = 0.5 * a * t * t - d;
	t2 = ( -2 * w + sqrt( (2 * w) * (2 * w) - 4 * a * x) ) * 0.5 / a;
	t2 *= 2;
	double vv = a * (t + 0.5 * t2 );

	print( t + t2 + cal(w, l - d) );
}

int main() {
	cin >> a >> v >> l >> d >> w;

	if( v <= w ) {
		solve1();
	} else {
		solve2();
	}

	return 0;
}

