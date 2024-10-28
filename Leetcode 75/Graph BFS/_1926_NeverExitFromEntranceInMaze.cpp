// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at. In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit. Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.





#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int ans=-1, maxi=INT_MAX, chk=1;
		vector<vector<int>>v(maze.size(), vector<int>(maze[0].size(), 0));
		queue<pair<pair<int, int>, int>>q;
		q.push({{entrance[0], entrance[1]}, 0});
		v[entrance[0]][entrance[1]]=1;
		int flag=1;
		while(!q.empty()){
			int x=q.front().first.first, y=q.front().first.second, cnt=q.front().second;
			q.pop();
			//cout<<cnt<<endl;
			if(flag==-1 && (x!=entrance[0] || y!=entrance[1]) && (x==0 || y==0 || x==maze.size()-1 || y==maze[0].size()-1)){maxi=min(maxi, cnt); chk=-1;}
			flag=-1;
			if(x>0 && !v[x-1][y] && maze[x-1][y]=='.'){
				v[x-1][y]=1;
				q.push({{x-1, y}, cnt+1});
				//if((x-1!=entrance[0] && y!=entrance[1]) && (x-1==0 || y==0 || x-1==maze.size()-1 || y==maze[0].size()-1)){maxi=min(maxi, cnt); chk=-1;}
			}
			
            if(y>0 && !v[x][y-1] && maze[x][y-1]=='.'){
				v[x][y-1]=1;
				q.push({{x, y-1}, cnt+1});
				//if((x!=entrance[0] && y-1!=entrance[1]) && (x==0 || y-1==0 || x==maze.size()-1 || y-1==maze[0].size()-1)){maxi=min(maxi, cnt); chk=-1;}
			}

			if(x<maze.size()-1 && !v[x+1][y] && maze[x+1][y]=='.'){
				v[x+1][y]=1;
				q.push({{x+1, y}, cnt+1});
				//if((x+1!=entrance[0] && y!=entrance[1]) && (x+1==0 || y==0 || x+1==maze.size()-1 || y==maze[0].size()-1)){maxi=min(maxi, cnt); chk=-1;}
			}

			if(y<maze[0].size()-1 && !v[x][y+1] && maze[x][y+1]=='.'){
				v[x][y+1]=1;
				q.push({{x, y+1}, cnt+1});
				//if((x!=entrance[0] && y+1!=entrance[1]) && (x==0 || y+1==0 || x==maze.size()-1 || y+1==maze[0].size()-1)){maxi=min(maxi, cnt); chk=-1;}
			}
		}
		//cout<<endl;
		if(chk==-1){return maxi;}
		return ans;
	}
};

int main() {
    Solution solution;
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };
    vector<int> entrance = {1, 2};
    int result = solution.nearestExit(maze, entrance);
    cout << "Nearest exit distance: " << result << endl;
    return 0;
}