#include <iostream>
#include <vector>
#include <queue>

int n, m, t;
std::queue<int> truth;
std::vector<std::vector<int> >party;
std::vector<std::vector<int> >people;
bool peCheck[51];
bool paCheck[51];

void recur(int peNum) {
	for (int i = 0; i < people[peNum].size(); i++) {
		int paNum = people[peNum][i];
		paCheck[paNum] = true;
		for (int j = 0; j < party[paNum].size(); j++) {
			if (!peCheck[party[paNum][j]]) {
				truth.push(party[paNum][j]);
			}
		}
	}
}

int main() {
		
	std::cin >> n >> m >> t;

	for (int i = 0; i < t; i++) {
		int temp;
		std::cin >> temp;
		truth.push(temp);
	}

	party = std::vector<std::vector<int> >(m + 1);
	people = std::vector<std::vector<int> >(n + 1);

	for (int i = 0; i < m; i++) {
		int temp;
		std::cin >> temp;
		for (int j = 0; j < temp; j++) {
			int temp2;
			std::cin >> temp2;
			party[i].push_back(temp2);
			people[temp2].push_back(i);
		}
	}

	if (t == 0) {
		std::cout << m;
		return 0;
	}

	while (!truth.empty()) {
		int peNum = truth.front();
		peCheck[peNum] = true;
		recur(peNum);
		truth.pop();
	}
	
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!paCheck[i]) cnt++;
	}

	std::cout << cnt;
	
	return 0;
}
