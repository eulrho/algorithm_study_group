// 대표값2 bj.2587
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int numbers[5], sum=0;

	for (int i=0; i<5; i++)
	{
		cin >> numbers[i];
		sum += numbers[i];
	}
	sort(numbers, numbers + 5);
	cout << sum/5 << '\n' << numbers[2];
	return (0);
}