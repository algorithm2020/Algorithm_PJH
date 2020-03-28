#include <iostream>
#include <deque>

int main() {
	int n;
	long long arr[101];
	std::deque<long long> que;

	bool visited[101] = {false,};

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	que.push_back(arr[0]);
	visited[0] = true;

	while (que.size() < n) {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				if (que.front() == arr[i] * 2) {
					que.push_front(arr[i]);
					visited[i] = true;
					break;
				}
				else if (que.front() == arr[i] / 3) {
					que.push_front(arr[i]);
					visited[i] = true;
					break;
				}
				else if (que.back() / 3 == arr[i]) {
					que.push_back(arr[i]);
					visited[i] = true;
					break;
				}
				else if (que.back() * 2 == arr[i]) {
					que.push_back(arr[i]);
					visited[i] = true;
					break;
				}
			}
		}
	}

	
	for (int i = 0; i < que.size(); i++) {
		std::cout << que[i] << ' ';
	}
	


	return 0;
}