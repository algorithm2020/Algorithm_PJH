#include <iostream>
#include <vector>
#include <cstring>

std::vector<std::vector<int> > relation;
bool visited[2001] = { false, };
std::vector<int> res;
int n, m;

int find(int cur) {
	visited[cur] = true;
	res.push_back(cur);
	if (res.size() >= 5) {
		return 1;
	}
	
	for (int i = 0; i < relation[cur].size(); i++) {
		int next = relation[cur][i];
	
		if (!visited[next]) {
			int returnVal = find(next);
			if (returnVal == 1) {
				return 1;
			}
		}
	}
	res.pop_back();
	visited[cur] = false;
	return -1;
}


int main() {
	std::cin >> n >> m;
	relation = std::vector<std::vector<int> >(n + 1);
	for (int i = 0; i < m; i++) {
		int front, back;
		std::cin >> front >> back;
		relation[front].push_back(back);
		relation[back].push_back(front);
	}
	int returnVal;
	for (int i = 0; i < n; i++) {
		if (relation[i].size() != 0) {
			returnVal = find(i);
			if(returnVal == 1) break;
			else {
				memset(visited, 0, sizeof(visited));
				res.clear();
			}
		}
	}
	
	if (returnVal == 1) {
		std::cout << 1;
	}
	else {
		std::cout << 0;
	}
	
	return 0;
} 