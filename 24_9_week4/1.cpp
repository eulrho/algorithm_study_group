// 이진 검색 트리 bj.5639
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int preorder[10001];
int postorder[10001];

int post_idx = 1;

void ft_postorder(int index, int size, int range_max)
{
	int right_node = index + 1;

	while (right_node < range_max && preorder[index] > preorder[right_node])
		right_node++;
	if (index + 1 < size && preorder[index] > preorder[index + 1])
		ft_postorder(index + 1, size, right_node);
	if (right_node < range_max)
		ft_postorder(right_node, size, range_max);
	postorder[post_idx++] = preorder[index];
}

int main()
{
	fast;
	int node, size=1;

	while (cin >> node)
		preorder[size++] = node;
	ft_postorder(1, size, size);
	for (int i=1; i<size; i++) {
		cout << postorder[i] << '\n';
	}
	return 0;
}
