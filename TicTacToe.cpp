#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Initialize the game board as a vector of strings
vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

// Function to display the game board
void displayBoard() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to process a player's move
void playerMove(string player) {
    cout << player << "'s turn." << endl;
    cout << "Select a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1;
    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "Invalid or occupied position. Please choose another: ";
        cin >> position;
        position -= 1;
    }
    board[position] = player;
    displayBoard();
}

// Function to determine the game's status
string evaluateGame() {
    // Check for a winning combination
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != "-") ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != "-") ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != "-") ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != "-") ||
        (board[0] == board[4] && board[4] == board[8] && board[0] != "-") ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) {
        return "win";
    }
    // Check for a draw
    else if (count(board.begin(), board.end(), "-") == 0) {
        return "tie";
    }
    // Continue playing
    else {
        return "play";
    }
}

// Main game loop
int main() {
    displayBoard();
    string currentPlayer = "X";
    bool isGameOver = false;
    while (!isGameOver) {
        playerMove(currentPlayer);
        string result = evaluateGame();
        if (result == "win") {
            cout << currentPlayer << " wins!" << endl;
            isGameOver = true;
        } else if (result == "tie") {
            cout << "It's a draw!" << endl;
            isGameOver = true;
        } else {
            // Switch turns between players
            currentPlayer = (currentPlayer == "X") ? "O" : "X";
        }
    }
    return 0;
}
