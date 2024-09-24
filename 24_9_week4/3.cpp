// 영화감독 숌 bj.1436
#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, step=0, number=666;
	cin >> n;

	while (true) {
		string tmp = to_string(number);
		number++;
		if (tmp.find("666") == string::npos) continue ;

		step++;
		if (step == n) {
			cout << tmp;
			break ;
		}
	}
	return (0);
}
