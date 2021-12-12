#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int arr[501][501];
int check[501][501];
int result;

int search(int y, int x) {
	if (y == N - 1 && x == M - 1)
	{
		return 1;
	}
	int& ret = check[y][x];
	if (ret != -1)
		return ret;

	ret = 0;

	if(x + 1 < M && arr[y][x] > arr[y][x + 1])
		ret += search(y, x + 1);
	if(x - 1 >= 0 && arr[y][x] > arr[y][x - 1])
		ret += search(y, x - 1);
	if(y + 1 < N && arr[y][x] > arr[y + 1][x])
		ret += search(y + 1, x);
	if(y - 1 >= 0 && arr[y][x] > arr[y - 1][x])
		ret += search(y - 1, x);

	return ret;
}


int main() {
	memset(check, -1, sizeof(check));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
	}

	cout << search(0, 0) << endl;
}