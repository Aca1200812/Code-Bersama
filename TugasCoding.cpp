#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& maze, int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}


bool solveMazeUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol, int N) {
    
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    
    if (isSafe(maze, x, y, N)) {
        
        sol[x][y] = 1;

        
        if (solveMazeUtil(maze, x, y + 1, sol, N)) {
            return true;
        }

        
        if (solveMazeUtil(maze, x + 1, y, sol, N)) {
            return true;
        }

       
        sol[x][y] = 0;
        return false;
    }

    return false;
}


bool solveMaze(vector<vector<int>>& maze, int N) {
    vector<vector<int>> sol(N, vector<int>(N, 0));

    if (solveMazeUtil(maze, 0, 0, sol, N)) {
        cout << "Solution exists! Path:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    } else {
        cout << "No solution exists!" << endl;
        return false;
    }
}


int main() {
    
    vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    cout << "Example 1: 4x4 Maze" << endl;
    cout << "Maze layout:" << endl;
    for (auto& row : maze1) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;

    solveMaze(maze1, 4);

    cout << endl;

    
    vector<vector<int>> maze2 = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {0, 0, 1, 1}
    };

    cout << "Example 2: 4x4 Maze" << endl;
    cout << "Maze layout:" << endl;
    for (auto& row : maze2) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;

    solveMaze(maze2, 4);

    return 0;
}
