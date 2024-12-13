#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_GAMES = 5;  


void playGame(int& playerScore, int& computerScore);
int getComputerChoice();
void displayChoice(int choice);
void displayMenu();
string getWinner(int playerChoice, int computerChoice);

int main() {
    srand(static_cast<unsigned int>(time(0)));  

    int playerTotalScore = 0;
    int computerTotalScore = 0;

    int bestPlayerScore = 0;
    int bestComputerScore = 0;

   
    int scores[NUM_GAMES][2];  

    
    for (int game = 0; game < NUM_GAMES; ++game) {
        int playerScore = 0, computerScore = 0;

        
        playGame(playerScore, computerScore);

        
        scores[game][0] = playerScore;
        scores[game][1] = computerScore;

        
        playerTotalScore += playerScore;
        computerTotalScore += computerScore;

        
        if (playerScore > bestPlayerScore) {
            bestPlayerScore = playerScore;
        }
        if (computerScore > bestComputerScore) {
            bestComputerScore = computerScore;
        }

        
        cout << "Game " << (game + 1) << " result: ";
        if (playerScore > computerScore) {
            cout << "Player wins!" << endl;
        } else if (computerScore > playerScore) {
            cout << "Computer wins!" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
        cout << endl;
    }

    
    cout << "Final Results:" << endl;
    cout << "Total Player Score: " << playerTotalScore << endl;
    cout << "Total Computer Score: " << computerTotalScore << endl;
    cout << "Best Player Score in a single game: " << bestPlayerScore << endl;
    cout << "Best Computer Score in a single game: " << bestComputerScore << endl;

    return 0;
}


void playGame(int& playerScore, int& computerScore) {
    int playerChoice, computerChoice;

    displayMenu();  
    cout << "Enter your choice (1=Rock, 2=Paper, 3=Scissors): ";
    cin >> playerChoice;

    
    if (playerChoice < 1 || playerChoice > 3) {
        cout << "Invalid choice! Please choose 1, 2, or 3." << endl;
        return;  
    }

    computerChoice = getComputerChoice();  

    cout << "Player's choice: ";
    displayChoice(playerChoice);
    cout << "Computer's choice: ";
    displayChoice(computerChoice);

    
    string winner = getWinner(playerChoice, computerChoice);
    if (winner == "Player") {
        playerScore = 1;
        computerScore = 0;
    } else if (winner == "Computer") {
        playerScore = 0;
        computerScore = 1;
    } else {
        playerScore = 0;
        computerScore = 0;
    }
}


int getComputerChoice() {
    return rand() % 3 + 1;  
}


void displayChoice(int choice) {
    switch (choice) {
        case 1: cout << "Rock "; break;
        case 2: cout << "Paper "; break;
        case 3: cout << "Scissors "; break;
    }
    cout << endl;
}


void displayMenu() {
    cout << "Rock, Paper, Scissors Game!" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
}


string getWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return "Tie";
    } else if ((playerChoice == 1 && computerChoice == 3) ||  
               (playerChoice == 2 && computerChoice == 1) ||  
               (playerChoice == 3 && computerChoice == 2)) {  
        return "Player";
    } else {
        return "Computer";
    }
}
