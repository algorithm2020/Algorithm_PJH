#include <iostream>
#include <vector>
#include <deque>


std::vector<std::vector<int> > relation;
std::vector<int> result;

bool find(int front, int back, bool reverse) {
	std::deque<int> que;
	int curTime;
	int visited[401] = { false, };
	for (int j = 0; j < relation[front].size(); j++) {
		if (relation[front][j] == back) {
			if(reverse) result.push_back(1);
			else result.push_back(-1);

			return true;
		}
		visited[relation[front][j]] = true;
		que.push_back(relation[front][j]);
	}

	if (!que.empty()) {
		
		while (!que.empty()) {
			int curFront = que.front();
			que.pop_front();

			for (int j = 0; j < relation[curFront].size(); j++) {
				if (relation[curFront][j] == back) {
					if (reverse) result.push_back(1);
					else result.push_back(-1);

					return true;
				}
				if (!visited[relation[curFront][j]]) {
					visited[relation[curFront][j]] = true;
					que.push_back(relation[curFront][j]);
				}
			}
		}
	}

	return false;
}

int main() {
	int n, k, s;
	std::cin >> n >> k;
	
	relation = std::vector<std::vector<int> >(n + 1);

	for (int i = 1; i <= k; i++) {
		int front, back;
		std::cin >> front >> back;
		relation[front].push_back(back);
	}
	std::cin >> s;

	for (int i = 1; i <= s; i++) {
		int front, back;
		std::cin >> front >> back;
		bool res1 = find(front, back, false);
		if (res1) continue;
		bool res2 = find(back, front, true);
		if (res2) continue;

		if (!res1 && !res2) result.push_back(0);
	}

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << '\n';
	}

	return 0;
}