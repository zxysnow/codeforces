#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	int m, n, a;

	cin >> n >> m >> a;
	int x = n / a + ((n % a) + a - 1) / a;
	int y = m / a + ((m % a) + a - 1) / a;

	cout << x *1ll * y << endl;

	return 0;
}

