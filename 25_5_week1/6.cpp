// 실패율
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<double, int> &p1, pair<double, int> &p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<double, int>> failure;
	int cnts[502] = {0, };

	for (int i=0; i<(int)stages.size(); i++) cnts[stages[i]]++;

	int tmp = cnts[N+1];
	for (int i=N; i>0; i--) {
		tmp += cnts[i];
		if (tmp == 0) failure.emplace_back(0, i);
		else failure.emplace_back((double)cnts[i] / tmp, i);
	}

	sort(failure.begin(), failure.end(), cmp);

	for (int i=0; i<N; i++) answer.push_back(failure[i].second);
	return answer;
}