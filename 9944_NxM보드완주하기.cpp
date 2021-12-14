#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N, M;
char map[31][31];
int check[31][31];
int Cnt;
int startY, startX;
int Min = 9999999;
int arrY[4] = { -1, 0, 1, 0 };
int arrX[4] = { 0, 1, 0, -1 };

bool range(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	else
		return true;
}

void search(int y, int x, int direction, int cnt, int move) {
	if (cnt == Cnt) {
		if (Min > move)
			Min = move;

		return;
	}

	int ny = y + arrY[direction];
	int nx = x + arrX[direction];
	if (range(ny, nx) && check[ny][nx] == 0 && map[ny][nx] == '.') {
		check[ny][nx] = 1;
		search(ny, nx, direction, cnt + 1, move);
		check[ny][nx] = 0;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i == direction)
				continue;

			ny = y + arrY[i];
			nx = x + arrX[i];
			if (range(ny, nx) && check[ny][nx] == 0 && map[ny][nx] == '.' ) {
				check[ny][nx] = 1;
				search(ny, nx, i, cnt + 1, move + 1);
				check[ny][nx] = 0;
			}
		}
	}
}

void start_Point() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					check[i][j] = 1;
					search(i, j, k, 1, 1);
					check[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	int test = 0;
	while (cin >> N >> M) {
		test++;
		Min = 9999999;
		Cnt = 0;
		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));

		for (int i = 0; i < N; i++)
			scanf("%s", &map[i]);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.')
					Cnt++;
			}
		}

		if (Cnt == 1) {
			cout << "Case " << test << ": " << 0 << endl;
			continue;
		}

		start_Point();

		if (Min == 9999999)
			cout << "Case " << test << ":" << " " << -1 << endl;
		else
			cout << "Case " << test << ": " << Min << endl;
	}
}