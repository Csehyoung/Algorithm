#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int N;
int arr[2][100001];
int check[2][100001];
int result;

int search(int row, int idx) {
	if (idx >= N)
		return 0;

	int& ret = check[row][idx];
	if (ret != -1)
		return ret;

	ret = 0;

	if (row == 0) 
		ret = max(max(search(row, idx + 1), search(row, idx + 2) + arr[row][idx]), max(search(row + 1, idx + 1), search(row + 1, idx + 1) + arr[row][idx]));
	else 
		ret = max(max(search(row, idx + 1), search(row, idx + 2) + arr[row][idx]), max(search(row - 1, idx + 1), search(row - 1, idx + 1) + arr[row][idx]));

	return ret;
}


int main() {
	memset(check, -1, sizeof(check));
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++)
				scanf("%d", &arr[i][j]);
		}
	
		memset(check, -1, sizeof(check));

		printf("%d\n", max(search(0, 0), search(1, 0)));
	}
}