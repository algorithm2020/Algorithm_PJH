#include <iostream>
#include <vector>

std::vector<int> arr;
bool visited[1001] = {false,};
int n, k, cur;

int main() {
	std::cin >> n >> k;
	
	int size = n;
	int cnt = 0;
	while (size > 0) {
		int next;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			cnt++;
			if (cnt == k) {
				visited[i] = true;
				arr.push_back(i);
				size--;
				cnt = 0;
			}
		}
	}
	std::cout << '<';
	for (int i = 0; i < n -1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[n-1] << '>';
	return 0;
}