===========================
===Lab4                 ===
===Xuchao Jia           ===
===xuchao.jia@wustl.edu ===
===Pu Chai              ===
===chaipu@wustl.edu ===
===========================
Xuchao Jia and I worked together and we both did Part I and Part II.
I worker on PartIII(Saving and Restoring a Game) for all the three games.
Xuchao Jia contributed to the partIV to add a Sudoku game, I wrote the insertion operator and we together debugged the program to finish the assignment

======================TEST CASES======================================
===Test1 Unenough input arguments.
Lab4.exe

===Output
Program Name Lab4.exe
 Please enter the program name and the game name.
 Enter Example: Lab4.exe TicTacToe.
 Then you will begin a simple tic-tac-toe game.
 Or you can enter Lab.exe Gomoku.
 Then you will start a Gomoku Game.
 Also, you can try Lab4.exe Sudoku to start a Soduku Game.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test2 Incorrect input arguments.
Lab4.exe aaaa

===Output
Program Name Lab4.exe
 Please enter the program name and the game name.
 Enter Example: Lab4.exe TicTacToe.
 Then you will begin a simple tic-tac-toe game.
 Or you can enter Lab.exe Gomoku.
 Then you will start a Gomoku Game.
 Also, you can try Lab4.exe Sudoku to start a Soduku Game.

=============================================================================
Copy Control Design Decisions for this Assignment:
We did not use copy control features for the game classes.
What we did to handle the save and load part of this assignment is to add a new method to save 
every piece of the game board to its corresponding ".txt" file and then read the saved file to 
extract the piece information and put the piece to the correct position in the constructor.
We did not included copy, move constructor or copy-assignment operator and move-assignment operator in our design
of every game class.
we prevent to use them since we did not find the appropriate places to use and we have designed other methods to 
make the game classes work. We use ifstream and ostream and istringstream to save load and extract the files and strings.
==============================================================================


=====================================================================
						TEST Sudoku Game
=====================================================================


Test1: run the game with correct arguments
Game is beginning!
====Game Boad====
8||5|3| || |7| || | | ||
-||-|-|-||-|-|-||-|-|-||
7||6| | ||1|9|5|| | | ||
-||-|-|-||-|-|-||-|-|-||
6|| |9|8|| | | || |6| ||
=||=|=|=||=|=|=||=|=|=||
5||8| | || |6| || | |3||
-||-|-|-||-|-|-||-|-|-||
4||4| | ||8| |3|| | |1||
-||-|-|-||-|-|-||-|-|-||
3||7| | || |2| || | |6||
=||=|=|=||=|=|=||=|=|=||
2|| |6| || | | ||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1|| | | ||4|1|9|| | |5||
-||-|-|-||-|-|-||-|-|-||
0|| | | || |8| || |7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

Have Fun!
============================
========Round1=========
Please input the position you want to place the tile and the number. E.g., 3,2,8
. Means place number 8 in position 3,2

the game initialized with the correct format

Test2: type in a valid input 0,0,1

 0,0,1
===Game Board===
8||5|3| || |7| || | | ||
-||-|-|-||-|-|-||-|-|-||
7||6| | ||1|9|5|| | | ||
-||-|-|-||-|-|-||-|-|-||
6|| |9|8|| | | || |6| ||
=||=|=|=||=|=|=||=|=|=||
5||8| | || |6| || | |3||
-||-|-|-||-|-|-||-|-|-||
4||4| | ||8| |3|| | |1||
-||-|-|-||-|-|-||-|-|-||
3||7| | || |2| || | |6||
=||=|=|=||=|=|=||=|=|=||
2|| |6| || | | ||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1|| | | ||4|1|9|| | |5||
-||-|-|-||-|-|-||-|-|-||
0||1| | || |8| || |7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

========Round2=========
Please input the position you want to place the tile and the number. E.g., 3,2,8
. Means place number 8 in position 3,2
the valid input will be in the specified place

Test 3: type in an invalid input
1,,1,,1
the input format is incorect, E.g., 3,2,8. Means place number 8 in position 3,2
You can not overwrite this position, please try another plcae.
========Round2=========
Please input the position you want to place the tile and the number. E.g., 3,2,8
. Means place number 8 in position 3,2

Test 4: an valid input but invalid place
4,0,8
You can not overwrite this position, please try another plcae.
========Round2=========
Please input the position you want to place the tile and the number. E.g., 3,2,8
. Means place number 8 in position 3,2
We cannot ovewrite the postion where the game borad intialzed.

Test 5: an valid input but violate the game rule
1,0,1
!Attention!: You can not place that number in this position. Please try another
number.
You can not overwrite this position, please try another plcae.
========Round2=========
Please input the position you want to place the tile and the number. E.g., 3,2,8
. Means place number 8 in position 3,2
Since the rule of the Sudoku game does not allow a tile with same number in the row and column and the 3*3 square.

Test6: quit and save the game:
quit
do you want to save the game?
please answer with: Y or y (yes), N or n (NO)
y
Game Saved!

Test7: load the game:
====Game Boad====
8||5|3| || |7| || | | ||
-||-|-|-||-|-|-||-|-|-||
7||6| | ||1|9|5|| | | ||
-||-|-|-||-|-|-||-|-|-||
6|| |9|8|| | | || |6| ||
=||=|=|=||=|=|=||=|=|=||
5||8| | || |6| || | |3||
-||-|-|-||-|-|-||-|-|-||
4||4| | ||8| |3|| | |1||
-||-|-|-||-|-|-||-|-|-||
3||7| | || |2| || | |6||
=||=|=|=||=|=|=||=|=|=||
2|| |6| || | | ||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1|| | | ||4|1|9|| | |5||
-||-|-|-||-|-|-||-|-|-||
0||1| | || |8| || |7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

Have Fun!
============================
========Round1=========
Please input the position you want to place the tile and the number. E.g., 3,2,8
. Means place number 8 in position 3,2

the game successfully extract the saved game.
Note: the format we saved our file is like this

Sudoku.txt
Game Saved
1 0 0 0 8 0 0 7 9 
0 0 0 4 1 9 0 0 5 
0 6 0 0 0 0 2 8 0 
7 0 0 0 2 0 0 0 6 
4 0 0 8 0 3 0 0 1 
8 0 0 0 6 0 0 0 3 
0 9 8 0 0 0 0 6 0 
6 0 0 1 9 5 0 0 0 
5 3 0 0 7 0 0 0 0 

We reaplce the "0" as empty string " " and then copy all tiles into the board.

---------------------------------------------------------------------
----------------------------------------------------------------------

==Gomoku==
===Test3 Correct input arguments.
Lab3.exe Gomoku

===Output
Game is beginning!
====Game Boad====
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2     B  
 1      
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Have Fun!
===============================
=======Round1==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test4 Continue input valid position
3,2

===Output
====Game Boad====
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2     B  
 1      
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player B:3,2
=======Round2==================
Player W, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test5 Continue input valid position
19,19

===Output
====Game Boad====
19                                              W 
18 
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2     B  
 1      
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player W:19,19
=======Round3==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test5 Invalid input position. Existed position
3,2

===Output
Your input is exceed the range, or the position you want to move to is not abaliable,
please double check and input again.
=======Round3==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test6 Invalid input position. Exceed range.
20,0

===Output
Your input is exceed the range, or the position you want to move to is not abaliable,
please double check and input again.
=======Round3==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test7 quit
quit

===Output
You guys have already played 2 rounds.
Have a good day!
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test8 win
(input valid position till B win the game.)

===Output
Game End. The winner is B! Congratulation!
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test10 Invalid input postion. parameter is empty
1,

===Output
Please input a valid postion coordinates, eg 3,2
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test11 Invalid input postion. no conmma.
1 1

===Test12 Save and Load Game
===Game Board===
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3     B
 2   W
 1 B                  W
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player W:10,1
========Round5=========
Player B, Please input the position you want to move. E.g., 3,2.
quit
quit
do you want to save the game?
please answer with: Y or y (yes), N or n (NO)
y
Game Saved!

===test13: load the game
Game is beginning!
====Game Boad====
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3     B
 2   W
 1 B                  W
 X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
Have Fun!
============================
========Round5=========
Player B, Please input the position you want to move. E.g., 3,2.

the program successfully load the saved file with correct pieces.


===TicTacToe

===Test11 Correct input arguments.
Lab4.exe TicTacToe

===Output
Game is beginning!
====Game Boad====
4
3
2
1
0
  0 1 2 3 4
Have Fun!
===============================
=======Round1==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test12 Continue input valid position
3,2

===Output
====Game Boad====
4
3
2       B
1      
0
  0 1 2 3 4

Player B:3,2
=======Round2==================
Player W, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test13 Continue input valid position
1,2

===Output
====Game Boad====
4
3
2   W   B
1      
0
  0 1 2 3 4

Player W:1,2
=======Round3==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test14 Invalid input position. Existed position
1,2

===Output
Your input is exceed the range, or the position you want to move to is not abaliable,
please double check and input again.
=======Round3==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test15 Invalid input position. Exceed range.
5,5

===Output
Your input is exceed the range, or the position you want to move to is not abaliable,
please double check and input again.
=======Round3==================
Player B, Please input the position you want to move. E.g., 3,2.
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test16 quit
quit

===Output
You guys have already played 2 rounds.
Have a good day!
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test17 win
(input valid position till B win the game.)

===Output
Game End. The winner is B! Congratulation!
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test18 full game board
(input valid position till no more avaliable postion.)

===Output
You guys have already played 8 rounds.
However there is no winner this time.
Have a good day!
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test19 Invalid input postion. parameter is empty
1,

===Output
Please input a valid postion coordinates, eg 3,2
----------------------------------------------------------------------
----------------------------------------------------------------------

===Test20 Invalid input postion. no conmma.
1 1

===Output
Please input a valid postion coordinates, eg 3,2

===Test21 Save and load the game,
===Game Board===
4
3
2     O
1   X
0
  0 1 2 3 4

Player O:2,2
========Round3=========
Player X, Please input the position you want to move. E.g., 3,2.
quit
do you want to save the game?
please answer with: Y or y (yes), N or n (NO)
y
Game Saved!

==Test22 Load the game
Game is beginning!
====Game Boad====
4
3
2     O
1   X
0
  0 1 2 3 4
Have Fun!
=======================
========Round3=========
Player X, Please input the position you want to move. E.g., 3,2.
The Load function is correct

