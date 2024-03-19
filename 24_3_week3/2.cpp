// 행운의 티켓 bj.1639
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	int max_len=0, mid=0, left, right, size;

	cin >> str;
	size = (int)str.size();
	while (mid < size - 1) {
		int temp_l=0, temp_r=0;
		left = mid;
		right = mid + 1;
		while (left >= 0 && right < size) {
			temp_l += str[left] - '0';
			temp_r += str[right] - '0';
			if (temp_l == temp_r)
				max_len = right - left + 1 > max_len ? right - left + 1 : max_len;
			left--;
			right++;
		}
		mid++;
	}
	cout << max_len;
	return (0);
}