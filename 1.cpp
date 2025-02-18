#include <iostream>
#include <vector>
#include <array>

const int N = 10; // Розмір сітки

struct Cell {
    char type; // '.', 'W', 'B'
    bool visited;
    int path; // 0 - немає, 1 - вертикальна лінія, 2 - горизонтальна лінія
};

std::array<std::array<Cell, N>, N> grid;

bool inBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void printGrid() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j].path == 1) std::cout << '|';
            else if (grid[i][j].path == 2) std::cout << '-';
            else std::cout << grid[i][j].type;
        }
        std::cout << std::endl;
    }
}

bool isValid(int x, int y, int px, int py, int direction) {
    if (!inBounds(x, y) || grid[x][y].visited) return false;
    if (grid[x][y].type == 'W' && px != -1 && py != -1) {
        if ((px != x && py != y)) return false;
    }
    if (grid[x][y].type == 'B' && px != -1 && py != -1) {
        if ((px == x && py == y - 1 && direction != 2) || (px == x && py == y + 1 && direction != 2) || (px == x - 1 && py == y && direction != 1) || (px == x + 1 && py == y && direction != 1)) {
            return false;
        }
    }
    return true;
}

bool dfs(int x, int y, int startX, int startY, int px, int py) {
    if (grid[x][y].visited) {
        return x == startX && y == startY;
    }

    grid[x][y].visited = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int pathType[] = {1, 1, 2, 2};

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx == px && ny == py) continue;

        if (isValid(nx, ny, x, y, pathType[i])) {
            grid[x][y].path = pathType[i];

            if (dfs(nx, ny, startX, startY, x, y)) {
                return true;
            }

            grid[x][y].path = 0;
        }
    }

    grid[x][y].visited = false;
    return false;
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = {'.', false, 0};
        }
    }

    // Розставлення чорних і білих кіл відповідно до фото
    // Приклад (необхідно заповнити згідно з тестовим завданням №1):
    grid[1][1].type = 'W';
    grid[3][3].type = 'B';

    // Пошук циклу
    bool found = false;
    for (int i = 0; i < N && !found; ++i) {
        for (int j = 0; j < N && !found; ++j) {
            if (dfs(i, j, i, j, -1, -1)) {
                found = true;
            }
        }
    }

    if (found) {
        printGrid();
    } else {
        std::cout << "Рішення не знайдено" << std::endl;
    }


    return 0;
}
