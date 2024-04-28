// 육회비빔밥 bj.30971
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, k, a[10], b[10], c[10];
int max_taste = -1;

bool is_included(int idx, int *seq, int right)
{
	for (int i=0; i<=right; i++) {
		if (seq[i] == idx) return (true);
	}
	return (false);
}

void find_max(int *seq, int right, int taste)
{
	int new_taste;

	if (right == n - 1) {
		max_taste = max_taste < taste ? taste : max_taste;
		return ;
	}
	if (right == -1) {
		for (int i=0; i<n; i++) {
			seq[right + 1] = i;
			find_max(seq, right + 1, 0);
		}
	}
	else {
		for (int i=0; i<n; i++) {
			if (!is_included(i, seq, right)) {
				if (c[seq[right]] * c[i] <= k) {
					seq[right + 1] = i;
					new_taste = taste + a[seq[right]] * b[i];
					find_max(seq, right + 1, new_taste);
				}
			}
		}
	}
}

int main()
{
	fast;
	cin >> n >> k; int seq[n];
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	for (int i=0; i<n; i++) cin >> c[i];
	find_max(seq, -1, 0);
	cout << max_taste;
	return (0);
}


