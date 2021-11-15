#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (1) {
		stack <char> st;
		string s;
		cin >> s;
		if (s == "0")
			break;

		int temp = 0;

		int length = s.size();
		for (int i = 0; i < length; i++) {
			if (length % 2 == 1 && i == length / 2) {
				continue;
			}
			
			if (i < length / 2)
				st.push(s[i]);
			else{
				if (st.top() == s[i])
					st.pop();
				else {
					cout << "no" << endl;
					temp = 1;
					break;
				}
			}
		}

		if(temp == 0)
			cout << "yes" << endl;
	}
}