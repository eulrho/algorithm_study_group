// 두 수를 뽑아서 더하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;

	int size = (int)numbers.size();
	for (int i=0; i<size; i++) { // O(n^2)
		for (int j=i+1; j<size; j++)
			answer.push_back(numbers[i] + numbers[j]);
	}
	sort(answer.begin(), answer.end()); // O(nlogn)
	answer.erase(unique(answer.begin(), answer.end()), answer.end()); // // O(n^2)
	return answer;
}