#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
queue <int> q;
vector <int> v[32001];
int check[32001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
		check[to] += 1;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == 0)
			q.push(i);
	}

	while(!q.empty()) {
		int x = q.front();
		q.pop();

		printf("%d ", x);

		int length = v[x].size();
		for (int j = 0; j < length; j++) {
			int y = v[x][j];
			check[y] -= 1;

			if (check[y] == 0)
				q.push(y);
		}
	}

	cout << endl;
}