# set-card-game-in-c-

Set is a game with a deck of 81 unique cards. Each card has 4 attributes: shape, color of shape, fill of shape, and number of shape. 12 cards are dealt and players attempt to find sets. A set is 3 cards where all 4 of the attributes are either the same or different (for each attribute). If there are no sets on the board, 3 more cards are dealt. I made a user playable version of the game and an auto solver.

I created a card object for this project. I initialized every combo of set cards into an array and then randomized the array. The first 12 cards of the array are shown, and when a set is found the card in the next unused slot of the array replaces the card that was just played. 
