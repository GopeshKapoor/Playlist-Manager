# Playlist-Manager
This document outlines the development of a Playlist Manager using a Singly Linked List data structure. The project aims to create an efficient system for managing music playlists dynamically, allowing users to add, remove, and traverse songs seamlessly. This project serves as a practical exercise in data structures and algorithm design, demonstrating the advantages of linked lists for dynamic data management.

# Problem Statement and Solution
## Problem:
Maintaining and managing playlists dynamically is a crucial feature in modern music applications. A static array-based playlist has limitations in terms of memory allocation and modification efficiency. Deleting or inserting songs at different positions in an array-based approach can lead to inefficient memory usage and time complexity.
## Solution:
This project proposes a Singly Linked List-based Playlist Manager, which provides dynamic memory allocation and efficient insertion/deletion operations. Using a linked list eliminates the constraints of fixed storage and allows smooth modifications to the playlist, making it a suitable solution for music applications.
The core problem addressed by this project is the inefficiency of using static array-based playlists. Arrays require a contiguous block of memory to be allocated, which can lead to wasted space if the playlist is not fully utilized. Furthermore, inserting or deleting songs in the middle of an array requires shifting elements, resulting in a time complexity of O(n), where n is the number of songs in the playlist. This can be slow and inefficient, especially for large playlists.
The solution is to use a Singly Linked List, which allows for dynamic memory allocation and efficient insertion/deletion operations. Linked lists do not require contiguous memory allocation, as each node stores a pointer to the next node in the list. This allows for more efficient memory usage, as memory is allocated only when needed. Inserting or deleting songs in a linked list requires only updating the pointers of the surrounding nodes, resulting in a time complexity of O(1) for insertion and deletion, assuming the position of the node is known.

# Features:
- Add songs to categorized playlists
- Delete any song from a playlist
- View all songs in a selected playlist
- Play any song from a playlist
- Pause or resume the currently playing song
- Play the next song in sequence
- Clear console interface for better experience

# Concepts Used:
- Singly Linked List (custom implementation)
- Structures and pointers
- Switch-case logic for menu handling
- Basic Object-Oriented Programming
- Clean input handling and formatted output

# Technologies:
- Language: C++
- IDE: Code::Blocks / VS Code
- Platform: Console

# How to Run:
- Clone the repo or copy the source code.
- Open it in any C++ compiler (e.g., Code::Blocks).
- Compile and run the main() function.
- Use the menu to interact with your playlists.


