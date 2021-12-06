#include <iostream>
using namespace std;

int weight[55];
int height[55];
int grade[55];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> weight[i] >> height[i];

	for (int i = 0; i < N; i++)
	{
		grade[i] = 1;
		for (int j = 0; j < N; j++)
		{
			if (weight[i] < weight[j] && height[i] < height[j])
				grade[i]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << grade[i] << " ";
	}
	cout << endl;

}