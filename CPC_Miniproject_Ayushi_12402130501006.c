#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Function to display the choice
void showChoice(int choice) {
    if (choice == 1)
        printf("Stone");
    else if (choice == 2)
        printf("Paper");
    else if (choice == 3)
        printf("Scissors");
}

// Function to determine the winner of the round
int determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) 
        return 0; // Draw
    else if ((playerChoice == 1 && computerChoice == 3) ||
             (playerChoice == 2 && computerChoice == 1) ||
             (playerChoice == 3 && computerChoice == 2)) 
        return 1; // Player wins
    else 
        return -1; // Computer wins
}

int main() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    printf("===== Welcome to the Stone-Paper-Scissors Game! =====\n");
    printf("Rules:\n");
    printf("1. Stone beats Scissors\n");
    printf("2. Scissors beats Paper\n");
    printf("3. Paper beats Stone\n");
    printf("=====================================================\n");

    do {
        printf("\nChoose your option:\n");
        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &playerChoice);
        clrscr();
        if (playerChoice < 1 || playerChoice > 3) {
            printf("Invalid choice! Please choose between 1 and 3.\n");
            continue;
        }

        computerChoice = (rand() % 3) + 1;

        printf("You chose: ");
        showChoice(playerChoice);
        printf("\nComputer chose: ");
        showChoice(computerChoice);
        printf("\n");

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0) {
            printf("It's a draw!\n");
        } else if (result == 1) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
            }
        printf("\nCurrent Scores:\n");
        printf("You: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);

        printf("\nDo you want to play another round? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n===== Final Scores =====\n");
    printf("You: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations! You won the game!\n");
    } else if (playerScore < computerScore) {
        printf("Computer wins the game! Better luck next time.\n");
    } else {
        printf("The game is a draw. Well played!\n");
    }

    printf("\nThank you for playing Stone-Paper-Scissors!\n");
    return 0;
}