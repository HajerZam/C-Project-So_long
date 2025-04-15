# C-Project-So_long
My seventh project in 42 common core (≖_≖ ) good GOD …the horrors I witnessed.

## 🧠 Main Concepts to Learn & Understand

### 1. **MiniLibX Basics**

the graphic library needed for the three rank 2 graphical project (so_long, FdF, Fract-ol).

- Creating a window
- Drawing images (sprites)
- Handling keyboard inputs
- Closing the window properly

### 2. **Map Parsing**

- Read `.ber` files
- Validate map format (rectangular, enclosed by walls)
- Track key characters: `0`, `1`, `C`, `E`, `P`

### 3. **Game Logic**

- Move player with W/A/S/D
- Block movement into walls
- Pick up collectibles
- Exit only when all collectibles are picked
- Count and display moves

### 4. **Pathfinding (Map Validation)**

- Ensure there is a valid path from P → all C → E
- DFS or BFS to check connectivity

### 5. **Memory Management**

- Handle malloc/free properly
- No leaks allowed

### 6. **Bonus Features**

- Enemies (patrols that kill the player)
- Sprites animations
- On-screen movement counter

---

## 🛠️ Project Plan: Step-by-Step Strategy

### 🔹 Step 1: Setup

- ✅ Install **MiniLibX**
- ✅ Prepare your **Makefile**
- ✅ Create project structure:

```c
so_long/
├── src/
├── include/
├── assets/
├── maps/
├── Makefile
└── main.c
```

### 🔹 Step 2: Map Parsing

- ✅ Read `.ber` file line by line
- ✅ Check characters validity
- ✅ Ensure rectangular & enclosed map
- ✅ Check for one `P`, one `E`, at least one `C`
- ✅ Use DFS/BFS to verify valid paths

### 🔹 Step 3: Graphics & Window

- ✅ Open a window with MiniLibX
- ✅ Display basic tiles: floor, wall, player, collectible, exit
- ✅ Create a map renderer function

### 🔹 Step 4: Player Movement

- ✅ Handle W/A/S/D key input
- ✅ Move only if target tile is not a wall
- ✅ Pick up collectible if on `C`
- ✅ Update move count

### 🔹 Step 5: Game Rules

- ✅ Allow exit only when all collectibles are taken
- ✅ Print movement count to terminal

### 🔹 Step 6: Handle Events

- ✅ Handle ESC key
- ✅ Handle window close (click X)
- ✅ Free memory before exiting

### 🔹 Step 7: Bonus (if time allowed)

- 🔸 Add enemy patrol logic (with simple AI)
- 🔸 Add basic sprite animation (e.g., alternating frames)
- 🔸 Display move counter inside the game window

---

## 📚 Resources for Each Step

### 🎥 YouTube

- **MiniLibX Tutorials**
    - [42School MiniLibX tutorial](https://www.youtube.com/watch?v=a1yD_lgDtmM)
    - [Creating 2D Game using MiniLibX](https://www.youtube.com/watch?v=g5HEp2MxKtg)

### 📘 GitBooks / Blogs

- MiniLibX Explained
- Pathfinding in C (DFS/BFS)
- [42 Game Tutorials & Patterns](https://github.com/0xAliK/42-So_long)

### 💻 GitHub Repos

- 🧠 **Good starter template**:
    
    https://github.com/ayoub0x1/so_long
    
- 📦 **MiniLibX Example**:
    
    https://github.com/42Paris/minilibx-linux
    
- 🧪 **Testing map parser**:
    
    [GitHub - Nuno-Jesus/so_long_invalidator: Small map validator for 42 School so_long project](https://github.com/Nuno-Jesus/so_long_invalidator.git)
    

### 🎨 Assets

ME!! I am a digital illustrator ☆ﾟ°˖* ᕕ( ᐛ )ᕗ buuuuut for you dear reader :

- https://itch.io/game-assets/free/tag-sprites
- [OpenGameArt](https://opengameart.org/)

---

## ✅ Checklist Before Submission

- [ ]  Map parsing is bulletproof (all rules checked)
- [ ]  No memory leaks (test with Valgrind)
- [ ]  ESC and window close work cleanly
- [ ]  Movement works & displayed correctly
- [ ]  Valid `.ber` maps work perfectly
- [ ]  Error messages are clear and user-friendly
- [ ]  Makefile with all rules
- [ ]  Git repo up-to-date
