#include <iostream>
using namespace std;

int maze[4][4]={{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}};
int sol[4][4];

bool isSafe(int x,int y) {
    return x>=0&&x<4&&y>=0&&y<4&&maze[x][y]==1;
}

bool solve(int x,int y) {
    if(x==2&&y==0) {
        sol[x][y]=1;
        return true;
    }
    if(isSafe(x,y)) {
        if(sol[x][y]==1) return false;
        sol[x][y]=1;
        if(solve(x+1,y)) return true;
        if(solve(x,y+1)) return true;
        if(solve(x-1,y)) return true;
        if(solve(x,y-1)) return true;
        sol[x][y]=0;
        return false;
    }
    return false;
}

int main() {
    if(solve(0,0)) {
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
}
