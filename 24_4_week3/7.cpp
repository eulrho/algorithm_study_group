// 개미굴 bj.14725
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(vector<string> &v1, vector<string> &v2)
{
	int v1_size = (int)v1.size(), v2_size = (int)v2.size();
	int size = v1_size < v2_size ? v1_size : v2_size;

	for (int i=0; i<size; i++) {
		if (v1[i] == v2[i]) continue ;
		else return (v1[i] < v2[i]);
	}
	return (false);
}

int main()
{
	fast;
	int n, food_cnt; cin >> n;
	vector<vector<string>> ant_tunnel(n);
	string food;
	string tmp[20] = {"", };

	for (int i=0; i<n; i++) {
		cin >> food_cnt;
		for (int j=0; j<food_cnt; j++) {
			cin >> food;
			ant_tunnel[i].push_back(food);
		}
	}
	sort(ant_tunnel.begin(), ant_tunnel.end(), cmp);
	for (int i=0; i<n; i++) {
		int bar = 0, size = (int)ant_tunnel[i].size();
		for (int j=0; j<size; j++) {
			if (tmp[j] == ant_tunnel[i][j]) bar++;
			else {
				fill(tmp + j, tmp + size, "");
				tmp[j] = ant_tunnel[i][j];
				for (int k=0; k<bar; k++) cout << "--";
				cout << ant_tunnel[i][j] << '\n';
				bar++;
			}
		}
	}
	return (0);
}