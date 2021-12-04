#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int check[105];
vector<int> v[105];
int n, edge;
queue<int> q;
int cnt = 0;

void search() 
{
	q.push(1);
	check[1] = 1;

	while (!q.empty()) 
	{
		int x;
		x = q.front(); 
		q.pop();

		for (int i = 0; i<v[x].size(); i++) 
		{
			if (check[v[x][i]] == 0) 
			{
				check[v[x][i]] = 1;
				q.push(v[x][i]);
			}
		}
	}
}

int main()
{
	cin >> n >> edge;

	for (int i = 0; i<edge; i++) 
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	search();

	for (int i = 2; i<105; i++) {
		if (check[i] == 1)
			cnt++;
	}

	cout << cnt << endl;
}