Problem Statement:
The Colossus Airlines has one plane with a seating capacity of 128. It makes Two inbound and two outbound flights daily (two round trips - 4 total flights). The program uses an array of structures for seats and array for storing 4 flight numbers. 
Each seat holds a seat identification number, a marker that indicates whether the seat is assigned, the last and the first name of the seat holder.

The program has 3 menus. The first menu chooses outbound flight, inbound flight or quit. The second menu asks for flight number or goes back to the main menu. The third menu lets the user see the list of empty seets, an alphabetical list of passengers, or return to main menu. When assigning or deleting a seat the user can abort, after each action the menu is shown again except when the user returns to the main menu.

Describe the Solution:
the first structure is seat that has a seat number, a marker that shows if its empty or taken, and a first and last name. The second is a 2d array called seats that has 4 rows for each flight and 128 seats per row. The third is an array called flights that has the flight numbers 101, 102, 201, and 202. The first two are outbound flights and the last 2 are inbound flights. main gives every seat its number then shows the first level menu inside a loop that repeats until the user chooses quit. Choosing outbound or inbound opens the second level loop menu. If the user chooses flight number the program asks for a number then searches the flights array for it. It only accepts outbound numbers from the outbound menu and inbound flight #s from the imbound menu. Trying 0 abourts and returns to the second level menu. A valid flight number calls a function named third menu and passes in the position of the flight in the array. In choices d and e typing 0 aborts and choice f ends the loop and returns to the previous menu.

Pros and Cons of your solution:
Cons: since everything is stored in memory, the seat assignments are lost after the program closes.
Bubble sort would be slower for a larger plane.

Pros: One seat structure and one 2d array data have the data for all 4 flights so nothing is repeated.
the menu is a loop so it comes back after every action.
