// 모의고사
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {2, 1, 2, 3, 2, 4, 2, 5};
	int arr3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

	vector<int> cnts = {0, 0, 0};
	for (int i=0; i<(int)answers.size(); i++) {
		if (arr1[i % 5] == answers[i]) cnts[0]++;
		if (arr2[i % 8] == answers[i]) cnts[1]++;
		if (arr3[i % 10] == answers[i]) cnts[2]++;
	}

	int max_score = *max_element(cnts.begin(), cnts.end());
	for (int i=0; i<3; i++) {
		if (max_score == cnts[i])
			answer.push_back(i + 1);
	}
	return answer;
}