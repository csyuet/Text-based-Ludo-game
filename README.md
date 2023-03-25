# Text-based-Ludo-game
This game project is a console application that can be accessed using the Linux terminal and via SSH. 

## Introduction
Ludo is a strategy board game that is played by four player, where players need to figure out how to beat other players by strategy and race their chess from start to finish according to the rolls of dice. In this program, we assume the game is played by four players.

**Description** 
* There will be four players, each will be given four chesses.
* There will be a board with route formed by boxes, players need to move their chess through the route and reach their perspective finish box.
* Each player will have a chance to roll the random dice each round.

## Rule
* Players can move their chess according to the number rolled from the dice.
* If the number is even number then the player can choose to move his chess to the ready position.
* If the number rolled is 6, then the player can roll the dice again. 
* Each box on the route are in a certain colour, if the chess landed on a box in the same as the player number, the chess can move forward to the next box that contain the same number on the route.
* If the player’s chess landed on the box that already had a chess on it, the chess in the box originally would have to return to the base.
* If the player landed on the box with the same colour as the player and at the same time the box originally have chess of other player, then the chess in the box would return to their base but the player’s chess would not move forward to the next box that are in the same colour.
* The first one with all his chess reached the finish box will be the winner and end the game.
* To reach the finish box, the chess will have to go around the board for once and enter the finish path in the middle of the board. After entering the finish path, the player need to roll the exact number to reach the finish box or else the chess will rebounce.

**Implementatio plan and coding element**
* Generation of random game sets or events
    - Generate random number (1-6) when user roll a dice using time.h in srand.
    - Generate number of time (1-3second) for the loading and saving bar to move.
* Data structures `struct` used for storing game status
    - **Chess**
        - ID(the id of each chess)
        - Stage(The stage of chess: "BASE", "ROAD", "PEND", "LAST", "GOAL")
        - Pos(The position of the chess)
    - **Player**
        - Icon (The chess appearance of the player)
        - Vector<CHESS>chess(vector to store the four chesses)
        - Map<string,int> counters (to count the number of chess pieces in specific stage)
* Dynamic memory management
    - Use of vector
        - Using pushback, new, delete to change the array size.
    - Use of map
        - Using the counter
* File input/output (e.g., for loading/saving game status)
    - There will be a default text file that store the stage, chess id, position number, so that everytime the player start a new game, the cheeses will be located in the initial position.
    - If the player choose to save and quit in the middle of the game, the player can name the file to output and store information like the stage, chess id, position and current player in the text file, so that if the player want to resume the previous game they can input the file and continue to play with the same player.
* Program codes in multiple files
    - Use a file define.h to store the header that our program needed.
    - Use a file functions.cpp to store all the functions that could be called from the program.
    - Use a file main.cpp to store the main program to be execute.
    - Use a text default.txt to store the default information that the program need.
    
**Compilation and execution instructions:**<br>
Input make to compile,
```
make
```
to execute the game,
```
./main
```
