#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// Functions
void showMainMenu(void);
void map(void);
void resetMap(void);
void singlePlay(int);
void compPlay(int);

// Global Variables
const short int rows = 5;
const short int cols = 5;
short int numberofBoats = 5;
short int boatsLeft = numberofBoats;
char mapMain[rows][cols];
char mapCopy[rows][cols];

// MAIN
int main()
{
    system("cls");
    srand(time(0));
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

            singlePlay(turns);
            break;

        case '2':
            cout << "Not released yet.\n\nPress any key to go back =>";
            innerOption = getche();
            system("cls");
            break;

        case '3':

            compPlay(turns);
            break;
        case '4':
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
    cout << "3. VS Computer (New Mode)\n\n";
    cout << "4. How To Play\n\n";
}

// RESET MAP

void resetMap()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mapMain[i][j] = ' ';
            mapCopy[i][j] = ' ';
        }
    }
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

// SINGLE PLAY

void singlePlay(int turns)
{
    resetMap();
    map();
    // reset the boats from other rounds
    boatsLeft = numberofBoats;
    for (int i = 0; i < numberofBoats; ++i)
    {
        int row, col;
        do
        {
            row = rand() % rows;
            col = rand() % cols;
        } while (mapMain[row][col] == '1');

        mapMain[row][col] = '1';
    }
    cout << "Captain, you have " << turns << " cannonballs and " << numberofBoats << " targets. ENGAGE PRECISELY!" << endl;
    short int score = 0;

    while (turns > 0 && boatsLeft > 0)
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
        if (mapCopy[a][b] == 'X')
        {
            mapCopy[a][b] = 'X';
        }
        else if (mapMain[a][b] == '1')
        {
            mapCopy[a][b] = 'X';
            score++;
            boatsLeft--;
        }
        else
        {
            mapCopy[a][b] = 'O';
        }

        turns--;
        map();
        cout << "Score : " << score << "\n\n";
        cout << "Boats left: " << boatsLeft << "\n\n";
        cout << "Turns left: " << turns << "\n\n";
    }
}

// VS COMP

void compPlay(int turns)
{
    resetMap();
    // reset the boats from other rounds
    boatsLeft = numberofBoats;
    short int score = 0;
    int row, col;
    do
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
                cout << mapMain[i][j] << " | ";
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
        cout << "Enter boats to place [for example 1 2] : ";
        cin >> row >> col;

        row--;
        col--;
        if (mapMain[row][col] == '1')
        {
            cout << "Boat already exist in that place, place again => ";
            int nextOption;
            nextOption = getch();

            continue;
        }
        mapMain[row][col] = '1';
        boatsLeft--;
    } while (boatsLeft != 0);

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
            cout << mapMain[i][j] << " | ";
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

    turns = 10;
    boatsLeft = numberofBoats;
    cout << "\nStart computer's turn => ";
    int nextOption;
    nextOption = getch();
    while (turns > 0)
    {
        int a, b;
        do
        {
            a = rand() % rows;
            b = rand() % cols;
        } while (mapCopy[a][b] == 'X' || mapCopy[a][b] == 'O');

        if (mapMain[a][b] == '1')
        {
            mapCopy[a][b] = 'X';
            score++;
            boatsLeft--;
            turns--;
        }
        else
        {
            mapCopy[a][b] = 'O';
            turns--;
        }

        map();
        cout << "Score : " << score << "\n\n";
        cout << "Boats left: " << boatsLeft << "\n\n";
        cout << "Turns left: " << turns << "\n\n";
        cout << "Press any key to advance => ";
        nextOption = getch();
    }

    if (boatsLeft == 0 && turns >= 0)
    {
        cout << "\nYou lost, try again!\n";
    }
    else
    {
        cout << "\n\nCongratulations, you won\n\n";
    }
}