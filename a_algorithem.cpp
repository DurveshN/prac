#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

struct Node {
    int x, y;
    int g, h, f;
    Node* parent;

    Node(int x, int y) {
        this->x = x;
        this->y = y;
        g = h = f = 0;
        parent = NULL;
    }
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};


bool isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}


bool isUnBlocked(int grid[ROW][COL], int x, int y) {
    return grid[x][y] == 0;
}


int calculateH(int x, int y, int goalX, int goalY) {
    return abs(x - goalX) + abs(y - goalY);
}


void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    cout << "(" << node->x << "," << node->y << ") ";
}


void aStar(int grid[ROW][COL], pair<int,int> start, pair<int,int> goal) {
    
    priority_queue<Node*, vector<Node*>, Compare> openList;

    bool closedList[ROW][COL] = {false};

    Node* startNode = new Node(start.first, start.second);
    openList.push(startNode);

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        int x = current->x;
        int y = current->y;

        closedList[x][y] = true;

        
        if (x == goal.first && y == goal.second) {
            cout << "Path found:\n";
            printPath(current);
            return;
        }

      
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY) && isUnBlocked(grid, newX, newY) && !closedList[newX][newY]) {
                
                Node* neighbor = new Node(newX, newY);

                neighbor->g = current->g + 1;
                neighbor->h = calculateH(newX, newY, goal.first, goal.second);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;

                openList.push(neighbor);
            }
        }
    }

    cout << "No path found.\n";
}


int main() {
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    pair<int,int> start = {0, 0};
    pair<int,int> goal = {4, 4};

    aStar(grid, start, goal);

    return 0;
}
