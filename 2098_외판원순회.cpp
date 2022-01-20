#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int map[16][16];
int dp[16][1 << 16];

int search(int now, int bit) {
	if (bit == (1 << N) - 1) {
		if (map[now][0] == 0)
			return 987654321;
		else
			return map[now][0];
	}

	int& ret = dp[now][bit];
	if (ret != 0)
		return ret;

	ret = 987654321;

	for (int i = 0; i < N; i++) {
		if (((bit & (1 << i)) == 0) && map[now][i] != 0) {
			ret = min(ret, search(i, bit | (1 << i)) + map[now][i]);
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

	int result = search(0, 1);

	cout << result << endl;
}