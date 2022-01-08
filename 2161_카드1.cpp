#include <iostrea>
#include <cstdio>
#include <queue>
using namespace std;

queue <int> q;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
	
	while (!q.empty())
	{
		printf("%d ", q.front());
		q.pop();
		
		if (q.empty())
			break;

		int a = q.front();
		q.pop();
		q.push(a);
	}
}