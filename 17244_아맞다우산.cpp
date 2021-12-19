#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Data {
	int y, x, bit, cnt;
};

int N, M;
int startY, startX;
int endY, endX;
int Cnt;
char map[51][51];
int check[51][51][1 << 5];
int arrY[4] = { -1, 0, 1, 0 };
int arrX[4] = { 0, 1, 0, -1 };
queue <Data> q;

bool range(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	else
		return true;
}

void search() {
	check[startY][startX][0] = 1;
	q.push({ startY, startX, 0, 0 });
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int bit = q.front().bit;
		int cnt = q.front().cnt;
		q.pop();

		if (y == endY && x == endX && bit == (1 << Cnt) - 1) {
			cout << cnt << endl;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + arrY[i];
			int nx = x + arrX[i];
			int nbit = bit;
			
			if (range(ny, nx)) {
				if (map[ny][nx] <= 5)
					nbit = nbit | (1 << map[ny][nx]);

				if (map[ny][nx] == '#' || check[ny][nx][nbit] == 1)
					continue;

				check[ny][nx][nbit] = 1;
				q.push({ ny, nx, nbit, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'X') {
				map[i][j] = Cnt;
				Cnt++;
			}
			else if (map[i][j] == 'S') {
				startY = i;
				startX = j;
			}
			else if (map[i][j] == 'E') {
				endY = i;
				endX = j;
			}
		}
	}

	search();
}