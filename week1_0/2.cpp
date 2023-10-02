// 진법 변환 2 bj.11005
#include <iostream>
#include <string>

using namespace std;

string ten_to_B(int N, int B) {
    string answer = "";

    if (N == 0)
    {
        answer += '0';
        return (answer);
    }
    while (N)
    {
        if (N % B >= 10)
            answer.insert(answer.begin(), (N % B) + 'A' - 10);
        else
            answer.insert(answer.begin(), (N % B) + '0');
        N /= B;
    }
    return (answer);
}

int main () {
    int N, B;
    string result;

    cin >> N >> B;
    result = ten_to_B(N, B);
    cout << result;
    return (0);
}