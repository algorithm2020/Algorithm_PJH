#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> rope;
std::vector<int> result;

bool comp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		rope.push_back(temp);
	}
		
	std::sort(rope.begin(), rope.end());

	for (int i = n , j = 0; i > 0; i--, j++) {
		result.push_back(i * rope[j]);
	}

	std::sort(result.begin(), result.end(), comp);

	std::cout << result.front();

	return 0;
}