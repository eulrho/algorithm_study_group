// 이진 검색 트리 bj.5639
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int pre_tree[10001]={0,}, post_tree[10001]={0, };
int post_idx = 1;

void find_post_tree(int size, int idx, int range_max)
{
	int right_node = idx + 1;

	while (right_node < range_max && pre_tree[idx] > pre_tree[right_node])
		right_node++;
	if (idx + 1 < size && pre_tree[idx] > pre_tree[idx + 1])
		find_post_tree(size, idx + 1, right_node);
	if (right_node < range_max)
		find_post_tree(size, right_node, range_max);
	post_tree[post_idx++] = pre_tree[idx];
}

int main()
{
	fast;
	int size=1, node;

	while (size <=10000 && cin >> node) {
		pre_tree[size] = node;
		size++;
	}
	find_post_tree(size, 1, size);
	for (int i=1; i<size; i++) cout << post_tree[i] << '\n';
	return (0);
}
