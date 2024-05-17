// 투에-모스 문자열 bj.18222
#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char number[2] = {'0', '1'};
int is_reversal;

void find_k_character(long long k, int lv)
{
	long long last_idx = (long long)pow(2, lv);

	if (k <= 2) {
		cout << number[(k - 1 + is_reversal) % 2];
		return ;
	}
	if (last_idx < k) {
		find_k_character(k, lv + 1);
		return ;
	}
	if (last_idx == k)
		cout << number[(lv + is_reversal) % 2];
	else
	{
		is_reversal^=1;
		find_k_character(k - (long long)pow(2, lv-1), 1);
	}
}

int main()
{
	fast;
	long long k;

	cin >> k;
	find_k_character(k, 1);
	return (0);
}