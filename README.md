# Game of Life

A graphical implementation of Conway's Game of Life using C++ and [raylib](https://www.raylib.com/). This project is based on the tutorial from [Programming with Nick](https://www.youtube.com/watch?v=daFYGrXq0aw).

## Features

- **Multiple cell states:** DEAD, ALIVE, NEWBORN, DYING (with distinct colors)
- **Interactive controls:** Pause, resume, clear, randomize, and set cell states with mouse
- **Adjustable speed:** Increase or decrease simulation FPS
- **Toroidal grid:** Edges wrap around for seamless simulation

## Controls

| Key / Mouse         | Action                                 |
|---------------------|----------------------------------------|
| `Space`             | Pause/Resume simulation                |
| `R`                 | Randomize grid                         |
| `C`                 | Clear grid                             |
| `W`                 | Increase simulation speed (FPS)        |
| `S`                 | Decrease simulation speed (FPS)        |
| Left Mouse Button   | Set cell to ALIVE                      |
| Right Mouse Button  | Set cell to DEAD                       |

## Build & Run

### Prerequisites

- C++ compiler (e.g., g++)
- [raylib](https://www.raylib.com/) library installed

### Build

```sh
g++ -o game_of_life src/main.cpp src/grid.cpp src/simulation.cpp -lraylib -std=c++17
```

### Run

```sh
./game_of_life
```

## How It Works

- The simulation grid is displayed in a window.
- Each cell can be DEAD, ALIVE, NEWBORN, or DYING.
- The simulation follows Conway's rules, with visual transitions for new and dying cells.

## Customization

You can modify cell colors, grid size, and rules in the source code to experiment with different behaviors.

## License

This project is open source and free to use.