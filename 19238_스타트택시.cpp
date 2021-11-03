#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct Node {
	int startY;
	int startX;
	int endY;
	int endX;
};

struct Data {
	int y;
	int x;
	int cnt;
};

int N, M, K;
int startY, startX;
int map[21][21];
int check[21][21];
int arrY[4] = { -1, 0, 0, 1 };
int arrX[4] = { 0, -1, 1, 0 };
Node passenger[401];

bool range(int y, int x) {
	if (y < 0 || y > N - 1 || x < 0 || x > N - 1)
		return false;
	else
		return true;
}

int search(int a, int b) {
	queue <Data> q;
	q.push({a, b, 0});
	//int check[21][21] = { 0 };
	memset(check, 0, sizeof(check));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (K - cnt < 0)
			return -1;

		check[y][x] = 1;

		if (map[y][x] != 0 && map[y][x] != -1) {
			int who = map[y][x];
			map[y][x] = 0;
			K = K - cnt;
			if (K < 0)
				return -1;
			
			return who;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + arrY[i];
			int nx = x + arrX[i];
			
			if (range(ny, nx) && map[ny][nx] != -1 && check[ny][nx] == 0) {
				q.push({ ny, nx, cnt + 1 });
			}
		}
	}

	return -1;
}

int search2(int a, int b, int c, int d) {
	queue <Data> q;
	q.push({ a, b, 0 });
	//int check[21][21] = { 0 };
	memset(check, 0, sizeof(check));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (K - cnt < 0)
			return -1;

		check[y][x] = 1;

		if (y == c && x == d) {
			K = K - cnt;
			if (K < 0)
				return -1;

			K = K + cnt * 2;
			startY = y;
			startX = x;

			return map[y][x];
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + arrY[i];
			int nx = x + arrX[i];

			if (range(ny, nx) && map[ny][nx] != -1 && check[ny][nx] == 0) {
				q.push({ ny, nx, cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
	}

	cin >> startY >> startX;

	for (int i = 1; i <= M; i++) {
		int manY, manX, goalY, goalX;
		scanf("%d %d %d %d", &manY, &manX, &goalY, &goalX);
		map[manY - 1][manX - 1] = i;
		passenger[i].startY = manY - 1;
		passenger[i].startX = manX - 1;
		passenger[i].endY = goalY - 1;
		passenger[i].endX = goalX - 1;
	}

	startY = startY - 1;
	startX = startX - 1;
	for (int i = 0; i < M; i++) {
		int who = search(startY, startX);
		if (who == -1) {
			cout << -1 << endl;
			return 0;
		}

		int ret = search2(passenger[who].startY, passenger[who].startX, passenger[who].endY, passenger[who].endX);
		if (ret == -1) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << K << endl;
}