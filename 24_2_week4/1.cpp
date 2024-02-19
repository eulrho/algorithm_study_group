// DSLR bj.9019
#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct s_check
{
	string command;
	bool visited = false;
} t_check;

string bfs(int a, int b)
{
	t_check check[10001];
	int num, temp;
	queue<int> queue;

	queue.push(a);
	check[a].command = "";
	check[a].visited = true;
	while (!queue.empty()) {
		num = queue.front();
		if (num == b) break ;
		temp = num * 2 > 9999 ? num * 2 % 10000 : num * 2;
		if (!check[temp].visited) {
			queue.push(temp);
			check[temp].visited = true;
			check[temp].command = check[num].command;
			check[temp].command += 'D';
		}
		temp = num == 0 ? 9999 : num - 1;
		if (!check[temp].visited) {
			queue.push(temp);
			check[temp].visited = true;
			check[temp].command = check[num].command;
			check[temp].command += 'S';
		}
		temp = num % 1000 * 10 + num / 1000;
		if (!check[temp].visited) {
			queue.push(temp);
			check[temp].visited = true;
			check[temp].command = check[num].command;
			check[temp].command += 'L';
		}
		temp = num % 10 * 1000 + num / 10;
		if (!check[temp].visited) {
			queue.push(temp);
			check[temp].visited = true;
			check[temp].command = check[num].command;
			check[temp].command += 'R';
		}
		queue.pop();
	}
	return (check[num].command);
}

int main()
{
	fast;
	int t, a, b;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
	return (0);
}