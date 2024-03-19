// DNA 비밀번호 bj.12891
#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void initial_map(map<char, int> &min_cnt, map<char, int> &cnt)
{
	int n;

	cnt.insert({'A', 0});
	cnt.insert({'C', 0});
	cnt.insert({'G', 0});
	cnt.insert({'T', 0});
	min_cnt = cnt;
	cin >> n;
	min_cnt['A'] = n;
	cin >> n;
	min_cnt['C'] = n;
	cin >> n;
	min_cnt['G'] = n;
	cin >> n;
	min_cnt['T'] = n;
}

int main()
{
	fast;
	int s, p, left, right, res=0;
	map<char, int> min_cnt;
	map<char, int> cnt;
	string str, dna_str="ACGT";

	cin >> s >> p >> str;
	initial_map(min_cnt, cnt);
	left = 0; right = p-1;
	for (int i=left; i<=right; i++)
		cnt[str[i]]++;
	for (int i=0; i<4; i++) {
		if (min_cnt[dna_str[i]] > cnt[dna_str[i]]) break ;
		if (i == 3) res++;
	}
	left++; right++;
	while (right < s) {
		cnt[str[left-1]]--;
		cnt[str[right]]++;
		for (int i=0; i<4; i++) {
			if (min_cnt[dna_str[i]] > cnt[dna_str[i]]) break ;
			if (i == 3) res++;
		}
		left++; right++;
	}
	cout << res;
	return (0);
}