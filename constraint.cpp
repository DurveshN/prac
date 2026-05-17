#include <iostream>
#include <vector>
using namespace std;

class NQueens {
    int N;
    vector<vector<int>> board;

public:
    NQueens(int n) {
        N = n;
        board.resize(N, vector<int>(N, 0));
    }

   
    bool isSafe(int row, int col) {
        
        for (int i = 0; i < col; i++)
            if (board[row][i])
                return false;

      
        for (int i=row, j=col; i>=0 && j>=0; i--, j--)
            if (board[i][j])
                return false;

        
        for (int i=row, j=col; i<N && j>=0; i++, j--)
            if (board[i][j])
                return false;

        return true;
    }

    
    bool solve(int col) {
        if (col >= N)
            return true;

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;

                if (solve(col + 1))
                    return true;

               
                board[i][col] = 0;
            }
        }
        return false;
    }

    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    NQueens obj(n);

    if (obj.solve(0)) {
        cout << "Solution:\n";
        obj.printSolution();
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
