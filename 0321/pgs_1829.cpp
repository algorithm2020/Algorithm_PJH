#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int M, N;
int dir[4][2] ={{-1,0}, {0,1}, {1,0}, {0,-1} };

int bfs(int i, int j,const vector<vector<int>> pic, bool visited[][101]){
    queue<pair<int,int>> q;
    int arangeVal = pic[i][j];
    int area = 0;
    visited[i][j] = true;
    q.push(make_pair(i,j));
    
    while(!q.empty()){
        area++;
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();  
        for(int i =0; i< 4; i++){
        int nextY = curY + dir[i][0];
        int nextX = curX + dir[i][1];
        
        if(nextY >= 0 && nextY <M && nextX >=0 && nextX <N ){
            if( !visited[nextY][nextX] && arangeVal == pic[nextY][nextX]){
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY, nextX));
            }
        }
    }
    
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int temp = 0;
    M = m;
    N= n;
     bool visited[101][101] = {0,};
    for(int i =0; i < m; i++){
        for(int j =0; j< n; j++){
            if(picture[i][j]!=0 && !visited[i][j]){
                number_of_area++;
                temp = bfs(i,j,picture, visited);
                max_size_of_one_area = (max_size_of_one_area < temp) ? temp : max_size_of_one_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] =  number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}