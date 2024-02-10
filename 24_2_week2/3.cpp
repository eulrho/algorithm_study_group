// 너의 평점은 bj.25206
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

double gpa(string grade)
{
	if (grade == "A+") return (4.5);
	else if (grade == "A0") return (4.0);
	else if (grade == "B+") return (3.5);
	else if (grade == "B0") return (3.0);
	else if (grade == "C+") return (2.5);
	else if (grade == "C0") return (2.0);
	else if (grade == "D+") return (1.5);
	else if (grade == "D0") return (1.0);
	else return (0.0);
}

int main()
{
	fast;
	double credit, total_credit=0, sum=0;
	string name, grade;

	for (int i=0; i<20; i++)
	{
		cin >> name >> credit >> grade;
		if (grade != "P")
		{
			total_credit += credit;
			sum += gpa(grade) * credit;
		}
	}
	cout << sum / total_credit;
	return (0);
}