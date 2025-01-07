<style>
	code {
		font-family: 'Courier New', Courier, monospace;
		color: #d63384;
	}
</style>

# Minimax Algorithm

<br>

Minimax is a decision-making algorithm widely used in game theory and AI to find the optimal move for a player, assuming the opponent also plays optimally.

<br>

## I - Introduction

---

<br>

The Minimax algorithm is a recursive strategy used in turn-based games like chess, tic-tac-toe, and Gomoku. It builds a decision tree of possible game states and selects the move that maximizes the chances of winning while minimizing the opponent's chances of success.

<br>

The algorithm alternates between two roles:

<br>

- **Maximizer:** seeks to maximize the score, representing the AI's turn.
- **Minimizer:** seeks to minimize the score, representing the opponent's turn.

<br>

## II - How it works

---

<br>

### 1. Decision Tree

<br>

The Minimax algorithm generates a game tree, where:

<br>

- **Nodes** represent possible game states.
- **Edges** represent moves from one state to another.

<br>

The tree is evaluated up to a certain depth to simulate possible future scenarios.

<br>

### 2. Recursive Evaluation

<br>

At each node:

<br>

- If it's the maximizer's turn, the algorithm selects the move with the **highest score**.
- If it's the minimizer's turn, the algorithm selects the move with the **lowest score**.

<br>

### 3. Terminal States

<br>

A terminal state occurs when:

<br>

- The game ends (win, loss, or draw).
- The maximum search depth is reached.

<br>

The terminal state is evaluated using a **heuristic function** that assigns a score to the game state.

<br>

### 4. Example

<br>

Consider the following game tree, where numbers represent the heuristic value of a terminal state:

<br>

<div style="font-family: 'Courier New', Courier, monospace; white-space: pre;">
          MAX
       /       \
      MIN       MIN
   /   |   \   /   \
  3    5    2  9    1
</div>

<br>

- The maximizer evaluates each branch, assuming the minimizer will choose the lowest value:
  - Left branch: MIN(3, 5, 2) = 2
  - Right branch: MIN(9, 1) = 1
- The maximizer then chooses the maximum: MAX(2, 1) = **2**.

<br>

Thus, the optimal move is the one leading to the left branch.

<br>

## III - Algorithm

---

<br>

### Steps

<br>

1. **Generate the Game Tree:**
   - Simulate all possible moves for the current player.

<br>

2. **Evaluate Terminal States:**
   - Assign scores to terminal nodes using a heuristic function.

<br>

3. **Recursive Evaluation:**
   - Starting from the terminal nodes, propagate scores back to the root, alternating between maximizing and minimizing.

<br>

4. **Choose the Optimal Move:**
   - Select the move leading to the best score at the root.

<br>

### Pseudocode

<br>

```python
function minimax(node, depth, maximizingPlayer):
	if depth == 0 or node is a terminal state:
		return heuristic(node)
	
	if maximizingPlayer:
		maxEval = -∞
		for each child of node:
			eval = minimax(child, depth - 1, false)
			maxEval = max(maxEval, eval)
		return maxEval
	else:
		minEval = +∞
		for each child of node:
			eval = minimax(child, depth - 1, true)
			minEval = min(minEval, eval)
		return minEval
```
