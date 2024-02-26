// 핸드폰 번호 궁합 bj.17202
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string num1, num2;
	int idx_1=0, idx_2=0;
	int arr[17] = {0, };

	cin >> num1 >> num2;
	for (int i=1; i<=16; i++) {
		if (i % 2 == 1) arr[i] = num1[idx_1++] - '0';
		else arr[i] = num2[idx_2++] - '0';
	}
	for (int i=16; i>=3; i--) {
		for (int j=1; j<i; j++)
			arr[j] = (arr[j + 1] + arr[j]) % 10;
	}
	cout << arr[1] << arr[2];
	return (0);
}