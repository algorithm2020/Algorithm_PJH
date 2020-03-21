#include <iostream>
#include <deque>

int main() {
	int tc; 
	int cnt = 0;
	std::deque<int> result;
	std::cin >> tc;

	while (cnt < tc) {
		int N, M, temp;
		std::deque<std::pair<int, bool> > tempq;
		std::cin >> N >> M;
		for (int i = 0; i < N; i++) {
			std::cin >> temp;
			tempq.push_back(std::make_pair(temp, false));
			if (i == M) {
				tempq[i].second = true;
			}
		}
		int seq = 0;
		while (!tempq.empty()) {
			int val = tempq.front().first;
			bool check = tempq.front().second;
			tempq.pop_front();
			
			bool find = false;
			for (int i = 0; i < tempq.size(); i++) {
				if (tempq[i].first > val) {
					find = true;
					break;
				}
			}
			if (find) {
				tempq.push_back(std::make_pair(val, check));
			}
			else {
				seq++;
				if (check) {
					result.push_back(seq);
				}
			}
		}

		cnt++;
	}
	

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}

	return 0;
}