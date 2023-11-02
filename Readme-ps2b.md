# PS2B: Sokoban

## Contact
Name: Rahul Pingali
Section: 201
Time to Complete: 9-10 hours

## Description
Explain what the project does.
This project is the second part of the sokoban game. We are adding the gameplay mechanics in this game.
Describe what your major decisions were and why you did things that way.
My major decisions were to store the data in a 1d array and to do the math that way so it acts as a 2d array. I did it this way because I first attempted to use a matrix but that wasn't getting me very far so I switched gears and that helped me a lot. I
### Memory
Describe how you decided to store the level data including whether you used smart pointers.
I decided to store the data in a pointer to an array/1d array. At first I tried to use a matrix but it didn't work out so I switched to this method.
### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.
I used the find algorithm to find the player index on the map for each level, and I used this in the movePlayer() function. I also used the for each function in my isWon() to iterate over each element in the map. To implement a lambda expression, I updated my isWon() by using a lambda expression, which uses the find function to search for the boxes and the storage crates and finds their difference in the array and determiens that if it is 1, and the condition is true then the box is on the crate.
### Changes
In this updated version, I fixed the reset issue so that now the game resets properly, and I attempted to add a change where audio is played if the game is won. I added a lambda expression to simplify the isWon() function(see Lambdas section for description)
### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
1. I added code and downloaded an ogg file and added it to the directory for the extra credit, however it is not working even though the code seems right and I am not so sure why audio isn't being played when the game is won
2. There is a glitch where if the player sprite goes onto a storage crate, then the storage crate swaps positions with the player.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
I tried to add audio to the game when isWon(see Issues Section)

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.
https://fonts.google.com/
I used this to get the Roboto Bold font.

https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php- Used this to help with loading textures.
I also used this^ to help format and center the victory message in the sfml window.
Used lecture notes to do the math for the 1d array

https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
Used this to handle audio in sfml

https://www.youtube.com/watch?v=m3wH9K9cDcI
audio file used