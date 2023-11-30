#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// Functions
void map(void);
void play(int);
void showMainMenu(void);

// Global Variables
const short int rows = 5;
const short int cols = 5;
const short int numberOfOnes = 5;
char mapMain[rows][cols];
char mapCopy[rows][cols];

// MAIN
int main()
{
    system("cls");
    int turns = 10;
    char mainOption;
    char innerOption;
    while (true)
    {

        showMainMenu();
        mainOption = getche();
        system("cls");

        switch (mainOption)
        {
        case '1':
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    mapMain[i][j] = ' ';
                    mapCopy[i][j] = ' ';
                }
            }
            // Initial Mapping
            map();
            srand(time(0));
            // Spread Random Boats on Map
            for (int i = 0; i < numberOfOnes; ++i)
            {
                int row, col;
                do
                {
                    row = rand() % rows;
                    col = rand() % cols;
                } while (mapMain[row][col] == '1');

                mapMain[row][col] = '1';
            }
            // Play Area
            cout << "Captain, you have " << turns << " cannonballs, ENGAGE PRECISELY!" << endl;
            play(turns);
            break;
        case '2':
            cout << "Not released yet.\n\nPress any key to go back =>";
            innerOption = getche();
            system("cls");
            break;
        case '3':
            cout << "\nINSTRUCTIONS:\n\nA number of ships will randomly be placed on the map. \n\nThe player controls a cannon with using RC(Row Column) coordinates. The goal is to shoot down the ships one by one. \n\nResulting score will be based on the number of ships sunk. \n\nGood Luck, Captain!\n\nPress any key to go back =>";
            innerOption = getche();
            system("cls");
            break;
        default:
            break;
        }
    }
    return 0;
}

// MENU

void showMainMenu()
{
    cout << "\nBattleship : Search and Destroy!\n\n";
    cout << "\nMain Menu (Select an option)\n\n";
    cout << "1. Single Player\n\n";
    cout << "2. Multi Player (Coming Soon)\n\n";
    cout << "3. How To Play\n\n";
}

// MAP

void map()
{
    system("cls");
    cout << endl;

    // Column Count
    cout << "\t    ";
    for (int j = 1; j <= cols; j++)
    {
        cout << j << "   ";
    }
    cout << endl
         << endl;

    for (int i = 0; i < rows; i++)
    {
        // Row Count
        cout << "\t" << i + 1 << "   ";

        // Print Row
        for (int j = 0; j < cols; j++)
        {
            cout << mapCopy[i][j] << " | ";
        }

        // Print Dashes
        cout << endl
             << "\t    ";
        if (i < rows - 1)
        {
            for (int j = 0; j < (cols * 4) - 1; j++)
            {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// PLAY

void play(int turns)
{
    int score = 0;

    while (turns > 0)
    {
        int a, b;
        cout << "Loading the Cannon...\n";
        cout << "Enter coordinates to shoot! [for example: 1 2 ] : ";
        cin >> a >> b;
        if (a > 0)
        {
            a--;
        }
        if (b > 0)
        {
            b--;
        }
        if (mapMain[a][b] == '1')
        {
            mapCopy[a][b] = 'X';
            score++;
        }
        else if (mapCopy[a][b] = 'X'){
            
        }
        else
        {
            mapCopy[a][b] = 'O';
        }

        turns--;
        map();
        cout << "Score : " << score << "\n\n";
    }
}
