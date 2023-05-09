// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 9, 2023
// Last Update: May 9, 2023
// Problem statement: File I/O

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define GAME_SIZE 4

using namespace std;

const char FILEPATH[] = "./words.txt";

typedef vector<vector<char>> Board_t;

// Indent: Check if the word in the board
// Pre: The variable board is the char vector, word is target word, x and y are
//      current position, index is the current word index
// Post: The function returns true if the word is in the board
bool _checkWordInBoardUtil(Board_t &board, const string &word, int x, int y,
                           size_t index = 0)
{
    if ( word.size() > (board.size() * board[0].size()) )
        return false;

    if ( index > word.size() - 1 )
        return true;

    char cc = word[index];
    for ( int i = y - 1; i < y + 2; ++i )
    {
        for ( int j = x - 1; j < x + 2; ++j )
        {

            if ( (i < 0 || i > board.size() - 1) ||
                 (j < 0 || j > board[i].size() - 1) )
                continue;

            if ( board[i][j] == cc )
            {
                board[i][j] = '\0';
                if ( _checkWordInBoardUtil(board, word, j, i, index + 1) )
                    return true;
            }
        }
    }

    return false;
}

// Indent: Check if the word in the board
// Pre: The variable board is the char vector, word is target word
// Post: The function returns true if the word is in the board
bool checkWordInBoard(const Board_t &board, const string &word)
{
    for ( int i = 0; i < board.size(); ++i )
    {
        for ( int j = 0; j < board[i].size(); ++j )
        {
            if ( board[i][j] == word[0] )
            {
                Board_t tmp = board;
                if ( _checkWordInBoardUtil(tmp, word, j, i) )
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<string> words;

    ifstream ifs;

    // Try to open the words file
    ifs.open(FILEPATH);
    if ( !ifs.is_open() )
    {
        cout << "Error: Couldn't open " << FILEPATH << " for reading" << endl;
        return 1;
    }

    // Read words into vector
    for ( string str; (ifs >> str) && !ifs.eof(); )
        words.push_back(str);

    for ( ;; )
    {
        Board_t board(GAME_SIZE, vector<char>(GAME_SIZE, '\0'));
        for ( size_t i = 0; i < GAME_SIZE; ++i )
        {
            string str;
            if ( !(cin >> str) || cin.eof() )
                return 0;

            for ( size_t j = 0; j < GAME_SIZE; ++j )
                board[i][j] = str[j];
        }
        for ( const string &w : words )
        {
            if ( checkWordInBoard(board, w) )
                cout << w << endl;
        }
    }

    return 0;
}