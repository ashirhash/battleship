
# Battleship: Search and Destroy! 🚢💥

This project is a simple C++ **Battleship** game, developed as part of my first-semester university project. It features a **grid-based naval warfare game** where players take turns to shoot down hidden ships using coordinates. The game includes multiple gameplay modes and is designed to demonstrate basic programming concepts, including loops, arrays, randomization, and user interaction in C++

## 🕹️ Features

1. **Single Player Mode**  
- Engage in a battle against random ship placements.
- Strategically sink all the ships within a limited number of turns.

2. **VS Computer Mode (New!)**  
- Compete against the computer in a tactical showdown.
- Place your ships on the grid and attempt to outwit the AI!

3. **Multi-Player Mode (Coming Soon)**  
- Stay tuned for an exciting two-player mode!

4. **Interactive Game Instructions**  
- Learn the basics with a clear and concise "How to Play" guide.

## 💻 How It Works

- **Grid Layout:** The game operates on a `5x5` grid.  
- **Ships Placement:** Ships are randomly placed on the grid in single-player mode. In "VS Computer" mode, you can manually place them.  
- **Game Mechanics:**  
  - Input coordinates to fire cannonballs at suspected ship locations.  
  - Each successful hit is marked with `X`, and a miss is marked with `O`.  
  - Your goal is to sink all the ships before running out of turns.

## 📂 File Structure

```plaintext
Battleship
├── main.cpp       # Contains the core logic of the game.
└── README.md      # Project documentation.
└── .gitignore     
```

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC, Clang).  
- A terminal or console for execution.

### Compilation

Use the following command to compile the program:

```bash
g++ main.cpp -o battleship
```

### Running the Game

Run the compiled program:

```bash
./battleship
```

## 📝 Instructions

- **Objective:** Sink all enemy ships using limited cannonballs.  
- **Controls:**  
  - Enter coordinates in the format `Row Column` (e.g., `1 2`).  
  - Use menu options to navigate and select game modes.  
- **Scoring:**  
  - Earn points for each ship destroyed.  
  - Track your progress with scores, turns remaining, and ships left.

## 📖 Code Breakdown

### Main Features

- **Main Menu:** Displays available game modes and instructions.  
- **Map Management:** Functions to reset, display, and manage the game grid.  
- **Single Player Mode:** Randomized ship placements and interactive gameplay.  
- **VS Computer Mode:** AI-controlled gameplay where both players compete.  

### Functions

- `showMainMenu()`: Displays the main menu.  
- `resetMap()`: Resets the game grid for a fresh round.  
- `map()`: Prints the current state of the grid.  
- `singlePlay(int turns)`: Handles single-player gameplay mechanics.  
- `compPlay(int turns)`: Manages gameplay in the VS Computer mode.

## 📊 Game Logic Overview

1. **Randomized Ship Placement:**  
- Uses `rand()` to position ships randomly on the grid.  

2. **Turn-Based Gameplay:**  
- Players input coordinates to fire at ships.  
- Visual feedback with `X` for hits and `O` for misses.

3. **Dynamic Map Rendering:**  
- Updates the grid after every turn.  

4. **Win/Loss Conditions:**  
- Victory: All ships are sunk within the given turns.  
- Loss: Turns run out before sinking all ships.

## 🎯 Future Enhancements

- Multi-player mode with network support.  
- Improved AI with difficulty levels.  
- Larger grid sizes and customizable settings.  

## 📜 License

This project is open-source and available under the [MIT License](https://opensource.org/license/mit). Feel free to contribute

## ❤️ Acknowledgments

- Thanks to my professors and classmates for their support.
- Inspired by the classic game of Battleship
