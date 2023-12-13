// ⚾️ bj.17281
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int max_score;

void count_score(vector<vector<int>> v, int n, int lst[])
{
    vector<int> position;
    int out=0, cnt=0, size, result, prev_res=1, i=0;

    while (i < n) {
        for (int j=prev_res; j<10; j++) {
            result = v[i][lst[j]-1];
            if (result == 0 && out < 3) out++;
            else if (result != 0) {
                position.push_back(result);
                size = (int)position.size();
                for (int k=0; k<size; k++) {
                    if (k != size-1) position[k] += result;
                    if (position[k] >= 4) {
                        cnt++;
                        position.erase(position.begin()+k);
                        size--;
                        k--;
                    }
                }
            }
            if (out == 3) {
                if (j == 9) prev_res = 1;
                else prev_res = j + 1;
                position = vector<int>();
                i++;
                out = 0;
                break ;
            }
            if (j == 9) prev_res = 1;
        }
    }
    if (max_score < cnt) {
        max_score = cnt;
    }
}

void sequence(vector<vector<int>> v, int n, int lst[], int idx, int check_lst[])
{
    if (idx == 10) {
        count_score(v, n, lst);
    }
    else {
        if (idx == 4)
            sequence(v, n, lst, idx+1, check_lst);
        else {
            for (int i=1; i<10; i++) {
                if (check_lst[i] == 0) {
                    lst[idx] = i;
                    check_lst[i] = 1;
                    sequence(v, n, lst, idx+1, check_lst);
                    check_lst[i] = 0;
                }
            }
        }
    }
}

int main()
{
    fast;
    int n, num;
    int lst[10]={0,};
    int check_lst[10]={0,};
    cin >> n;
    vector<vector<int>> v(n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<9; j++) {
            cin >> num;
            v[i].push_back(num);
        }
    }
    lst[4] = 1;
    check_lst[1] = 1;
    sequence(v, n, lst, 1, check_lst);
    cout << max_score;
    return (0);
}