// 트리의 순회 bj.2236
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;
int inorder[100001];
int inidx[100001];
int postorder[100001];

void make_pre(int in_left, int in_right, int post_left, int post_right)
{
    if (in_left > in_right || post_left > post_right) return ;
    int root = postorder[post_right];
    int rootidx = inidx[root];
    int len = rootidx - in_left;

    cout << root << ' ';
    make_pre(in_left, rootidx-1, post_left, post_left+len-1);
    make_pre(rootidx+1, in_right, post_left+len, post_right-1);
}

int main()
{
    fast;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> inorder[i];
        inidx[inorder[i]] = i;
    }
    for (int i=1; i<=n; i++) {
        cin >> postorder[i];
    }
    make_pre(1, n, 1, n);
    return (0);
}