// 사탕 게임 bj.3085
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[2] = {0, 1};
int dx[2] = {1, 0};

int down(string candies[], int i, int j, int n)
{
	int count=0;

	for (int k=0; k<n; k++) {
		if (i + k >= n) break ;
		if (candies[i][j] != candies[i + k][j]) break ;
		count++;
	}
	return (count);
}

int right(string candies[], int i, int j, int n)
{
	int count=0;

	for (int k=0; k<n; k++) {
		if (j + k >= n) break ;
		if (candies[i][j] != candies[i][j + k]) break ;
		count++;
	}
	return (count);
}

void find_max_count(string candies[], int n, int *max)
{
	int temp;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			temp = 0;
			if (i == 0 || candies[i - 1][j] != candies[i][j])
				temp = down(candies, i, j, n);
			*max = *max < temp ? temp : *max;
			if (j == 0 || candies[i][j - 1] != candies[i][j])
				temp = right(candies, i, j, n);
			*max = *max < temp ? temp : *max;
		}
	}
}

void swap_candy(char *c1, char *c2)
{
	char temp;

	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

int main()
{
	fast;
	string candies[50];
	int n, max=0;

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> candies[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<2; k++) {
				if (i + dy[k] >= n || j + dx[k] >= n) continue ;
				if (candies[i][j] != candies[i + dy[k]][j + dx[k]]) {
					swap_candy(&candies[i][j], &candies[i + dy[k]][j + dx[k]]);
					find_max_count(candies, n, &max);
					swap_candy(&candies[i][j], &candies[i + dy[k]][j + dx[k]]);
				}
			}
		}
	}
	cout << max;
	return (0);
}