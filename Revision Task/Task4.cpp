#include <iostream>

using namespace std;

#define N 4

int maze[N][N] = {
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 1, 0, 1},
    {0, 1, 1, 1}
};

int visited[N][N] = {0};

bool isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

bool findEscapePath(int x, int y, int path[][2], int& pathIndex) {
    if (x == N - 1 && y == N - 1) {
        path[pathIndex][0] = x;
        path[pathIndex][1] = y;
        pathIndex++;
        return true;
    }

    if (isSafe(x, y)) {
        visited[x][y] = 1;
        path[pathIndex][0] = x;
        path[pathIndex][1] = y;
        pathIndex++;

        if (findEscapePath(x + 1, y, path, pathIndex)) {
            return true;
        }
        if (findEscapePath(x, y + 1, path, pathIndex)) {
            return true;
        }
        if (findEscapePath(x - 1, y, path, pathIndex)) {
            return true;
        }
        if (findEscapePath(x, y - 1, path, pathIndex)) {
            return true;
        }

        pathIndex--;
        visited[x][y] = 0;
    }
    return false;
}

int main() {
    int path[N * N][2];
    int pathIndex = 0;

    if (findEscapePath(0, 0, path, pathIndex)) {
        cout << "Escape path found: ";
        for (int i = 0; i < pathIndex; i++) {
            cout << "(" << path[i][0] << ", " << path[i][1] << ") ";
        }
    } else {
        cout << "No safe escape path exists.";
    }

    return 0;
}
