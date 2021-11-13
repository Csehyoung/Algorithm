#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int length = s.size();
	if (length == 1) {
		if (s[0] == '0') {
			cout << "0" << endl;
			return 0;
		}
	}

	for (int i = 0; i < length; i++) {
		if (i == 0) {
			if (s[i] == '1')
				printf("%s", "1");
			else if (s[i] == '2')
				printf("%s", "10");
			else if (s[i] == '3')
				printf("%s", "11");
			else if (s[i] == '4')
				printf("%s", "100");
			else if (s[i] == '5')
				printf("%s", "101");
			else if (s[i] == '6')
				printf("%s", "110");
			else if (s[i] == '7')
				printf("%s", "111");
		}
		else {
			if (s[i] == '0')
				printf("%s", "000");
			else if (s[i] == '1')
				printf("%s", "001");
			else if (s[i] == '2')
				printf("%s", "010");
			else if (s[i] == '3')
				printf("%s", "011");
			else if (s[i] == '4')
				printf("%s", "100");
			else if (s[i] == '5')
				printf("%s", "101");
			else if (s[i] == '6')
				printf("%s", "110");
			else if (s[i] == '7')
				printf("%s", "111");
		}
	}

	cout << endl;
}