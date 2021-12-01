#include <iostream>
#include <cstdio>
using namespace std;

struct Data {
	char left;
	char right;
};

int N;
Data Tree[27];

void preorder(int now) {	
	printf("%c", now + 65);

	if (Tree[now].left != '.')
		preorder(Tree[now].left - 65);
	if (Tree[now].right != '.')
		preorder(Tree[now].right - 65);
}

void inorder(int now) {
	if (Tree[now].left != '.')
		inorder(Tree[now].left - 65);

	printf("%c", now + 65);

	if (Tree[now].right != '.')
		inorder(Tree[now].right - 65);
}

void postorder(int now) {
	if (Tree[now].left != '.')
		postorder(Tree[now].left - 65);
	if (Tree[now].right != '.')
		postorder(Tree[now].right - 65);
	
	printf("%c", now + 65);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char now, left, right;
		cin >> now >> left >> right;
		Tree[now - 65].left = left;
		Tree[now - 65].right = right;
	}

	preorder(0);
	printf("\n");

	inorder(0);
	printf("\n");

	postorder(0);
	printf("\n");
}