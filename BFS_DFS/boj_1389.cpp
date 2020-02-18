#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>

int  n, m;
std::vector<std::vector<int> > relation;
std::vector<std::pair<int, int> > result;

void find(int init) {
	
	std::deque<int> que;
	int visited[101];
	memset(visited, -1, sizeof(visited));

	que.push_back(init);
	visited[init] = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop_front();

		for (int i = 0; i < relation[cur].size(); i++) {
			if (visited[relation[cur][i]] < 0) {
				que.push_back(relation[cur][i]);
				visited[relation[cur][i]] =  visited[cur] + 1;	
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += visited[i];
	}
	result.push_back(std::make_pair(init, sum));
}

bool comp(std::pair<int,int> a, std::pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}


int main() {
	
	std::cin >> n >> m;
	
	relation = std::vector<std::vector<int> >(n + 1);
	
	for (int i = 0; i < m; i++) {
		int rel1, rel2;
		std::cin >> rel1 >> rel2;
		relation[rel1].push_back(rel2);
		relation[rel2].push_back(rel1);
	}

	for (int i = 1; i <= n; i++) {
		find(i);
	}

	std::sort(result.begin(), result.end(), comp);
	std::cout << result.front().first;

	return 0;
}