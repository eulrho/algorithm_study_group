// Candy bj.12897
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define NUM_LIMIT 1000000007
using namespace std;

unsigned long long my_pow(int n1, int n2)
{
	unsigned long long res=1;
	for (int i=1; i<=n2; i++)
		res = (res * n1) % NUM_LIMIT;
	return (res);
}

int main()
{
	fast;
	int n; cin >> n;
	cout << my_pow(3, n) - 1;
	return (0);
}