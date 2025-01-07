<style>
	code {
		font-family: 'Courier New', Courier, monospace;
		color: #d63384;
	}
</style>

# Alpha-Beta Pruning

<br>

Alpha-Beta Pruning is an optimization technique for the Minimax algorithm that reduces the number of nodes evaluated in the game tree.

<br>

## I - Introduction

---

<br>

Alpha-Beta Pruning enhances the Minimax algorithm by skipping branches that cannot influence the final decision. This drastically reduces computation time, making it possible to evaluate deeper game trees within the same time constraints.

<br>

The algorithm introduces two values:

<br>

- **Alpha (α):** The best score the maximizer can guarantee so far.
- **Beta (β):** The best score the minimizer can guarantee so far.

<br>

## II - How it works

---

<br>

### 1. Pruning Condition

<br>

At any node, if the current score of a branch is worse than a previously evaluated branch, further exploration of that branch is unnecessary.

<br>

### 2. Recursive Evaluation

<br>

Alpha-Beta Pruning is applied during the recursive evaluation of the game tree:

<br>

- **Maximizer:** Updates `α` as it explores better options.
- **Minimizer:** Updates `β` as it explores better options.

<br>

If `α >= β`, the current branch is pruned (no further exploration is needed).

<br>

### 3. Example

<br>

Consider the following game tree with Alpha-Beta Pruning applied:

<br>

<div style="font-family: 'Courier New', Courier, monospace; white-space: pre;">
           MAX
         /     \
      MIN       MIN
   /   |   \   /   \
  3    5    2  9    1
</div>

<br>

- The algorithm evaluates the left branch first:
  - MAX evaluates MIN(3, 5, 2) = **2**
  - `α` = 2

<br>

- Moving to the right branch:
  - If any MIN node evaluates to ≤ 2, it is pruned.

<br>

- As soon as MIN evaluates 9 (greater than `α`), the entire right branch is skipped, as it cannot improve the MAX node.

<br>

## III - Algorithm

---

<br>

### Steps

<br>

1. **Initialize α and β:**
   - α starts at `-∞`, and β starts at `+∞`.

<br>

2. **Evaluate Nodes Recursively:**
   - At each node, update `α` or `β` based on the player type (Maximizer or Minimizer).

<br>

3. **Prune Subtrees:**
   - Stop exploring a branch when `α ≥ β`.

<br>

4. **Return the Best Move:**
   - At the root node, the optimal move is the one leading to the highest value for the Maximizer.

<br>

### Pseudocode

<br>

```python
function alphaBeta(node, depth, alpha, beta, maximizingPlayer):
    if depth == 0 or node is a terminal state:
        return heuristic(node)

    if maximizingPlayer:
        maxEval = -∞
        for each child of node:
            eval = alphaBeta(child, depth - 1, alpha, beta, false)
            maxEval = max(maxEval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break  # Beta cutoff
        return maxEval
    else:
        minEval = +∞
        for each child of node:
            eval = alphaBeta(child, depth - 1, alpha, beta, true)
            minEval = min(minEval, eval)
            beta = min(beta, eval)
            if beta <= alpha:
                break  # Alpha cutoff
        return minEval
```
