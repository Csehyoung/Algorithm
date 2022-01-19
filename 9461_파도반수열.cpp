#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
long long dp[101];

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, 0, sizeof(dp));

		cin >> N;

		dp[1] = 1;
		dp[2] = 1;

		for (int i = 3; i <= N; i++)
			dp[i] = dp[i - 3] + dp[i - 2];
	
		cout << dp[N] << endl;
	}
}