# 🐍 SNAKE GAME

An immersive classic revisited. Navigate the grid, grow your snake, and challenge your reflexes. Built in C with a touch of modern elegance.

## Directory Structure

- **`bin`**: Contains compiled files and the game executable.
- **`src`**: Source code of the game.

## Getting Started

### Dependencies

To render the graphical interface, you'll need the **MLV** library.

#### Setting Up MLV Library

1. **Install the `build-essential` meta package:**  
Provides the compiler and other essential tools.
   ```
   sudo apt install build-essential
   ```
2. **Download the MLV Library Source Code:**<br/>
Use the link below to fetch the source: [here](http://www-igm.univ-mlv.fr/~boussica/mlv/api/English/html/download.html)

### Compilation

- Use `make snake` to generate an executable named `game`.
- `make clean` will clear the content of the `bin/` directory.

## Launching the Game

To start the game, run : ```./game```

## Game Options

**Available Arguments:**

- `-h` or `--help`: Displays the user manual.
- `-i` or `--input`: Specifies the grid to use, you can create a custom map.
- `-d` or `--debug`: Debug mode, displays game information in the c

To play, use the keyboard arrows to move the snake. The objective is to collect all the **golden apples**. Good luck!