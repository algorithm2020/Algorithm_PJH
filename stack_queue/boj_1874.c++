#include <iostream>
#include <deque>
#include <vector>

std::vector<int> stack;
std::vector<char> resArr;

int initArr[100000];

int main() {
	int n, temp;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> initArr[i];
	}
	int idx = 1;
	for(int i =0; i< n; i++){
		
		if (stack.empty() || stack.back() != initArr[i]) {
			while (true) {
				if (idx > n) {
					std::cout << "NO";
					return 0;
				}
				resArr.push_back('+');
				stack.push_back(idx);
				idx++;
				if (stack.back() == initArr[i]) {
					stack.pop_back();
					resArr.push_back('-');
					break;
				}
			}
		}
		else if(stack.back() == initArr[i]) {
			stack.pop_back();
			resArr.push_back('-');
		}
	}

	for (int i = 0; i< resArr.size(); i++) {
		std::cout << resArr[i] << std::endl;
	}

	return 0;
}