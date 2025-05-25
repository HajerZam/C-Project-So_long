<h1 align="center">🎮 C-Project: so_long</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg">
  <img src="https://img.shields.io/badge/42-Common%20Core-critical">
  <img src="https://img.shields.io/badge/score-100-brightgreen?style=flat-square">
</p>

<p align="center">
  🧱 My 7th project in the 42 Common Core <br>
  (≖_≖ ) good GOD …the horrors I witnessed.
</p>

---

## 🧠 What You’ll Learn

- 💡 **MiniLibX**: Basic graphics in C (rendering, input, events)
- 🗺️ **Map parsing**: Read & validate `.ber` maps
- 🧍 **Game logic**: Move the player, collect items, reach the exit
- 🧭 **Pathfinding**: Use DFS/BFS to validate solvability
- 🧼 **Memory management**: Avoiding leaks like your life depends on it
- 💀 **Bonus**: Enemies, animations, on-screen counters (for the brave)

---

## 🎯 Project Goal

Create a 2D tile-based game where a player:

- Navigates a map using **WASD**
- Collects all **C** (collectibles)
- Reaches the **E** (exit) **only** when all C are collected
- Avoids walking into **1** (walls)

---

## 🛠 Project Structure

```

so\_long/
├── src/
├── include/
│   ├── so\_long.h
│   ├── libft.h
│   └── ft\_printf.h
├── lib/
│   ├── minilibx-linux/
│   ├── libft/
│   └── ft\_printf/
├── assets/
├── maps/
├── main.c
└── Makefile

````

---

## 🧩 Map Format (`.ber`)

Maps are built from characters:

| Char | Meaning          |
|------|------------------|
| `1`  | Wall             |
| `0`  | Empty/floor      |
| `C`  | Collectible      |
| `E`  | Exit             |
| `P`  | Player start     |

✅ Must be rectangular  
✅ Enclosed by walls  
✅ 1 player `P`, 1 exit `E`, at least 1 `C`  
✅ All collectibles and exit must be reachable

---

## 🕹 Controls

- `W` → Move up
- `A` → Move left
- `S` → Move down
- `D` → Move right
- `ESC` → Quit game

---

## 🚶 Game Flow

- Render map to window
- Capture keypress events
- Move player (check walls)
- Pick up collectibles
- Only allow exit when all `C` are collected
- Track and display **move count**

---

## 🔄 Map Validation (DFS/BFS)

Check that all collectibles and the exit can be reached from the player’s position.

Common approach:
1. Duplicate the map
2. Use DFS/BFS to traverse from `P`
3. Check if you reached all `C` and `E`

---

## 🎨 Assets

You can use your own sprite art if you're a digital illustrator like yours truly (*chef’s kiss*), or get free assets here I guess 🙄 :

- https://itch.io/game-assets/free/tag-sprites
- https://opengameart.org/

Make sure images are `.xpm` (MiniLibX requirement).

---

## 🔧 Build & Run

### 🧱 Requirements

- Linux or WSL  
- MiniLibX (included in repo)

### 🏗 Compile

```bash
make
````

### ▶️ Run

```bash
./so_long maps/map1.ber
```

---

## ✨ Bonus Ideas

| Feature              | Status |
| -------------------- | ------ |
| 🧟 Enemy patrols     | ❓      |
| 🎞️ Animations       | ❓      |
| 🎯 In-window counter | ❓      |

---

## 🛠 Helpful Resources

### 📺 YouTube

* [MiniLibX Tutorial](https://www.youtube.com/watch?v=a1yD_lgDtmM)
* [2D Game in MiniLibX](https://www.youtube.com/watch?v=g5HEp2MxKtg)

### 📘 Guides

* [so\_long explained](https://github.com/0xAliK/42-So_long)
* [Map Validator Tool](https://github.com/Nuno-Jesus/so_long_invalidator.git)

---

## ✅ Pre-Submission Checklist

* [ ] `.ber` map parsing is airtight
* [ ] DFS/BFS path validation is solid
* [ ] MiniLibX window displays correctly
* [ ] Player movement works with WASD
* [ ] Exit opens only after collecting all `C`
* [ ] Terminal move counter prints correctly
* [ ] No memory leaks (test with `valgrind`)
* [ ] Clean `Makefile` with all rules
* [ ] ESC and X button exit cleanly
* [ ] Bonus features (if implemented) work bug-free
* [ ] Git repo is clean, commented, and pushed

---

## 🧪 Example Map

```
11111
1P0C1
10001
1C0E1
11111
```

---

## 🧹 Memory Management Tips

```bash
valgrind ./so_long maps/test.ber
```

Don’t forget:

* Free the map array
* Free textures and MLX pointers
* Close window and destroy display

---

## 🧵 Closing Thoughts

> “If you stare into the abyss of MiniLibX long enough, the abyss starts leaking memory.”

Stay hydrated. Comment your code.
And may your `.ber` files never segfault again.

---

<p align="center">
Made with 💀, 🎮 and maybe some tears by your local wizard
</p>

---
