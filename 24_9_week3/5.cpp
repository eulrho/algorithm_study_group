// 게으른 백곰 bj.10025
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_max_sum(int *bucket, int k, int min_x, int max_x)
{
	int left=min_x, right, res=0;

	while (left <= max_x) {
		right = left + 2 * k;
		if (right > max_x) right = max_x;

		int sum;
		if (left == 0) sum = bucket[right];
		else sum = bucket[right] - bucket[left-1];
		res = max(res, sum);
		left++;
	}
	return res;
}

int main()
{
	fast;
	int n, k, g, x, min_x=1000000, max_x=0;
	int bucket[1000001]={0,};

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> g >> x;
		bucket[x] = g;
		max_x = max(max_x, x);
		min_x = min(min_x, x);
	}
	for (int i=min_x; i<=max_x; i++) {
		if (i != 0) bucket[i] += bucket[i-1];
	}
	cout << find_max_sum(bucket, k, min_x, max_x);
	return (0);
}