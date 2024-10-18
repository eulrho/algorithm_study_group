// 캡틴 이다솜 bj.1660
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void set_tetrahedron(vector<int> &tetrahedron, int n)
{
	tetrahedron.push_back(1);
	int depth = 2, tmp = 1;
	while (true) {
		tmp += depth;
		tetrahedron.push_back(tetrahedron.back() + tmp);
		if (tetrahedron.back() > n) break ;
		depth++;
	}
}

int main()
{
	fast;
	int n;
	cin >> n;

	vector<int> tetrahedron;
	set_tetrahedron(tetrahedron, n);
	int arr[n+1];
	for (int i=0; i<=n; i++) arr[i] = 0;
	for (int i=1; i<=n; i++) {
		if (find(tetrahedron.begin(), tetrahedron.end(), i) != tetrahedron.end())
			arr[i] = 1;
		else {
			int tmp = arr[i - 1] + 1;
			for (int j=(int)tetrahedron.size() - 1; j>=0; j--) {
				if (tetrahedron[j] > i) continue ;
				tmp = min(arr[i - tetrahedron[j]] + 1, tmp);
			}
			arr[i] = tmp;
		}
	}
	cout << arr[n];
	return 0;
}