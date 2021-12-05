#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	int beforeY = -1, beforeX = -1;
	int afterY = -1, afterX = -1;
	int apple = 0;
};

struct Data {
	int y = 0, x = 0;
};

struct Time {
	int time;
	char change;
};

int N, K, L;
Node map[101][101];
int arrY[4] = { -1, 0, 1, 0 };
int arrX[4] = { 0, 1, 0, -1 };
int direction;
Data head;
Data tail;
Time arr[101];

bool range(int y, int x) {
	if (y < 0 || y > N - 1 || x < 0 || x > N - 1)
		return false;
	else
		return true;
}

int search() {
	direction = 1;
	int p = 0;
	int cnt = 0;
	
	while (1) {
		if (cnt == arr[p].time) {
			if (arr[p].change == 'D')
				direction = (direction + 1) % 4;
			else if (arr[p].change == 'L')
				direction = (direction  + 4 - 1) % 4;

			p++;
		}

		int ny = head.y + arrY[direction];
		int nx = head.x + arrX[direction];
		
		if (range(ny, nx)) {
			if (map[ny][nx].afterY != -1) {
				cnt++;
				break;
			}
			else {
				if (map[ny][nx].apple == 0) {
					map[ny][nx].beforeY = head.y;
					map[ny][nx].beforeX = head.x;
					map[head.y][head.x].afterY = ny;
					map[head.y][head.x].afterX = nx;
					head.y = ny;
					head.x = nx;

					int ty = map[tail.y][tail.x].afterY;
					int tx = map[tail.y][tail.x].afterX;
					map[tail.y][tail.x].afterY = -1;
					map[tail.y][tail.x].afterX = -1;
					map[ty][tx].beforeY = -1;
					map[ty][tx].beforeX = -1;
					tail.y = ty;
					tail.x = tx;
				}
				else if (map[ny][nx].apple == 1) {
					map[ny][nx].beforeY = head.y;
					map[ny][nx].beforeX = head.x;
					map[ny][nx].apple = 0;
					map[head.y][head.x].afterY = ny;
					map[head.y][head.x].afterX = nx;
					head.y = ny;
					head.x = nx;
				}
			}

			cnt++;
		}
		else {
			cnt++;
			break;
		}
	}

	return cnt;
}


int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		map[y - 1][x - 1].apple = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
		scanf("%d %c", &arr[i].time, &arr[i].change);

	int result = search();
	cout << result << endl;
}