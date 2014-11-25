#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string s;

int to_digit(string s, int k) {
	int ans = 0;
	char c = 'A' - 1;
	if( k == 10 )
		c = '0';
	for(int i=0; i<s.size(); i++) {
		ans *= k;
		ans += (s[i] - c);
	}
	return ans;
}

string to26(int x) {
	string ans = "";
	
	while( x ) {
		int tmp = x % 26;
		if( tmp == 0 ) {
			ans += 'Z';
			x -= 26;
		} else
			ans += tmp - 1 + 'A';
		x /= 26;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string system1(string s) {
	int pos = s.find('C');
	string col = s.substr(pos+1);
	string row = s.substr(1, pos-1);
	int c = to_digit(col, 10);
	col = to26(c);
	return col + row;
}

string system2(string s) {
	string strset="0123456789";
	int pos = s.find_first_of(strset);
	string col = s.substr(0, pos);
	string row = s.substr(pos);
	int c = to_digit(col, 26);
	stringstream ss;
	ss << c;
	col = ss.str();
	return 'R' + row + 'C' + string(col);
}

bool is_system1(string s) {
	string strset="0123456789";
	int pos_digit = s.find_first_of(strset);
	int pos_alpha = s.find_last_not_of(strset);
	if( pos_alpha > pos_digit ) 
		return true;
	return false;
}
int main() {
	int n;

	cin >> n;

	while( n-- ) {
		cin >> s;
		if( is_system1(s) )
			cout << system1(s) << endl;
		else
			cout << system2(s) << endl;
	}

	return 0;
}

