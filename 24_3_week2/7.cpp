// 다이어트 bj.1484
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<int> arr;
int arr_size;

void find_cur_w(int g, vector<int> &cur_w)
{
	int left=0, right=1, temp;

	while (right < arr_size) {
		temp = arr[left] + arr[right];
		if (temp % 2 == 0) {
			if ((arr[left] - arr[right]) != 0)
				cur_w.push_back(temp / 2);
		}
		left += 2; right += 2;
	}
	if (cur_w.empty()) cur_w.push_back(-1);
}

int main()
{
	fast;
	int g;
	vector<int> cur_w;

	cin >> g;
	for (int i=1; i<=g/i; i++) {
		if (g % i == 0 && find(arr.begin(), arr.end(), i) == arr.end()) {
			arr.push_back(i);
			arr.push_back(g / i);
		}
	}
	arr_size = arr.size();
	find_cur_w(g, cur_w);
	sort(cur_w.begin(), cur_w.end());
	for (int i=0; i<cur_w.size(); i++) cout << cur_w[i] << '\n';
	return (0);
}