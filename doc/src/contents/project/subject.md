# Subject

<br>

*Summary: The goal of this project is to make an AI capable of beating human players at Gomoku.*

<br>

## I - Introduction

---

<br>

[Gomoku](https://en.wikipedia.org/wiki/Gomoku) is a strategy board game traditionally played on a [Go](https://en.wikipedia.org/wiki/Go_%28game%29) board with stones of two different colors.

<br>

## II - General guidelines

---

<br>

In the context of this project, you will play with the following additional rules:

<br>

• Two players take turns placing stones of their color on an intersection of the board, and the game ends when one player manages to align five stones. Sometimes, only an alignment of 5 can win, and sometimes 5 or more is okay. In the context of this projet, we will consider 5 or more to be a win.

<br>

• There are different interpretations on what the board size for Gomoku should be.
In the context of this project, Gomoku will be played on a 19x19 Goban, without
limit to the number of stones.

<br>

• There are a great many additional rules to Gomoku (Google it!) aimed at making the game more fair (regular Gomoku is proven to be unfair, a perfect first player wins 100% of the time) and more interesting.

<br>

• Capture (As in the Ninuki-renju or Pente variants) : You can remove a pair of your opponent’s stones from the board by flanking them with your own stones (See the appendix). This rule adds a win condition : If you manage to capture ten of your opponent’s stones, you win the game.

<br>

• Endgame Capture:

<br>

		◦ A player who manages to line up five stones wins only if the opponent cannot break this line by capturing a pair.
		◦ If the player has already lost four pairs and the opponent can capture one more, the opponent wins by capture.
		◦ If there is no possibility of this happening, there is no need to continue the game.

<br>

• No double-threes : It is forbidden to play a move that introduces two free-three alignments, which would guarantee a win by alignment (See the appendix).

<br>

• You are free to use whatever language and graphical interface library you want.

<br>

• Your program should not crash in any circumstances (even when it runs out of memory), and should not quit unexpectedly.
If it happens, your project will be considered non-functional and your grade will be 0.

<br>

• You have to provide a Makefile which must produce your program. It must not
relink.

<br>

• Your Makefile must at least contain the rules: $(NAME), all, clean, fclean and re.

<br>

> ℹ️ Although you must keep in mind that while there will not be a grading scale on the time/space performance of your AI relative to others (We’ll see about that kind of thing later on), if your AI takes more than half a second (in average) to find a move, you will not validate the project. That’d be bad, wouldn’t it ? Also, you must still keep performance for its own sake in mind : You will not get all the points if your implementation wins too slowly, or if your implementation seems lazily done (Low search depth, naive
implementation, etc...)

<br>

## III - Mandatory part

---

<br>

You must write a program that lets you play Gomoku(with the rules specified previously):

<br>

		• The executable must be named Gomoku.

<br>


		• Against your program : The most interesting case, of course. The goal here is that the program wins the game, without you letting it win. It must be able to adapt its strategy to the player’s moves.

<br>

		• Against another human player on the same computer (hotseat), but with a movesuggestion feature. Easy to do once you have made a whole computer player.

<br>

The AI will, basically, generate a possible-solution tree, and choose the best move according to this tree. You have to use a Min-Max algorithm for this. While this is rather easy in itself, since these algorithms are well-documented and you pretty much only have to implement them, for them to actually be useful, you need an efficient heuristic function to evaluate the value of a terminal node in your tree. You will have to experiment and refine it until it is sufficiently accurate while remaining fast enough. Don’t be fooled : The heuristic is actually the hardest part. 

<br>

You must also provide a usable graphical interface to allow one to actually play Gomoku. After all, while the AI is the main focus here, your game still has to be playable. You’re free to use whichever graphical or ncurses-like library you want for this, as long as the end result is at least vaguely pleasing to the eye, and is easily playable.

<br>

Also, it would be a very good idea to implement some sort of debugging process that lets you examine the reasoning process of your AI while it’s running. Not only would it be helpful to refine your AI’s tactics, but it would help during your defense sessions, since you will have to actually explain how it works.