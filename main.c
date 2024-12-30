#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"  // Comand to clear the terminal screen in Windows
#else
    #define CLEAR_SCREEN "clear"  // Command to clear the terminal screen in Linux and Mac
#endif

#define START_MONEY 1000  // Starting amount of money
#define MAX_HAND_SIZE 10  // Max number of cards the player can have at once

// Function to generate a random card
int random_card() {
    int card = rand() % 13 + 1;  // Generate a random number between 1 and 13
    return card;
}

// Function to show the cards in the player's or dealer's hand
void show_cards(int *cards, int n) {
    for (int i = 0; i < n; i++) {
        if (cards[i] == 1) {
            printf("A ");  // Ace
        } else if (cards[i] == 11) {
            printf("J ");  // Jack
        } else if (cards[i] == 12) {
            printf("Q ");  // Queen
        } else if (cards[i] == 13) {
            printf("K ");  // King
        } else {
            printf("%d ", cards[i]);  // Cards with numbers on them
        }
    }
    printf("\n");
}

// Function to calculate the sum of a hand
int hand_value(int *cards, int n) {
    int total = 0;  // Total sum of the hand
    int aces = 0;   // Count of aces in the hand
    for (int i = 0; i < n; i++) {
        if (cards[i] == 1) {
            aces = aces + 1;  // Count the ace
            total = total + 11;  // Treat ace as 11
        } else if (cards[i] > 10) {
            total = total + 10;  // K, Q and J cards are 10 points each
        } else {
            total = total + cards[i];  // Cards with numbers are worth their number
        }
    }
    while (total > 21 && aces > 0) {  // If the score is 21 or more and the player has aces their points are reduced to 1 per ace
        total = total - 10;  // Change an ace's value from 11 to 1
        aces = aces - 1;
    }
    return total;
}

// Function to display the possible values of the hand (for hands with aces)
void display_hand_value(int *cards, int n) {
    int total = 0;  // Total value of the hand
    int aces = 0;   // Count of aces in the hand
    for (int i = 0; i < n; i++) {
        if (cards[i] == 1) {
            aces = aces + 1;  // Count the ace cards
            total = total + 11;  // Treat ace as 11 at first
        } else if (cards[i] > 10) {
            total = total + 10;  // K, Q and J cards are worth 10 points
        } else {
            total = total + cards[i];  // Cards with numbers are worth their number
        }
    }
    while (total > 21 && aces > 0) {  // // If the score is 21 or more and the player has aces their points are reduced to 1 per ace
        total = total - 10;  // Change an ace's value from 11 to 1
        aces = aces - 1;
    }
    if (aces > 0) {
        printf("%d/%d", total - (aces * 10), total);  // Show both possible values of the hand if there are aces
    } else {
        printf("%d", total);  // Show the single value of the hand
    }
}

// Main function to run the game
int main() {
    srand(time(NULL));  // Seed the random number generator with the current time
    int money = START_MONEY;  // Player's starting money
    int player[MAX_HAND_SIZE], dealer[MAX_HAND_SIZE];  // Arrays to hold player and dealer cards
    int player_count, dealer_count, bet;  // Variables for card counts and betting amount
    char choice;  // Player's choice: hit or stand

    printf("Welcome to Blackjack!!!\n");

    while (money > 0) {  // Loop runs until the player runs out of money
        system(CLEAR_SCREEN);  // Clear the screen for better visibility
        player_count = 0;  // Reset player's hand
        dealer_count = 0;  // Reset dealer hand
        printf("\nYou have $%d. Enter your bet: ", money);
        if (scanf("%d", &bet) != 1 || bet <= 0 || bet > money) {  // Validate the bet
            printf("Invalid bet! Try again.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        // Deal starting cards to the player and the dealer
        player[player_count++] = random_card();
        player[player_count++] = random_card();
        dealer[dealer_count++] = random_card();
        dealer[dealer_count++] = random_card();

        // Player's turn
        while (1) {
            system(CLEAR_SCREEN);  // Clear the screen
            printf("\nYour cards: ");
            show_cards(player, player_count);  // Display player's cards
            printf("Your hand value: ");
            display_hand_value(player, player_count);  // Display hand value
            printf("\n");

            // Show dealer's visible card
            printf("Dealer's visible card: ");
            if (dealer[0] == 1) {
                printf("A\n");
            } else if (dealer[0] == 11) {
                printf("J\n");
            } else if (dealer[0] == 12) {
                printf("Q\n");
            } else if (dealer[0] == 13) {
                printf("K\n");
            } else {
                printf("%d\n", dealer[0]);
            }

            printf("(h)it or (s)tand? ");  // Ask the player to hit or stand
            scanf(" %c", &choice);

            if (choice == 'h') {  // Player chooses to hit
                player[player_count++] = random_card();  // Add a new card to player's hand
                if (hand_value(player, player_count) > 21) {  // Check for bust
                    system(CLEAR_SCREEN);
                    printf("\nYour cards: ");
                    show_cards(player, player_count);
                    printf("Your hand value: ");
                    display_hand_value(player, player_count);
                    printf("\n\nYou busted!!!\n");
                    money = money - bet;  // Remove the bet amount from the player money balance
                    printf("\nPress Enter to continue...");
                    while (getchar() != '\n');
                    while (getchar() != '\n');
                    break;
                }
            } else if (choice == 's') {  // Player chooses to stand
                break;
            } else {
                printf("Invalid choice!\n");  // Handle invalid input
            }
        }

        if (hand_value(player, player_count) > 21) continue;  // Skip dealer's turn if player busts

        // Dealer's turn
        system(CLEAR_SCREEN);
        while (hand_value(dealer, dealer_count) < 17) {  // Dealer must hit until his hand's sum is 17 or more
            dealer[dealer_count++] = random_card();
            if (hand_value(dealer, dealer_count) >= 17) {
                break;  // Dealer stops hitting at 17 or higher
            }
        }

        // Show final results
        system(CLEAR_SCREEN);
        printf("\nYour final cards: ");
        show_cards(player, player_count);
        printf("Your final value: ");
        display_hand_value(player, player_count);
        printf("\n");
        printf("---------------------------\n");
        printf("Dealer's final cards: ");
        show_cards(dealer, dealer_count);
        printf("Dealer's final value: %d\n", hand_value(dealer, dealer_count));
        printf("---------------------------\n");


        int player_value = hand_value(player, player_count);  // Calculate player's final hand value
        int dealer_value = hand_value(dealer, dealer_count);  // Calculate dealer's final hand value

        // Determine the winner based on hand values
        if (dealer_value > 21 || player_value > dealer_value) {  // Player wins if dealer busts or player has a higher value
            printf("You WIN $%d!!!\n", bet);
            money = money + bet;  // Add the bet amount to player's money
        } else if (player_value < dealer_value) {  // Player loses if dealer has a higher value
            printf("You lose $%d...\n", bet);
            money = money - bet;  // Remove the bet amount from the player money balance
        } else {  // It's a tie if both have the same value
            printf("It's a TIE!\n");  // No money is gained or lost
        }

        // Ask the player to continue to the next round
        printf("\nPress Enter to continue...");
        while (getchar() != '\n');  // Wait for Enter key
        while (getchar() != '\n');  // Clear input buffer
    }

    // Game over message when the player runs out of money
    printf("\nYou're OUT OF MONEY!!! Game over.\n");
    return 0;  // Exit the game
