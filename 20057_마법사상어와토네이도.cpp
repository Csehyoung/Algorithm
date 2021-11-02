#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N;
int map[500][500];
int check[500][500];
int arrY[4][9] = { {-2, -1, -1, 0, 0, 0, 0, 1, 1}, {0, -1, 1, -2, -1, 1, 2, -1, 1}, {2, 1, 1, 0, 0, 0, 0, -1, -1}, {0, 1, -1, 2, 1, -1, -2, 1, -1} };
int arrX[4][9] = { {0, -1, 1, -2, -1, 1, 2, -1, 1}, {2, 1, 1, 0, 0, 0, 0, -1, -1}, {0, 1, -1, 2, 1, -1, -2, 1, -1}, {-2, -1, -1, 0, 0, 0, 0, 1, 1} };
int sand[9] = { 5, 10, 10, 2, 7, 7, 2, 1, 1 };
int dir;
int sum;

bool range(int y, int x) {
	if (y < 0 || y > N - 1 || x < 0 || x > N - 1)
		return false;
	else
		return true;
}

void search(int y, int x) {
	check[y][x] = 1;
	while (1) {
		while (1) {
			dir = 3;
			x--;
			check[y][x] = 1;

			int spread = 0;
			if (map[y][x] != 0) {
				for (int i = 0; i < 9; i++) {
					int ny = y + arrY[dir][i];
					int nx = x + arrX[dir][i];
					int move = map[y][x] * (0.01 * sand[i]);

					if (range(ny, nx)) {
						map[ny][nx] += move;
						spread += move;
					}
					else {
						sum += move;
						spread += move;
					}
				}

				map[y][x] -= spread;
				if (range(y, x - 1)) {
					map[y][x - 1] += map[y][x];
					map[y][x] = 0;
				}
				else {
					sum += map[y][x];
					map[y][x] = 0;
				}

			}

			if (check[y + 1][x] == 0)
				break;
			if (y == 0 && x == 0)
				break;
		}

		while (1) {
			dir = 2;
			if (y == 0 && x == 0)
				break;
			y++;
			check[y][x] = 1;

			int spread = 0;
			if (map[y][x] != 0) {
				for (int i = 0; i < 9; i++) {
					int ny = y + arrY[dir][i];
					int nx = x + arrX[dir][i];
					int move = map[y][x] * (0.01 * sand[i]);

					if (range(ny, nx)) {
						map[ny][nx] += move;
						spread += move;
					}
					else {
						sum += move;
						spread += move;
					}
				}

				map[y][x] -= spread;
				if (range(y + 1, x)) {
					map[y + 1][x] += map[y][x];
					map[y][x] = 0;
				}
				else {
					sum += map[y][x];
					map[y][x] = 0;
				}
			}

			if (check[y][x + 1] == 0)
				break;
			if (y == 0 && x == 0)
				break;
		}

		while (1) {
			dir = 1;
			if (y == 0 && x == 0)
				break;
			x++;
			check[y][x] = 1;

			int spread = 0;
			if (map[y][x] != 0) {
				for (int i = 0; i < 9; i++) {
					int ny = y + arrY[dir][i];
					int nx = x + arrX[dir][i];
					int move = map[y][x] * (0.01 * sand[i]);

					if (range(ny, nx)) {
						map[ny][nx] += move;
						spread += move;
					}
					else {
						sum += move;
						spread += move;
					}
				}

				map[y][x] -= spread;
				if (range(y, x + 1)) {
					map[y][x + 1] += map[y][x];
					map[y][x] = 0;
				}
				else {
					sum += map[y][x];
					map[y][x] = 0;
				}
			}

			if (check[y - 1][x] == 0)
				break;
			if (y == 0 && x == 0)
				break;
		}

		while (1) {
			dir = 0;
			if (y == 0 && x == 0)
				break;
			y--;
			check[y][x] = 1;

			int spread = 0;
			if (map[y][x] != 0) {
				for (int i = 0; i < 9; i++) {
					int ny = y + arrY[dir][i];
					int nx = x + arrX[dir][i];
					int move = map[y][x] * (0.01 * sand[i]);

					if (range(ny, nx)) {
						map[ny][nx] += move;
						spread += move;
					}
					else {
						sum += move;
						spread += move;
					}
				}

				map[y][x] -= spread;
				if (range(y - 1, x)) {
					map[y - 1][x] += map[y][x];
					map[y][x] = 0;
				}
				else {
					sum += map[y][x];
					map[y][x] = 0;
				}
			}

			if (check[y][x - 1] == 0)
				break;
			if (y == 0 && x == 0)
				break;
		}

		if (y == 0 && x == 0)
			break;

		
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	int y = N / 2;
	int x = N / 2;
	

	search(y, x);

	cout << sum << endl;
}
