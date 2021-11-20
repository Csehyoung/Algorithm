#include <iostream>
#include <cstdio>
using namespace std;

char str[101];

int main()
{
	cin >> str;
	
	int idx = 0;
	while (str[idx] != '\0')
		idx++;

	cout << str[0];
	for (int i = 0; i < idx; i++)
	{
		if (str[i] == '-')
			cout << str[i + 1];
	}

	cout << endl;
}