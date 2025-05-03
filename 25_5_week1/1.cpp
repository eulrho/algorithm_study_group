// 배열 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<int> solution(vector<int> arr) {
	sort(arr.begin(), arr.end());
	return arr;
}

int main()
{
	fast;
	vector<int> arr = {6, 1, 7};
//	vector<int> arr = {1, -5, 2, 4, 3};
//	vector<int> arr = {2, 1, 1, 3, 2, 5, 4};
	vector<int> res = solution(arr);
	for (auto r : res) cout << r << '\n';
	return (0);
}