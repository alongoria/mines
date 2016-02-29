Welcome to The Game of Life, as implemented by Grant Walker and Adam Longoria.

The Game of Life is a simple game to play. Cells are arranged in a 100x100 pattern. Cells are either 'dead'
or 'alive'. All cells are, by default, dead. The player selects cells by clicking on them, thereby making
them 'alive', or turning them on.

After selecting cells, the player can start the game by pressing 'g' (for "Go!"). The game then proceeds
without input from the player, according to Conway's rules for the Game of Life:

For a space that is 'populated':
    Each cell with one or no neighbors dies, as if by loneliness. 
    Each cell with four or more neighbors dies, as if by overpopulation. 
    Each cell with two or three neighbors survives.

For a space that is 'empty' or 'unpopulated'
    Each cell with three neighbors becomes populated. 

The game then runs until the player presses 'g', which will pause the current game and allow
the player to turn on additional cells, or 'r', which clears all cells and resets the game.

On reset, the game returns to the state it was in when the program was started. From here,
the player can experiment with different intitial cells until satisfied.

We hope you enjoy experimenting with The Game of Life!

If you have any questions about the game, please feel free to email the creators at gwalker@mines.edu.