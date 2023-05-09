# so_long
A basic 2D top-down game, written in C, designed for the project so_long, at 42 School.

A couple notes, ft_printf in libft does not work on my m1 mac, so i compiled all the libraries with the command arch -x86_64
this will work fine on an x86 mac as well.

all you will have to do is clone the repo, run make in the root directory, and run ./so_long "map.ber"

the map is entirely customizable, with each character in the .ber file representing a sprite in the game,
with a maximum of 24 sprites high.
1 for wall,
0 for ground,
P for player, (there must only be one)
C for collectible,
E for exit, (there must only be one)

The game is just an exercise and has no replayability or fun to speak of... it may be continued in the future, but i have
other projects to work on.

Thanks for looking! :)
