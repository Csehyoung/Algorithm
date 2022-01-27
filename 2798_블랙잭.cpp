#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int card[101];
int Max;

void search(int sum, int cnt, int idx) {
	if (cnt == 3) {
		if (sum <= M)
			Max = max(Max, sum);

		return;
	}

	for (int i = idx; i < N; i++) {
		if (sum + card[i] <= M)
			search(sum + card[i], cnt + 1, i + 1);
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	search(0, 0, 0);

	cout << Max << endl;
}