#include <iostream>
using namespace std;

int arr[1001];
int check[1002][1001];
int n;

int search(int a, int idx)
{
	int ret=0;

	if (idx == n)
		return 0;

	if (check[a][idx] > 0)
		return check[a][idx];

	if (a > arr[idx])
	{
		ret = search(arr[idx], idx + 1) + 1;
	}

	int temp = search(a, idx + 1);
	if (temp > ret)
		ret = temp;

	check[a][idx] = ret;
	return check[a][idx];
}


int main()
{
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		cin >> arr[t];
	}

	cout << search(1001, 0) << endl;
	return 0;
}