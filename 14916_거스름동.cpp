#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int dp[100001];

int main() {
	cin >> N;

	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (dp[i - 5] == 0) {
			if (dp[i - 2] == 0)
				dp[i] = 0;
			else
				dp[i] = dp[i - 2] + 1;
		}
		else if (dp[i - 2] == 0) {
			if (dp[i - 5] == 0)
				dp[i] = 0;
			else
				dp[i] = dp[i - 5] + 1;
		}
		else
			dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	}
	
	if (dp[N] == 0)
		cout << -1 << endl;
	else
		cout << dp[N] << endl;
}