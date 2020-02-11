#include <iostream>
#include <vector>

int r, c; 
char arr[20][20];
bool visited[20][20] = {false,};
bool checked[26] = {false,};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int res =0;

bool isRanged(int y, int x) {
	return ((y >= 0 && y < r) && (x >= 0 && x < c));
}

int toInt(char a){
    return (int)a - 'A';
}

void print(int y, int x){
    for(int i =0; i< r; i++){
        for(int j =0; j< c; j++){
            std::cout << visited[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i =0; i< 26; i++){
        std::cout << checked[i];
    }

    std::cout << std::endl;
    std::cout << y << x << std::endl;
}

void dfs(int curY, int curX, int cnt){
    if(checked[toInt(arr[curY][curX])]){
        res = (res < cnt ) ? cnt : res;
        return;
    }
    checked[toInt(arr[curY][curX])] = true;
    for(int i =0; i<4; i++){
        int nextY = curY + dir[i][0];
        int nextX = curX + dir[i][1];

        if(isRanged(nextY, nextY) && !visited[nextY][nextX]){
            visited[nextY][nextX] = true;
            print(nextY, nextX);
            dfs(nextY, nextX, cnt + 1 );
            visited[nextY][nextX] = false;
        }
    }
    checked[toInt(arr[curY][curX])] = false;
}

int main(){
    
    std::cin >> r >> c;

    for(int i =0; i< r; i++){
        for(int j =0; j< c; j++){
            std::cin >> arr[i][j];
        }
    }
    visited[0][0] = true;
    dfs(0,0,0);
    std::cout << res;
    return 0;
}