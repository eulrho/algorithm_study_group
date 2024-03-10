// 전쟁 - 땅따먹기 bj.1270
#include <iostream>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, t, end;
	long long soldier_no;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		end = 0;
		map<long long, int> land = map<long long, int> ();
		for (int j=0; j<t; j++) {
			cin >> soldier_no;
			if (land.find(soldier_no) == land.end())
				land.insert({soldier_no, 1});
			else land[soldier_no]++;
		}
		for (auto iter : land) {
			if (iter.second > t / 2) {
				cout << iter.first << '\n';
				end = 1;
				break ;
			}
		}
		if (end == 0) cout << "SYJKGW\n";
	}
	return (0);
}
