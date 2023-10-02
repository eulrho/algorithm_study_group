// 열 개씩 끊어 출력하기 bj.11721
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int i = 0, size, len;

    cin >> str;
    size = str.size();
    do
    {
        if (size >= 10)
            len = 10;
        else
            len = size;
        cout << str.substr(i, len) << "\n";
        size -= len;
        i += 10;
    } while (size);
    return (0);
}