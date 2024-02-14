// 마술사 이민혁 bj.3023
#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int r, c, a, b;

void draw_card(string card[], string card_design[])
{
	string rev_temp;
	int idx=0;

	for (int j=0; j<2; j++) {
		for (int i=0; i<r; i++) {
			card[idx] = card_design[i];
			rev_temp = card_design[i];
			reverse(rev_temp.begin(), rev_temp.end());
			card[idx] += rev_temp;
			idx++;
		}
		reverse(card_design, card_design + r);
	}
	if (card[a - 1][b - 1] == '#')
		card[a - 1][b - 1] = '.';
	else
		card[a - 1][b - 1] = '#';
}

int main()
{
	fast;
	string card_design[52];
	string card[102];

	cin >> r >> c;
	for (int i=0; i<r; i++)
		cin >> card_design[i];
	cin >> a >> b;
	draw_card(card, card_design);
	for (int i=0; i<2*r; i++)
		cout << card[i] << '\n';
	return (0);
}