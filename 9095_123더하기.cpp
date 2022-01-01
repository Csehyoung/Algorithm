#include <iostream>
#include <cstdio>
using namespace std;

int search(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;

	return search(n - 1) + search(n - 2) + search(n - 3);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", search(a));
	}
}