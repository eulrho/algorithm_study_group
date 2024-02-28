// 친구 bj.1058
#include <iostream>
#include <string>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void find_friends(string humans[], int idx, int *cnt)
{
	int visited[51] = {0, };
	queue<int> queue;
	int number;

	visited[idx] = 1;
	for (int k=0; k<humans[idx].size(); k++) {
		if (humans[idx][k] == 'Y' && visited[k] == 0) {
			queue.push(k);
			visited[k] = 1;
			(*cnt)++;
		}
	}
	while (!queue.empty()) {
		number = queue.front();
		queue.pop();
		for (int k=0; k<humans[number].size(); k++) {
			if (humans[number][k] == 'Y' && visited[k] == 0) {
				visited[k] = 1;
				(*cnt)++;
			}
		}
	}
}

int main()
{
	fast;
	int n; cin >> n;
	int max=0;
	string humans[n];

	for (int i=0; i<n; i++)
		cin >> humans[i];
	for (int i=0; i<n; i++) {
		int cnt = 0;

		find_friends(humans, i, &cnt);
		max = max < cnt ? cnt : max;
	}
	cout << max;
	return (0);
}