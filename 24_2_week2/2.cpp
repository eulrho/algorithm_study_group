// 쉽게 푸는 문제 bj.1292
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_target_end_point(int target)
{
	int sum = 0;

	for (int i=1; i<=target; i++)
		sum += i;
	return (sum);
}

int find_target(int position)
{
	int i, sum = 1;

	for (i=1; i<=45; i++)
	{
		if (sum <= position && sum + i > position)
			break ;
		sum += i;
	}
	return (i);
}

int	sum_seq(int start, int end)
{
	int res, temp;
	int t_start, t_end;

	t_start = find_target(start);
	t_end = find_target(end);
	temp = find_target_end_point(t_start);
	if (end == temp)
		res = (temp - start + 1) * t_start;
	else if (end > temp)
	{
		res = (temp - start + 1) * t_start;
		for (int i = t_start + 1; i <= t_end; i++)
		{
			if (i != t_end)
				res += i * i;
			else
				res += i * (end - find_target_end_point(i - 1));
		}
	}
	else
		res = t_start * (end - start + 1);
	return (res);
}

int main()
{
	fast;
	int start, end;

	cin >> start >> end;
	cout << sum_seq(start, end);
	return (0);
}