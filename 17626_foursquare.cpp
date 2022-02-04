#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int dp[50001];

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++)
		dp[i] = 4;

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}

	cout << dp[N] << endl;
}