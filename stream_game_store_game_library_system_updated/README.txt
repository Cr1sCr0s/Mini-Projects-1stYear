The Stream Game Store (Persistent Version)
==========================================

This updated version of The Stream Game Store includes **file-based persistence**. It stores and retrieves game inventory and balance information across sessions using a simple `.dat` file format. This enables the store to maintain data even after the program is closed and reopened.

---

💾 New Features: Persistence
----------------------------

In addition to the original functionality of managing a game library, shopping cart, and balance, this version includes:

### 1. `load_library(game_dict)`
- Reads data from a file called `library.dat`.
- Populates the input `game_dict` with inventory data from the file.
- Also retrieves and returns the user's balance (the first line in the file).

### 2. `save_library(game_dict, balance)`
- Writes the current balance and game inventory to `library.dat`.
- Overwrites the file with up-to-date information.

---

📁 File Format: `library.dat`
-----------------------------

The file follows a structured, comma-separated format:

