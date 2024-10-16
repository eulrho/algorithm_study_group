// 컨베이어 벨트 위의 로봇 bj.20055
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void check_range(int *number, int n)
{
	if (*number < 0) *number = 2 * n - 1;
	else if (*number >= 2 * n) *number = 0;
}

int main()
{
	fast;
	int n, k;
	cin >> n >> k;

	vector<pair<int, bool> > arr(2 * n);
	for (int i=0; i< 2 * n; i++) {
		cin >> arr[i].first;
		arr[i].second = false;
	}

	int input=0, output=n-1, step=1, cnt=0;
	while(true) {
		check_range(&(--input), n);
		check_range(&(--output), n);

		int i=output;
		while (i != input) {
			if (!arr[i].second) {
				check_range(&(--i), n);
				continue ;
			}

			int next = i + 1;
			check_range(&(next), n);
			if (i == output) arr[i].second = false;
			else if (arr[next].first > 0 && !arr[next].second) {
				arr[next].first--;
				if (arr[next].first == 0) cnt++;
				arr[next].second = true;
				arr[i].second = false;
			}
			check_range(&(--i), n);
		}
		if (arr[output].second) arr[output].second = false;
		
		if (arr[input].first != 0) {
			arr[input].first--;
			if (arr[input].first == 0) cnt++;
			arr[input].second = true;
		}

		if (cnt >= k) break ;
		step++;
	}
	cout << step;
	return 0;
}