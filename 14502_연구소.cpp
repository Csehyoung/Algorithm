#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int map[9][9];
int check[9][9];
vector <pair<int, int>> v;
queue <pair<int, int>> q;
int arrY[4] = { -1, 0, 1, 0 };
int arrX[4] = { 0, 1, 0, -1 };
int Max;

bool range(int y, int x) {
	if (y < 0 || y > n - 1 || x < 0 || x > m - 1)
		return false;
	else
		return true;
}

void search() {
	int searchMap[9][9] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			searchMap[i][j] = check[i][j];
	}

	int length = v.size();
	for (int i = 0; i < length; i++)
		q.push(make_pair(v[i].first, v[i].second));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + arrY[i];
			int nx = x + arrX[i];

			if (range(ny, nx) && searchMap[ny][nx] == 0) {
				searchMap[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (searchMap[i][j] == 0)
				cnt++;
		}
	}

	if (Max < cnt)
		Max = cnt;
}

void wall(int count) {
	if (count == 3) {
		search();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				wall(count + 1);
				check[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			check[i][j] = map[i][j];

			if (map[i][j] == 2)
				v.push_back(make_pair(i, j));
		}
	}

	wall(0);

	cout << Max << endl;
}