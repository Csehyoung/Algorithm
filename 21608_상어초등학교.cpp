#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Data {
	int student;
	int like[4];
};

struct Seat {
	int y;
	int x;
	int no;
	int empty;
};

int N;
int map[20][20];
Data arr[401];
int arrY[4] = { -1, 0, 1, 0 };
int arrX[4] = { 0, 1, 0, -1 };
vector <Seat> v;
int result;

bool range(int y, int x) {
	if (y < 0 || y > N - 1 || x < 0 || x > N - 1)
		return false;
	else
		return true;
}

void search(int who) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] != 0)
				continue;

			int ny = 0;
			int nx = 0;
			int cnt = 0;
			int empty = 0;

			for (int i = 0; i < 4; i++){
				ny = y + arrY[i];
				nx = x + arrX[i];

				if (range(ny, nx)) {
					for (int j = 0; j < 4; j++) {
						if (map[ny][nx] == arr[who].like[j])
							cnt++;
					}
					if (map[ny][nx] == 0)
						empty++;
				}
			}
		
			if (v.empty())
				v.push_back({ y, x, cnt, empty });
			else if (v.back().no < cnt) {
				v.clear();
				v.push_back({ y, x, cnt, empty });
			}
			else if (v.back().no == cnt && v.back().empty < empty) {
				v.clear();
				v.push_back({ y, x, cnt, empty });
			}
			else if (v.back().no == cnt && v.back().empty == empty) {
				v.push_back({ y, x, cnt, empty });
			}
		}
	}

	map[v[0].y][v[0].x] = who;
	
	v.clear();
}

int search2() {
	int sum = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int ny = 0;
			int nx = 0;
			int cnt = 0;

			for (int i = 0; i < 4; i++) {
				ny = y + arrY[i];
				nx = x + arrX[i];

				if (range(ny, nx)) {
					for (int j = 0; j < 4; j++) {
						if (map[ny][nx] == arr[map[y][x]].like[j])
							cnt++;
					}
				}
			}

			if (cnt == 0)
				sum += 0;
			else if (cnt == 1)
				sum += 1;
			else if (cnt == 2)
				sum += 10;
			else if (cnt == 3)
				sum += 100;
			else if (cnt == 4)
				sum += 1000;
		}
	}

	return sum;
}


int main() {
	cin >> N;
	
	for (int i = 0; i < N * N; i++) {
		int who;
		scanf("%d", &who);
		arr[who].student = who;

		for (int j = 0; j < 4; j++) {
			int like;
			scanf("%d", &like);
			arr[who].like[j] = like;
		}	

		search(who);
	}

	int result = search2();

	cout << result << endl;
}