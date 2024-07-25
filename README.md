I'm assuming that most people are familiar with the rules of tic-tac-toe, so I won't go into the details of the gameplay. This project includes three key functions in addition to main: PrintBoard, MarkBoard, and Check_Win_Condition.

PrintBoard: This function displays the tic-tac-toe board, showing both the layout and the current markers in each cell. It uses numbers for empty cells, and players select cells by entering these numbers.

MarkBoard: This function updates the board with the player’s marker ('X' or 'O'). It also ensures that the selected cell is not already occupied to prevent invalid moves.

Check_Win_Condition: This function checks if a player has won by evaluating all possible winning conditions—rows, columns, and diagonals.

main: The main function manages the game flow. It sets up the board, switches turns between players, handles user input, and runs the game loop. After each game, it asks if players want to play again or exit.
