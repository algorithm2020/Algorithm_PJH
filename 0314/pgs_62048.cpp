#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

long long solution(int w,int h)
{
	long long answer = 1;
    queue<pair<int,int> > que;
     int map[16000][16000];   
    int dir[2][2] = { { 0,1 }, {1,0} };
    
    long long total = (long long)w * (long long)h;
    long long g;
    if(w > h){
        g = gcd(w, h);   
    }
    else{
        g = gcd(h, w);   
    }

    /* 탐색하면 실패
    map[0][0] = 1;
    que.push(make_pair(0,0));

    while(!que.empty()){
        int curY = que.front().first;
        int curX = que.front().second;
        que.pop();
        
        if(curY == (h/g - 1) && curX == (w/g -1 ) ) {
            answer = total - map[curY][curX] * g;
            break;
        }
        
        for(int i =0; i < 2; i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            
            if( nextY >= 0 && nextY < h && nextX >= 0 && nextX < w){
                if(map[nextY][nextX] == 0){
                    map[nextY][nextX] =map[curY][curX] + 1;
                    que.push(make_pair(nextY, nextX));
                }
            }
        }
    }
    */
    answer = total - g * ((w / g) + (h / g) - 1);
	return answer;
}