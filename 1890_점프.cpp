#include <iostream>
#include <cstdio>
using namespace std;

int N;
int map[101][101];
long long int check[101][101];
int arrY[2] = { 0, 1 };
int arrX[2] = { 1, 0 };

bool range(int y, int x) {
	if (y >= N || x >= N)
		return false;
	else
		return true;
}

long long int search(int y, int x) {
	if (y == N - 1 && x == N - 1)
		return 1;

	if (map[y][x] == 0)
		return 0;

	long long int& ret = check[y][x];
	if (ret != 0)
		return ret;

	for (int i = 0; i < 2; i++) {
		int ny = y + arrY[i] * map[y][x];
		int nx = x + arrX[i] * map[y][x];

		if (range(ny, nx)) {
			ret += search(ny, nx);
		}
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	cout << search(0, 0) << endl;
}