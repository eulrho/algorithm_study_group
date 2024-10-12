// 숨바꼭질 3 bj.13549
#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_min_sec(int n, int k)
{
	int tmp;
	if (n <= k) tmp = 2 * k;
	else tmp = n;

	int arr[tmp + 1], visited[tmp + 1];
	for (int i=0; i<tmp+1; i++) {
		arr[i] = -1;
		visited[i] = 0;
	}
	arr[n] = 0;

	int target;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, n});
	while (!pq.empty()) {
		target = pq.top().second;
		pq.pop();

		if (visited[target] == 1) continue ;
		visited[target] = 1;
		if (target * 2 <= tmp && (arr[target * 2] == -1 || arr[target] < arr[target * 2])) {
			arr[target * 2] = arr[target];
			pq.push({arr[target * 2], target * 2});
		}
		if (target < k && (arr[target + 1] == -1 || arr[target] + 1 < arr[target + 1])) {
			arr[target + 1] = arr[target] + 1;
			pq.push({arr[target + 1], target + 1});
		}
		if (target > 0 && (arr[target - 1] == -1 || arr[target] + 1 < arr[target - 1])) {
			arr[target - 1] = arr[target] + 1;
			pq.push({arr[target - 1], target - 1});
		}
	}
	return arr[k];
}

int main()
{
	fast;
	int n, k;
	cin >> n >> k;

	cout << find_min_sec(n, k);
	return (0);
}