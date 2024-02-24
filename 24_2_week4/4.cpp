// 나는야 포켓몬 마스터 이다솜 bj.1620
#include <iostream>
#include <map>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m; cin >> n >> m;
	map<int, string > pokemon_num;
	map<string, int > pokemon_name;
	string name, question;

	for (int i=1; i<=n; i++) {
		cin >> name;
		pokemon_num.insert({i, name});
		pokemon_name.insert({name, i});
	}
	for (int i=0; i<m; i++) {
		cin >> question;
		if (question[0] >= '1' && question[1] <= '9')
			cout << pokemon_num[stoi(question)] << '\n';
		else
			cout << pokemon_name[question] << '\n';
	}
	return (0);
}