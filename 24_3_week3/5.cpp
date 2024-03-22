// DSLR bj.9019
#include <iostream>
#include <string>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string find_command(int a, int b)
{
	queue<int> queue;
	int number, visited[10000]={0,}, temp;
	string commands[10000];

	queue.push(a);
	visited[a] = 1;
	commands[a] = "";
	while (!queue.empty()) {
		number = queue.front();
		queue.pop();
		if (number == b) break ;
		temp = number * 2 > 9999 ? number * 2 % 10000 : number * 2;
		if (visited[temp] == 0) {
			visited[temp] = 1;
			queue.push(temp);
			commands[temp] = commands[number] + 'D';
		}
		temp = number == 0 ? 9999 : number - 1;
		if (visited[temp] == 0) {
			visited[temp] = 1;
			queue.push(temp);
			commands[temp] = commands[number] + 'S';
		}
		temp = (number % 1000) * 10 + number / 1000;
		if (visited[temp] == 0) {
			visited[temp] = 1;
			queue.push(temp);
			commands[temp] = commands[number] + 'L';
		}
		temp = (number % 10) * 1000 + number / 10;
		if (visited[temp] == 0) {
			visited[temp] = 1;
			queue.push(temp);
			commands[temp] = commands[number] + 'R';
		}
	}
	return (commands[b]);
}

int main()
{
	fast;
	int t, a, b;

	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> a >> b;
		cout << find_command(a, b) << '\n';
	}
	return (0);
}