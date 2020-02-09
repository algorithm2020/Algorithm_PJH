
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

char arr[15];
int L, C;
bool visited[15] = { false, };
std::string finded;
std::vector<std::string> res;

bool isahdma(int val) {
	if (val == (int)'a' || val == (int)'e' || val == (int)'i' || val == (int)'o' || val == (int)'u') return true;
	else return false;
}

void backtracking(int cur ,int depth, int m, int j) {
	int m_cnt = 0;
	int j_cnt = 0;
	if (depth == L - 1) {
		if(m >=1 && j >= 2) res.push_back(finded);
		return;
	}
	

	for (int i = 0; i < C; i++) {
		if (visited[i]) continue;
		if ((int)arr[cur] > (int)arr[i]) continue;


		if (isahdma(arr[i])) {m_cnt = 1; j_cnt = 0;}
		else {j_cnt = 1; m_cnt = 0;}

		finded.push_back(arr[i]);
		visited[i] = true;
		backtracking(i, depth+1, m + m_cnt, j + j_cnt);
		visited[i] = false;
		finded.pop_back();
	}	
}

bool comp(std::string a, std::string b) {
	return a < b;
}

int main() {
	std::cin >> L >> C;

	for (int i = 0; i < C; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < C; i++) {
		int m_cnt = 0;
		int j_cnt = 0;
		if (isahdma(arr[i])) m_cnt = 1;
		else j_cnt = 1;
		visited[i] = true;
		finded.push_back(arr[i]);
		backtracking(i, 0, m_cnt, j_cnt);
		finded.pop_back();
		visited[i] = false;
	}
	sort(res.begin(), res.end(), comp);
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << '\n';
	}
	
	return 0;
}

