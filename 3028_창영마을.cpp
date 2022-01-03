#include <iostream>
#include <cstdio>
using namespace std;

char str[51];

int main()
{
	int arr[3] = { 1, 0, 0 };

	cin >> str;

	int idx = 0;
	while (str[idx] != '\0')
		idx++;

	for (int i = 0; i < idx; i++)
	{
		if (str[i] == 'A')
			swap(arr[0], arr[1]);
		else if (str[i] == 'B')
			swap(arr[1], arr[2]);
		else if (str[i] == 'C')
			swap(arr[0], arr[2]);
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == 1)
			cout << i + 1 << endl;
	}
}