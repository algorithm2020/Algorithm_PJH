#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

std::deque<std::deque<std::pair<int, int> > > tree;
std::deque <bool> visited;
int n;
int longlength = 0;
int farnode = 0;

void dfs(int curnode, int leng) {

	visited[curnode] = true;

	for (int i = 0; i < tree[curnode].size(); i++) {
		int nextnode = tree[curnode][i].first;
		if (visited[nextnode] != true) {
			int tmp = leng + tree[curnode][i].second;
			if (longlength < tmp) {
				longlength = tmp;
				farnode = nextnode;
			}
			dfs(nextnode, tmp);
		}
	}
}

int main() {
	scanf("%d", &n);

	tree = std::deque<std::deque<std::pair<int, int> > >(n + 1);
	visited = std::deque<bool>(n + 1, false);

	for (int i = 1; i < n; i++) {
		int v, u, e;
		scanf("%d %d %d", &v, &u, &e);
		tree[v].push_back(std::make_pair(u, e));
		tree[u].push_back(std::make_pair(v, e));
	}

	dfs(1, 0);
	visited = std::deque<bool>(n + 1, false);
	longlength = 0;
	dfs(farnode, 0);

	printf("%d", longlength);

	return 0;
}