#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N;
int check[21];

int search(int cnt) {

	if (cnt == 0)
		return 0;
	else if (cnt == 1)
		return 1;

	int& ret = check[cnt];
	if (ret != -1)
		return ret;
	
	ret = search(cnt - 1) + search(cnt - 2);

	return ret;
}

int main() {
	memset(check, -1, sizeof check);
	cin >> N;
	cout << search(N) << endl;
}