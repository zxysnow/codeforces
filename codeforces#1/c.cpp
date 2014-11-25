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
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

struct point{
	double x, y;
	void input(){
		cin >> x >> y;
	}
};
point a, b, c;

double disp2p(point a,point b)    
{
	return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
double  circumcir_r(point ap,point bp,point cp)
{
	double a,b,c;
	a = disp2p(ap,bp); b = disp2p(bp,cp); c = disp2p(cp,ap);
	return a*b*c/sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
}
const double pi = acos(-1.0);
const double eps = 1e-4;
bool check( double a ){
	return fabs(a - floor(a + eps)) < eps;
}
int main()
{
	a.input();
	b.input();
	c.input();
	
	double r = circumcir_r(a, b, c);
	double aa = disp2p(a, b);
	double bb = disp2p(b, c);
	double cc = disp2p(a, c);
	double ang;
	double A = 2 * asin(aa/(2*r));
	double B = 2 * asin(bb/(2*r));
	double C = 2 * asin(cc/(2*r));
	
	int i = 3;
	for(i=3; i<=100; i++){
		ang = 2*pi / i;
		if( check(A/ang) && check(B/ang) && check(C/ang) )
			break;
	}
	
	double ans = i * 0.5 * r * r * sin(ang);
	cout << fixed << setprecision(10) << ans << endl;
	
return 0;
}
