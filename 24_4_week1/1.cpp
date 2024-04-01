// 최소 힙 bj.1927
#include <iostream>
#include <queue>
#include <functional>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> num;
		if (num != 0) pq.push(num);
		else {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return (0);
}