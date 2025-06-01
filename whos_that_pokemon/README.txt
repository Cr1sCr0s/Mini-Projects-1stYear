Who’s That Pokémon? — Mini-Game
===============================

This project is a Python-based mini-game where the player guesses Pokémon names based on partially hidden clues. The game randomly reveals three letters from each name, while the rest are masked with asterisks (*). The player attempts to guess the name and receives a score based on the number of correct guesses.

---

🎮 How the Game Works
---------------------

The game starts with a simple text-based **main menu**, allowing the user to:

1. **Add Pokémon** — Admins can add new Pokémon names to the database. Only names with **5 or more letters** are accepted to ensure meaningful clues.
2. **View All Pokémon** — Lists all currently stored Pokémon names.
3. **Play** — Starts the guessing game, where names are randomly selected and partially hidden.

---

🧠 Gameplay Logic
-----------------

- Each round, one name is shown with only **3 letters visible**, chosen at random positions.
- All remaining characters are replaced with “*”.
- The player is prompted to guess the full name.
- The number of rounds equals the number of Pokémon in the database.
- The list is **shuffled** at the start of each game to keep things unpredictable.
- At the end of the session, the player's **score** is displayed.

---

🔧 Randomization Details
------------------------

The `random` module is used for two purposes:

- `random.shuffle(pokemon_list)` — Randomizes the order of the Pokémon names before each game.
- `random.randrange(0, len(name))` — Picks random indices in each name to reveal.

---

🗃 File Structure
-----------------

- `main_menu()` — Displays the menu and handles navigation.
- `add_pokemon()` — Allows admin to add names (validated to be ≥5 letters).
- `view_all()` — Shows all names in the list.
- `play_game()` — Core game loop, handles hiding/revealing letters and tracking score.