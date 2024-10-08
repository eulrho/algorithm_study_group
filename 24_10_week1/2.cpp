// 중량제한 bj.1939
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_pair(int a, int b, vector<vector<pair<int, int> > > &bridge)
{
	for (int j=0; j<(int)bridge[a].size(); j++) {
		if (bridge[a][j].first == b) {
			return j;
		}
	}
	return -1;
}

int find_limit(int n, vector<vector<pair<int, int> > > &bridge, int start, int end)
{
	vector<int> weight(n+1, -1);
	bool visited[10001] = {false};

	visited[start] = true;
	weight[start] = 0;
	for (int j=0; j<(int)bridge[start].size(); j++) {
		weight[bridge[start][j].first] = bridge[start][j].second;
	}

	int current;
	for (int i=1; i<n; i++) {
		int value=-1;
		for (int j=1; j<=n; j++) {
			if (visited[j] == false && weight[j] > value) {
				current = j;
				value = weight[j];
			}
		}

		visited[current] = true;
		for (int j=0; j<(int)bridge[current].size(); j++) {
			if (visited[bridge[current][j].first] == false) {
				int tmp = min(bridge[current][j].second, value);
				weight[bridge[current][j].first] = max(weight[bridge[current][j].first], tmp);
			}
		}
	}
	return weight[end];
}

int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > bridge(n+1);

	int a, b, c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		int tmp = find_pair(a, b, bridge);
		if (tmp == -1)
		{
			bridge[a].push_back(make_pair(b, c));
			bridge[b].push_back(make_pair(a, c));
		}
		else {
			bridge[a][tmp].second = max(bridge[a][tmp].second, c);
			tmp = find_pair(b, a, bridge);
			bridge[b][tmp].second = max(bridge[b][tmp].second, c);
		}
	}

	int start, end;
	cin >> start >> end;

	cout << find_limit(n, bridge, start, end);
	return 0;
}