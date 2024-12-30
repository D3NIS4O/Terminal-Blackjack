# Terminal-Blackjack
1. General Idea  
•	Project Topic: The project is a text-based Blackjack game, a simplified version of the popular casino card game.  
•	How the Program Works:  
&emsp;o	The player starts with a fixed amount of money ($1000) and bets a portion of it in each round.  
&emsp;o	The goal is to get a hand value as close to 21 as possible without exceeding it (busting) while beating the dealer's hand.  
&emsp;o	The player and dealer are dealt cards, and the player can choose to hit (take another card) or stand (end their turn). The dealer must draw cards until their hand value is at least 17.  
&emsp;o	Outcomes include win, loss, or tie, and the player's money adjusts accordingly.  
•	Specific Idea: The program focuses on simulating core Blackjack mechanics while maintaining simplicity. The aim was to create an interactive console-based game that handles card values, player decisions, and dealer logic accurately.







3. How (Tricky Steps)  
•	Handling Aces:  
&emsp;o	Aces can have a value of 1 or 11, depending on the total hand value.  
&emsp;o	The logic adjusts Ace values dynamically if the total hand value exceeds 21, which requires tracking the count of Aces in the hand and modifying their contribution accordingly.  
•	Dealer Logic:  
&emsp;o	The dealer must follow strict rules to hit until their hand value reaches at least 17. Implementing this automatic decision-making involved calculating the dealer's hand value after each draw and enforcing the stopping condition.  
•	Input Validation:  
&emsp;o	Validating player input for bets (e.g., ensuring the bet is within available money and is a positive number) was necessary to avoid invalid game states.  
&emsp;o	Similarly, validating hit/stand inputs ensures smooth gameplay.  
•	Screen Clearing Across Platforms:  
&emsp;o	The program uses platform-dependent commands (cls for Windows and clear for Linux/Mac) to clear the screen for better user experience.




4. Manual (User Menu and Instructions)  
•	How to Use:  
&emsp;o	When the game starts, you are given $1000 to play with.  
&emsp;o	Each round begins with a prompt to place a bet. Enter a valid number within your available money.  
&emsp;o	After receiving two initial cards, decide whether to:  
&emsp;&emsp;	(h)it: Take another card to try and get closer to 21.  
&emsp;&emsp;	(s)tand: End your turn and let the dealer play.  
&emsp;o	The dealer then draws cards according to the rules, and the final results are displayed, showing both hands and the outcome of the round.  
&emsp;o	The game ends when your money reaches $0.  











5. Diagram

![image](https://github.com/user-attachments/assets/ff2441fb-a04b-454b-9a10-27706cffa1cf)




















5. What More Could You Do?
•	Improvements:
o	User Interface: Add a graphical or web-based UI for a more engaging experience.
o	Multiple Rounds: Include game statistics and allow multiple rounds with tracking for wins/losses.
o	Deck Management: Use a realistic deck of 52 cards instead of random generation to mimic actual Blackjack rules.
o	Advanced Betting: Add features like doubling down, splitting hands, or insurance bets.
o	Multiplayer: Enable multiple players to participate in the game.
o	AI Enhancements: Make the dealer's logic customizable (e.g., mimic human-like decisions).
