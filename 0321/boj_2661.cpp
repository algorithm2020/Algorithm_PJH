#include <iostream>
#include <string>

int n;
std::string str;

bool valid(std::string s) {
	int size = s.size() / 2;
	for (int j = 1; j <= size; j++) {
		std::string temp1, temp2;
		temp1 = s.substr(s.size() - j, j);
		temp2 = s.substr(s.size() - j * 2, j);
		if (temp1 == temp2) {
			return false;
		}
	}
	return true;
}

void recur(int cnt) {
	if (cnt == n) {
		std::cout << str;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		if (valid(str + std::to_string(i)) ) {
			str += std::to_string(i);
			recur(cnt + 1);
			str.pop_back();
		}
	}
}

int main() {
	std::cin >> n;

	recur(0);


	return 0;
}