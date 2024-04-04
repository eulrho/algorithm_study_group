// 절댓값 힙 bj.11286
#include <iostream>
#include <cmath>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int numbers[200010];
int h_size=1;

bool cmp(int p, int c)
{
	if (abs(numbers[p]) > abs(numbers[c])) return (false);
	if (abs(numbers[p]) == abs(numbers[c]) && numbers[p] > numbers[c]) return (false);
	return (true);
}

void push_heap(int x)
{
	numbers[h_size++] = x;
	if (h_size == 2) return ;
	for (int i=h_size - 1; i>1; i /= 2) {
		if (!cmp(i / 2, i)) swap(numbers[i / 2], numbers[i]);
		else break ;
	}
}

int pop_heap()
{
	int res, child;

	if (h_size == 1) return (0);
	res = numbers[1];
	numbers[1] = numbers[h_size - 1];
	h_size--;
	if (h_size != 2) {
		for (int i = 1; 2 * i < h_size - 1;) {
			child = 2 * i;
			if (child < h_size - 1 && !cmp(child, child + 1)) child++;
			if (!cmp(i, child)) swap(numbers[i], numbers[child]);
			i = child;
		}
	}
	return(res);
}

int main()
{
	fast;
	int n, x;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x != 0) push_heap(x);
		else cout << pop_heap() << '\n';
	}
	return (0);
}