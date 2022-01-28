#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int arr[1025][1025];
long long int dp[1025][1025];
vector <long long int> v;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		long long int result = 0;
		result = dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1];
		v.push_back(result);
	}

	for (int i = 0; i < M; i++)
		printf("%lld\n", v[i]);
}