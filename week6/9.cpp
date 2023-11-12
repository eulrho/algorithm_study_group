// 완전 이진 트리 bj.9934
#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int idx=1;

void print_result(int *result, int size)
{
    int level=1, mult=1;

    for (int i=1; i<=size; i++) {
        cout << result[i];
        if (level == i) {
            cout << '\n';
            level += 2*mult;
            mult++;
        }
        else cout << ' ';
    }
}

void input_buildings(int *building, int size)
{
    for (int i = 1; i <= size; i++) cin >> building[i];
}

void find_node(int *building, int *result, int node, int max_node)
{
    if (2 * node <= max_node)
        find_node(building, result, 2 * node, max_node);
    result[node] = building[idx];
    idx += 1;
    if (2 * node + 1 <= max_node)
        find_node(building, result, 2 * node + 1, max_node);
}

int main()
{
    int k, size;
    cin >> k;
    size = (int)pow(2, k) - 1;
    int *building = new int[size+1];
    int *result = new int[size+1];

    input_buildings(building, size);
    find_node(building, result, 1, size);
    print_result(result, size);
    delete []building;
    delete []result;
    return (0);
}