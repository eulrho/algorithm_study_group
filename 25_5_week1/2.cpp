// 배열 제어하기
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

vector<int> solution(vector<int> arr) {
	sort(arr.begin(), arr.end(), cmp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	return arr;
}

int main()
{
	fast;
//	vector<int> arr = {4, 2, 2, 1, 3, 4};
	vector<int> arr = {2, 1, 1, 3, 2, 5, 4};
	vector<int> res = solution(arr);
	for (auto r : res) cout << r << '\n';
	return (0);
}