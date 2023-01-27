
#include <iostream>
#include <tuple>

using namespace std;
class TicTacToeGame
{
public:
    TicTacToeGame();
    virtual ~TicTacToeGame();

    void play();

    private:
        void initializeGird();
        void displayGrid();
        tuple<int, int> findFirstUnoccupiesSqaure(); //computer move
        tuple<int, int> promptForGridCoord();   //user moves
        bool checkForDraw();
        bool checkForWin();

    private:
        char** pp_cGrid = nullptr; //pointer to (pointer to character)
};

TicTacToeGame::TicTacToeGame()
{
    this->pp_cGrid = new char* [3];

    for (int iRow = 0; iRow < 3; ++iRow)
        pp_cGrid[iRow] = new char[3];

    //more code to be inserted a little later
    initializeGird();
}

TicTacToeGame::~TicTacToeGame()
{
    for (int iRow = 0; iRow < 3; ++iRow) {
        delete[] pp_cGrid[iRow]; //delete arrays of 3 characters
    }
    delete[] pp_cGrid; //delete array of three pointers to characters
    pp_cGrid = nullptr;
}

void TicTacToeGame::initializeGird()
{
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            this->pp_cGrid[iRow][iColumn] = '~';
        }
    }
}

void TicTacToeGame::displayGrid()
{
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            cout << this->pp_cGrid[iRow][iColumn] << " ";
        }
        cout << endl;
    }
}

tuple<int, int> TicTacToeGame::promptForGridCoord()
{
    int iRow = 0;
    int iColumn = 0;

    cout << "Please enter grid row number: " << endl;
    cin >> iRow;

    cout << "Please enter grid column number: " << endl;
    cin >> iColumn;
    cout << endl;

    tuple <int, int> tupleCoord = make_tuple(iRow, iColumn);

    return tupleCoord;
}

tuple<int, int> TicTacToeGame::findFirstUnoccupiesSqaure()
{
    int iRowUnoccupied = 0;
    int iColumnUnoccupied = 0;

    bool bFound = false;

    for (int iRow = 0; (iRow < 3) && !bFound; iRow++)
    {
        for (int iColumn = 0; (iColumn < 3) && !bFound; iColumn++)
        {
            if (this->pp_cGrid[iRow][iColumn] == '~')
            {
                iRowUnoccupied = iRow;
                iColumnUnoccupied = iColumn;
                bFound = true;
            }
        }
    }

    tuple<int, int> tupleUnoccupiedGridSquare(iRowUnoccupied, iColumnUnoccupied);
    return tupleUnoccupiedGridSquare;
}

bool TicTacToeGame::checkForDraw()
{
    bool bContinue = false;
    
    //checking the game is in continue mode or not
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            if (this->pp_cGrid[iRow][iColumn] != 'O' && this->pp_cGrid[iRow][iColumn] != 'X')
                bContinue = true;
        }
    }

    return !bContinue;
}

bool TicTacToeGame::checkForWin()
{
    bool bWin = false;

    for (int iRow = 0; (iRow < 3) && !bWin; iRow++) {
        if (this->pp_cGrid[iRow][0] != '~') 
        {
            if ((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) && (this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][2]))
            {
                bWin = true;
                cout << "WINNER: " << this->pp_cGrid[iRow][0] << "!" << endl;
            }
        }
    }

    for (int iColumn = 0; (iColumn < 3) && !bWin; iColumn++)
    {
        if (this->pp_cGrid[0][iColumn] != '~')
        {
            if ((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) && (this->pp_cGrid[0][iColumn] == this->pp_cGrid[2][iColumn]))
            {
                bWin = true;
                cout << "WINNER: " << this->pp_cGrid[0][iColumn] << "!" << endl;
            }
        }
    }

    if (this->pp_cGrid[0][0] != '~') {
        if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][0] == this->pp_cGrid[2][2]))
        {
            bWin = true;
            cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << endl;
        }
    }

    if (this->pp_cGrid[0][2] != '~') {
        if ((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][2] == this->pp_cGrid[2][0]))
        {
            bWin = true;
            cout << "WINNER: " << this->pp_cGrid[0][2] << "!" << endl;
        }
    }
    
    return bWin;
}

void TicTacToeGame::play() 
{
    bool bWin = false;
    bool bDraw = false;
    int iRow = 0;
    int iColumn = 0;

    cout << "Tic Tac Toe" << endl;
    cout << endl;

    displayGrid();

    while (!bWin && !bDraw)
    {
        //human player turn
        tie(iRow, iColumn) = promptForGridCoord();
        this->pp_cGrid[iRow][iColumn] = 'X';

        displayGrid();
        bWin = checkForWin();
        bDraw = checkForDraw();

        //computer player turn
        if (!bWin and !bDraw)
        {
            cout << endl;
            tie(iRow, iColumn) = findFirstUnoccupiesSqaure();
            this->pp_cGrid[iRow][iColumn] = 'O';
            displayGrid();
            bWin = checkForWin();
            bDraw = checkForDraw();
        }

        if (bDraw && !bWin)
        {
            cout << "Draw! " << endl;
        }
    }

    cout << "Game over." << endl;
    return;
}

int main() 
{
    TicTacToeGame* p_game = new TicTacToeGame();
    
    p_game->play();

    delete p_game;
}