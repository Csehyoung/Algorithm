#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[10001];
int dp[10001];

int search() {
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	
	for (int i = 3; i <= N; i++) 
		dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]), dp[i - 3] + arr[i - 1] + arr[i]);
	
	return dp[N];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) 
		scanf("%d", &arr[i]);
	
	cout << search() << endl;
}