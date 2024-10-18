// 치킨 배달 bj.15686
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define CHICKEN(a, b, c, d) (abs(a-c)+abs(b-d));
int n, m;
int min_sum = -1;

int find_chicken_dist(pair<int, int> home, vector<pair<int, int> > &info, vector<pair<int, int> > &closed)
{
	int res = -1;
	for (int i=0; i<(int)info.size(); i++) {
		if (find(closed.begin(), closed.end(), info[i]) != closed.end()) continue ;

		int tmp = CHICKEN(home.first, home.second, info[i].first, info[i].second);
		if (res == -1) res = tmp;
		else res = min(res, tmp);
	}
	return res;
}

void find_min_dist(vector<pair<int, int> > &home, vector<pair<int, int> > &info, int idx, vector<pair<int, int> > &closed)
{
	if ((int)closed.size() == (int)info.size() - m) {
		int sum=0;
		for (int i=0; i<(int)home.size(); i++)
			sum += find_chicken_dist(home[i], info, closed);
		if (min_sum == -1) min_sum = sum;
		else min_sum = min(min_sum, sum);
		return ;
	}
	if (idx == (int)info.size()) return ;
	find_min_dist(home, info, idx+1, closed);
	closed.push_back(info[idx]);
	find_min_dist(home, info, idx+1, closed);
	closed.pop_back();
}

int main()
{
	fast;
	cin >> n >> m;

	int num;
	vector<pair<int, int> > home;
	vector<pair<int, int> > info;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> num;
			if (num == 1) home.push_back(make_pair(i, j));
			else if (num == 2) info.push_back(make_pair(i, j));
		}
	}

	vector<pair<int, int> > closed;
	find_min_dist(home, info, 0, closed);
	cout << min_sum;
	return 0;
}
