#include <iostream>
using namespace std;

int main()
{
	int D;
	int car;
	cin >> D;
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> car;
		if (D == car)
			count++;
	}
	cout << count << endl;
}