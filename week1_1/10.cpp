// 그대로 출력하기 bj.11718
#include <iostream>

using namespace std;

int main() {
    string arr;

    for (int i=0; i<100; i++)
    {
        getline(cin, arr);
        cout << arr << "\n";
    }
    return (0);
}