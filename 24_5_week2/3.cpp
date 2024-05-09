// 베스트셀러 bj.1302
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct s_books {
	string name;
	int cnt;
} t_books;

t_books books[1001];
int book_size;

int find_book(string name)
{
	for (int i=1; i<=book_size; i++) {
		if (books[i].name == name) return (i);
	}
	return (0);
}

void swap_name(string &s1, string &s2)
{
	string tmp;

	tmp = s1;
	s1 = s2;
	s2 = tmp;
}

void swap_cnt(int *c1, int *c2)
{
	int tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void reorder_book(int idx)
{
	for (int i=idx; i/2>=1; i/=2) {
		if (books[i/2].cnt > books[i].cnt || (books[i/2].cnt == books[i].cnt && books[i/2].name < books[i].name))
			break ;
		swap_name(books[i].name, books[i/2].name);
		swap_cnt(&(books[i].cnt), &(books[i/2].cnt));
	}
}

void insert_book(string name)
{
	book_size++;
	books[book_size].name = name;
	books[book_size].cnt = 1;
	reorder_book(book_size);
}

int main()
{
	fast;
	int n, tmp;
	string name;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> name;
		tmp = find_book(name);
		if (!tmp)
			insert_book(name);
		else {
			books[tmp].cnt++;
			reorder_book(tmp);
		}
	}
	cout << books[1].name;
	return (0);
}