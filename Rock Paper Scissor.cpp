#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Abstract base class
class Player {
public:
    virtual int makeChoice() = 0; // Pure virtual function
};

// Human player class
class Human : public Player {
public:
    int makeChoice() override {
        int choice;
        cout << "\nChoose:\n0: Rock\n1: Paper\n2: Scissors\nEnter your choice: ";
        cin >> choice;
        while (choice < 0 || choice > 2) {
            cout << "Invalid choice. Try again: ";
            cin >> choice;
        }
        return choice;
    }
};

// Computer player class
class Computer : public Player {
public:
    int makeChoice() override {
        return rand() % 3;
    }
};

// Game class
class RockPaperScissorsGame {
private:
    Human human;
    Computer computer;
    string options[3] = {"Rock", "Paper", "Scissors"};

public:
    void play() {
        int userChoice = human.makeChoice();
        int computerChoice = computer.makeChoice();

        cout << "\nYou chose: " << options[userChoice] << endl;
        cout << "Computer chose: " << options[computerChoice] << endl;

        if (userChoice == computerChoice) {
            cout << "Result: It's a tie!\n";
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            cout << "Result: You win!\n";
        } else {
            cout << "Result: You lose!\n";
        }
    }
};

int main() {
    srand(time(0));
    RockPaperScissorsGame game;
    char again;

    do {
        game.play();
        cout << "\nPlay again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
