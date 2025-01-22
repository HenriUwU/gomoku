<div align="center">

![](/assets/images/logo.png)

**Yeah, well, your brain has to fry sometime.**

</div>

## Features

- Implement a Gomoku game from scratch with an AI and player modes.
- Support customizable rules.
- Handle user input for placing pieces and validating moves.
- Implement AI with heuristic evaluation and strategy for gameplay.
- Detect winning conditions and handle game-ending scenarios.
- Provide a graphical interface for gameplay.
- Optimize performance for AI decision-making and board management.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/gomoku.git
```

2. Navigate to the project directory:

```bash
cd gomoku
```

The project provides two ways of installation, one uses g++ (Makefile), but will need to install the SFML on your machine, and the other uses Docker (CMake). 

### Using g++

1. Compile the program:

```bash
make
```

### Using Docker

1. Build the Docker:

```bash
make docker-build
```

2. Run the Docker:

```bash
make docker-run
```

## Usage

Run the program as follows:

```bash
./Gomoku
```

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/gomoku/blob/main/LICENSE) file.

## Resources

- [Gomoku (Wikipedia)](https://en.wikipedia.org/wiki/Gomoku)
- [Go game (Wikipedia)](https://en.wikipedia.org/wiki/Go_%28game%29)
- [Goban (Wikipedia)](https://en.wikipedia.org/wiki/Go_equipment#Board)
- [Minimax (Wikipedia)](https://en.wikipedia.org/wiki/Minimax)
- [Heuristic (Wikipedia)](https://en.wikipedia.org/wiki/Heuristic_(computer_science))
- [Alpha-beta pruning (Wikipedia)](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning)
- [Algorithms Explained – minimax and alpha-beta pruning (YouTube)](https://www.youtube.com/watch?v=l-hh51ncgDI)
- [Minimax with Alpha Beta Pruning (YouTube)](https://www.youtube.com/watch?v=zp3VMe0Jpf8&t=603s)
- [Minimax: How Computers Play Games (YouTube)](https://www.youtube.com/watch?v=SLgZhpDsrfc)
- [Quick Sort (GeeksforGeeks)](https://www.geeksforgeeks.org/quick-sort-algorithm/)
- [Negamax (Wikipedia)](https://en.wikipedia.org/wiki/Negamax)
- [Principal variation search (Wikipedia)](https://en.wikipedia.org/wiki/Principal_variation_search)
- [Bitboard logic (GitHub)](https://github.com/wwatkins42/gomoku/blob/master/include/BitBoard.hpp)
- [Animated GIF (GitHub)](https://github.com/SFML/SFML/wiki/Source:-Animated-GIF)
- [GNU gprof (GNU)](https://ftp.gnu.org/old-gnu/Manuals/gprof-2.9.1/html_mono/gprof.html)
- [Documentation of SFML 2.6.1 (SFML)](https://www.sfml-dev.org/documentation/2.6.1/)