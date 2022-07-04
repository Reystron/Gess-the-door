// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using std::cout;
using std::cin;

int wins = 0;
int total = 0;
class door {
public:
    int status;
    int user;
    int game;
    door(int Game = 0, int n = 0, int Player = 0) {
        game = Game;
        status = n;
        user = Player;
    }
    std::string getL() {
        if (status == 0)
            return " ";
        else if (status == 1)
            return "_";
        else if (status == 2)
            return "X";
        else if (status == 3)
            return ":";
        else
            return "$";
    }
    void userGuess(int mod) {
        if (status != 2) {
            status = mod;
            user = mod;
        }
    }
    void open(int right) {
        if (right) {
            if (game == 2)
                status = 2;
        }
        else {
            if (user != 1 && game!=1)
                status = 2;
        }
    }
    void openFinal() {
        if (user == 1) {
            if (game == 1)
                status = 4;
            else
                status = 3;
        }
        else {
            if (game == 1)
                status = 4;
            else
                status = 2;
        }
    }
    void clear() {
        status = 0;
        user = 0;
        game = 0;
    }
};

void line();
void showLine(door door1, door door2, door door3);
void decision(door d1, door d2, door d3, int dec);
void play();
void showStats();
void rules();
void menu();

int main()
{
    int n;
    do {
        menu();
        cin >> n;
        switch (n) {
        case 1:
            system("cls");
            play();
            break;
        case 3:
            system("cls");
            rules();
            break;
        case 2:
            system("cls");
            showStats();
            break;
        case 4:
            break;
        }
    } while (n != 4);
}

void menu() {
    line();
    cout << "-----------GAME------------" << std::endl;
    line();
    cout << "1 - start new game" << std::endl;
    cout << "2 - show stats" << std::endl;
    cout << "3 - rules" << std::endl;
    cout << "4 - exit" << std::endl;
    line();
}

void play() {
    door d1;
    door d2;
    door d3;
    int ga1 = (rand() % 3) + 1;
    int ga2 = (rand() % 2);
    switch (ga1) {
    case 1:
        d1.game = 1;
        if (ga2 == 0)
            d2.game = 2;
        else
            d3.game = 2; break;
    case 2:
        d2.game = 1;
        if (ga2 == 0)
            d1.game = 2;
        else
            d3.game = 2; break;
    case 3:
        d3.game = 1;
        if (ga2 == 0)
            d2.game = 2;
        else
            d1.game = 2; break;
    }
    
    showLine(d1, d2, d3);
    cout << "guess where the prise is" << std::endl;
    line();
    int userGuess, openedDoor, n;
    bool right1 = 0;
    do {
        cin >> userGuess;
    } while (userGuess < 1 && userGuess > 3);
    system("cls");
    if (userGuess == ga1)
        right1 = 1;
    switch (userGuess) {
    case 1:
        d1.userGuess(1);
        d2.userGuess(0); 
        d3.userGuess(0); break;
    case 2:
        d2.userGuess(1);
        d1.userGuess(0); 
        d3.userGuess(0); break;
    case 3:
        d3.userGuess(1);
        d1.userGuess(0); 
        d2.userGuess(0); break;
    }

    showLine(d1, d2, d3);
    cout << "i open one of the doors" << std::endl;
    line();
    cout << "1 - OK" << std::endl;
    line();
    do {
        cin >> n;
    } while (n!=1);
    system("cls");
    d1.open(right1);
    d2.open(right1);
    d3.open(right1);
    if (d1.status == 2)
        openedDoor = 1;
    else if (d2.status == 2)
        openedDoor = 2;
    else
        openedDoor = 3;

    showLine(d1, d2, d3);
    cout << "would u change ur mind?" << std::endl;
    line();
    cout << "1 - YES" << std::endl;
    cout << "2 - NO" << std::endl;
    line();
    do {
        cin >> n;
    } while (n!=1 && n!=2);
    system("cls");
    
    if (n == 2) 
        showLine(d1, d2, d3);
    else
    {
        if (userGuess == 1) {
            d1.userGuess(0);
            d2.userGuess(1);
            d3.userGuess(1);
        }
        else if (userGuess == 2) {
            d1.userGuess(1);
            d2.userGuess(0);
            d3.userGuess(1);
        }
        else {
            d1.userGuess(1);
            d2.userGuess(1);
            d3.userGuess(0);
        }
        if (d1.user == 1)
            userGuess = 1;
        else if (d2.user == 1)
            userGuess = 2;
        else
            userGuess = 3;
        showLine(d1, d2, d3);
    }
    cout << "1- to see resulst press" << std::endl;
    line();
    do {
        cin >> n;
    } while (n != 1);
    system("cls");
    d1.openFinal();
    d2.openFinal();
    d3.openFinal();

    showLine(d1, d2, d3);
    if (userGuess == ga1) {
        cout << "winner winner chiken dinner" << std::endl;
        wins++;
    }
    else
        cout << "not today" << std::endl;
    line();
    cout << "1- back to menu" << std::endl;
    line();
    do {
        cin >> n;
    } while (n != 1);
    system("cls");
    d1.clear();
    d2.clear();
    d3.clear();
    total++;
}

void showLine(door door1, door door2, door door3) {
    line();
    cout << "    |" << door1.getL() << "|     |" << door2.getL() << "|     |" << door3.getL() << "|" << std::endl;
    line();
    line();
}

void line() {
    cout << "---------------------------" << std::endl;
}

void decision(door d1, door d2, door d3, int dec){
    switch (dec) {
        case 0:
            d1.user = 0;
            d1.user = 0;
            d1.user = 0; break;
        case 1:
            d1.user = 1;
            d1.user = 0;
            d1.user = 0; break;
        case 2:
            d2.user = 1;
            d2.status = 0;
            d2.user = 0; break;
        case 3:
            d3.user = 1;
            d3.status = 0;
            d3.user = 0; break;
    }
}

void rules() {
    int n;
    line();
    cout << "Rules:" << std::endl;
    line();
    line();
    cout << "1 - back" << std::endl;
    line();
    do {
        cin >> n;
    } while (n != 1);
    system("cls");
}

void showStats() {
    line();
    cout << "Stats:" << std::endl;
    line();
    cout << "Wins: " << wins << std::endl;
    cout << "Total: " << total << std::endl;
    if (total!=0)
        cout << "Winrate: " << float(wins) / float(total) * 100 << "%" << std::endl;
    else
        cout << "Winrate: -" << std::endl;
    line();
    cout << "1 - back" << std::endl;
    line();
    int n;
    do {
        cin >> n;
    } while (n != 1);
    system("cls");
}


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file