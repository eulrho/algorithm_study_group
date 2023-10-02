// 진법 변환 bj.2745
#include <iostream>
#include <string>

using namespace std;

int ft_base(string N, int B) {
    int size = N.size(), answer = 0, num;

    for (int i=0; i<size; i++)
    {
        if (N[i] >= 'A' && N[i] <= 'Z')
            num = N[i] - 'A' + 10;
        else
            num = N[i] - '0';
        answer = answer * B + num;
    }
    return (answer);
}

int main () {
    string N;
    int B, result;

    cin >> N >> B;
    result = ft_base(N, B);
    cout << result;
    return (0);
}