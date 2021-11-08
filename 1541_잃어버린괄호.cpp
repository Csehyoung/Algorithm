#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	string num;

	int temp = 0;
	int result = 0;
	int sum = 0;
	int length = str.size();
	for (int i = 0; i < length; i++) {

		if(str[i] != '-' && str[i] != '+' && i != length - 1)
			num += str[i];
		else {
			if (i == length - 1)
				num += str[i];

			if (temp == 0) {
				result += stoi(num);
				num = "";
			}
			else if (temp == 1) {
				result -= stoi(num);
				num = "";
			}
		}
		
		if (str[i] == '-')
			temp = 1;
	}

	cout << result << endl;
}