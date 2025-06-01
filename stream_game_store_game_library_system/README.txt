The Stream Game Store — Game Library System
===========================================

This Python program simulates an online store called **The Stream Game Store**, designed to manage a digital game library for volunteers. It supports core functionalities like adding and removing games, managing a shopping cart, and simulating purchase flows. Volunteers can test the system but cannot own games.

---

🎮 Core Features
---------------

The program allows users (volunteers) to:

1. Add new games to the library  
2. Add games to a shopping cart  
3. View all games in the store  
4. View the current cart  
5. Remove games from the cart  
6. Remove games from the library  
7. Clear the cart  
8. Simulate purchasing games  
9. Check their balance

All game data is stored using a **dictionary** with the `game_id` as the key. Each value is a list containing:
- `game_name`  
- `game_numofcopies`  
- `game_description`  
- `game_price`

The shopping cart is implemented as a **list of game IDs** (dictionary keys).

---

🧩 Functional Overview
----------------------

### 1. `add_game_store(game_dict)`
Prompts the admin to input a new game’s details:
- `game_id` (string)
- `game_name` (string)
- `game_numofcopies` (int)
- `game_description` (string)
- `game_price` (float)

Stores the data in the `game_dict`.

---

### 2. `add_game_to_cart(cart_list, game_dict)`
Asks for a `game_id` and adds it to the `cart_list` if the game exists in the store.

---

### 3. `view_cart(cart_list, game_dict)`
Displays the contents of the shopping cart by fetching the corresponding game details from the store.

---

### 4. `view_games(game_dict)`
Lists all games currently available in the store library, including their name, description, price, and copies available.

---

### 5. `remove_game_from_cart(cart_list)`
Removes a game from the cart based on `game_id`. Informs the user if the game is not found in the cart.

---

### 6. `remove_games(game_dict)`
Removes a game from the main game library based on `game_id`. Updates the game dictionary accordingly.

---

### 7. `clear_cart(cart_list)`
Empties the entire cart list.

---

### 8. `buy_games(game_dict, cart_list, balance)`
Attempts to "purchase" all games in the cart:
- Verifies if enough copies are available.
- Computes the total cost of all games in the cart.
- Confirms that the total cost is within the user’s balance (default `10000`).
- If successful, reduces the copies in the game store and clears the cart.
- If conditions fail, shows an appropriate message and aborts the purchase.

---

### 9. `check_balance(balance)`
Displays the user’s current balance.  
Initial balance is set to **10000**.

---

🗂 Data Structure Summary
-------------------------

**Game Store Dictionary:**
```python
game_store = {
    "ID001": ["Elden Ring", 3, "Action RPG", 2499.00],
    "ID002": ["Stardew Valley", 10, "Farming Sim", 799.00],
}
