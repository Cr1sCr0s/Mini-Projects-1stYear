String Editor with Undo/Redo (Doubly Linked List) — Exercise 11
===============================================================

This C program allows users to interactively modify a string with features to replace, change characters, and append text. 
Users can also undo or redo their previous actions using a doubly linked list to track string states.

---------------------------------------------------------------
Program Flow
---------------------------------------------------------------

At program start, the user is prompted to input the initial string. 
The main menu then offers four options:

[1] Edit String  
[2] Undo  
[3] Redo  
[4] Exit  

Invalid inputs trigger error messages.

---------------------------------------------------------------
Edit String Submenu
---------------------------------------------------------------

When [1] Edit String is selected, the following submenu appears:

[1] Replace String  
[2] Change Character At  
[3] Append a String  
[4] Back to Main Menu  

Each option modifies the string and records the new state in a doubly linked list node.
Invalid choices or out-of-bounds indexes are rejected with proper messages.

---------------------------------------------------------------
Features
---------------------------------------------------------------

1. Replace String  
   - Replaces the entire string with a new one.  
   - Example: "hello" → replace with "world" → "world"

2. Change Character At  
   - Asks for an index and replaces the character at that index.  
   - Validates that the index is within bounds.  
   - Example: "world", index 1, char 'a' → "warld"

3. Append a String  
   - Concatenates a user-provided string to the current string.  
   - Example: "hi", append " there" → "hi there"

4. Undo  
   - Moves the pointer to the previous state in the doubly linked list.  
   - If no previous state exists, informs the user.

5. Redo  
   - Moves forward in the linked list if undo was previously used.  
   - If no redo state exists, informs the user.

---------------------------------------------------------------
Technical Implementation
---------------------------------------------------------------

- A doubly linked list is used to store each version of the string.
- Each node stores a copy of the string.
- On each edit, a new node is created and appended.
- Undo moves the pointer to the previous node.
- Redo moves to the next node, if available.
- Editing while not on the latest node removes all "future" nodes.

---------------------------------------------------------------
Example Interaction
---------------------------------------------------------------

Initial string: hello

Main Menu:
[1] Edit String
[2] Undo
[3] Redo
[4] Exit

> 1
Edit Menu:
[1] Replace String
[2] Change Character At
[3] Append a String
[4] Back to Main Menu

> 3
Enter string to append: world
String updated: helloworld

> 2
Undo successful. Current string: hello

> 3
Redo successful. Current string: helloworld

---------------------------------------------------------------
Compilation Instructions
---------------------------------------------------------------

Compile with:
gcc string_editor.c -o string_editor
./string_editor

---------------------------------------------------------------
Summary
---------------------------------------------------------------

This project demonstrates how to:
- Use doubly linked lists to implement undo/redo features
- Manage dynamic memory and state history
- Provide real-time, text-based string editing in C
- Design interactive menu-based systems with input validation
