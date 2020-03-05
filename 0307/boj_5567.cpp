#include <iostream>
#include <vector>
#include <queue>

int n, m;
std::vector<std::vector<int> > relation;
bool visited[501];

int bfs() {
	int cnt = 0;
	std::queue<int> que;
	visited[1] = true;

	for (int i = 0; i < relation[1].size(); i++) {
		que.push(relation[1][i]);
		visited[relation[1][i]] = true;
		cnt++;
	}
	
	while (!que.empty()) {
		int curNum = que.front();
		que.pop();

		for (int i = 0; i < relation[curNum].size(); i++) {
			if (!visited[relation[curNum][i]]) {
				visited[relation[curNum][i]] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	std::cin >> n >> m;

	relation = std::vector<std::vector<int> >(n + 1);

	for (int i = 0; i < m; i++) {
		int s, f;
		std::cin >> s >> f;
		relation[s].push_back(f);
		relation[f].push_back(s);
	}
	
	std::cout << bfs();

	return 0;
    
}