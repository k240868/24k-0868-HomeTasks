#include <iostream>

using namespace std;

#define N 5

int grid[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

int visited[N][N] = {0};

bool isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && grid[x][y] == 1 && visited[x][y] == 0);
}

bool findPaths(int x, int y, int foodX, int foodY, int path[][2], int& pathIndex) {
    if (x == foodX && y == foodY) {
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

        if (findPaths(x + 1, y, foodX, foodY, path, pathIndex)) {
            return true;
        }
        if (findPaths(x, y + 1, foodX, foodY, path, pathIndex)) {
            return true;
        }
        if (findPaths(x - 1, y, foodX, foodY, path, pathIndex)) {
            return true;
        }
        if (findPaths(x, y - 1, foodX, foodY, path, pathIndex)) {
            return true;
        }

        pathIndex--;
        visited[x][y] = 0;
    }
    return false;
}

void printPath(int path[][2], int pathIndex) {
    for (int i = 0; i < pathIndex; i++) {
        cout << "(" << path[i][0] << ", " << path[i][1] << ") ";
    }
    cout << endl;
}

int main() {
    int rabbitPath[N * N][2];
    int catPath[N * N][2];
    int rabbitPathIndex = 0;
    int catPathIndex = 0;

    if (findPaths(0, 0, 2, 2, rabbitPath, rabbitPathIndex)) {
        cout << "Rabbit's Path: ";
        printPath(rabbitPath, rabbitPathIndex);
    } else {
        cout << "No path found for the rabbit!" << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    if (findPaths(4, 4, 2, 2, catPath, catPathIndex)) {
        cout << "Cat's Path: ";
        printPath(catPath, catPathIndex);
    } else {
        cout << "No path found for the cat!" << endl;
    }

    cout << "Intersection Points: ";
    bool intersectionFound = false;
    for (int i = 0; i < rabbitPathIndex; i++) {
        for (int j = 0; j < catPathIndex; j++) {
            if (rabbitPath[i][0] == catPath[j][0] && rabbitPath[i][1] == catPath[j][1]) {
                cout << "(" << rabbitPath[i][0] << ", " << rabbitPath[i][1] << ") ";
                intersectionFound = true;
            }
        }
    }
    if (!intersectionFound) {
        cout << "No intersections found.";
    }
    cout << endl;

    return 0;
}
