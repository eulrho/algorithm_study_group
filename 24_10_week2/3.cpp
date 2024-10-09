// 지름길 bj.1446
#include <iostream>
#include <vector>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct way {
	int start, end, distance;

	way(int start, int end, int distance) {
		this->start = start;
		this->end = end;
		this->distance = distance;
	}
};

int main()
{
	fast;
	int n, d;
	cin >> n >> d;

	int s, e, len;
	vector<way> info;
	for (int i=0; i<n; i++) {
		cin >> s >> e >> len;
		info.push_back(way(s, e, len));
	}
	
	map<int, int> pos;
	for (int i=0; i<n; i++) {
		pos[info[i].start] = d;
		pos[info[i].end] = d;
	}
	pos[0] = 0;
	pos[d] = d;
	
	int front = 0;
	for (map<int, int>::iterator iter=++(pos.begin()); iter != pos.end(); iter++) {
		int tmp = iter->first - front + pos[front];

		for (int i=0; i<n; i++) {
			if (info[i].end != iter->first) continue ;
			tmp = min(info[i].distance + pos[info[i].start], tmp);
		}
		iter->second = min(tmp, iter->second);
		front = iter->first;
	}
	cout << pos[d];
	return 0;
}
