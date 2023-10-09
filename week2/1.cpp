// 막대기 bj.17608
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, h;
    vector<int> stack;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> h;
        while (stack.size() != 0 && stack.back() <= h)
            stack.pop_back();
        stack.push_back(h);
    }
    cout << stack.size();
    return (0);
}