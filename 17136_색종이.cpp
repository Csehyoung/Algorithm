#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int map[10][10];
int check[10][10];
int paper[6];
int Min = 101;
vector <pair <int, int>> v;

bool range(int y, int x) {
	if (y > 10 || x > 10)
		return false;
	else
		return true;
}

bool cover(int y, int x, int k) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (check[i][j] != 0)
				return false;
			if (map[i][j] == 0)
				return false;
		}
	}

	return true;
}

void search(int cnt, int coverCnt) {
	if (coverCnt == v.size()) {
		if (Min > cnt)
			Min = cnt;
		
		return;
	}

	if (Min <= cnt)
		return;
	
	int length = v.size();
	for (int i = 0; i < length; i++) {
		int y = v[i].first;
		int x = v[i].second;

		if (check[y][x] == 1)
			continue;

		for (int j = 5; j > 0; j--) {
			if (paper[j] == 0)
				continue;

			if (range(y + j, x + j) && cover(y, x, j)) {
				for (int a = y; a < y + j; a++) {
					for (int b = x; b < x + j; b++) {
						check[a][b] = 1;
					}
				}
				paper[j]--;
				
				search(cnt + 1, coverCnt + j * j);
				
				for (int a = y; a < y + j; a++) {
					for (int b = x; b < x + j; b++) {
						check[a][b] = 0;
					}
				}
				paper[j]++;
			}
		}

		return;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				v.push_back(make_pair(i, j));
		}
	}

	for (int i = 1; i < 6; i++)
		paper[i] = 5;

	search(0, 0);

	if (Min == 101)
		cout << -1 << endl;
	else
		cout << Min << endl;
}