# so_long
This is a game project.
I developed a game from the scratch.
The game's goal is collect the red collectibles and go to exit and finish the game.

I use minilibx functions to put open a window and put images to window.
The minilibx is a small C library used for rendering graphics, primarily used by 42 students. As the name implies, this library is built on top of the X Window System API, to provide a much simpler programming interface suited for beginners

Compilation on macOS
use make command in the terminal to compile the executable.
MiniLibX requires Cocoa of MacOSX (AppKit) and OpenGL (it doesn’t use X11 anymore) we need to link them accordingly. This can cause a complicated compilation process. 

Compilation on Linux
use make Linux command to compile in Linux.
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
In case of Linux, you can use the Codam provided zip which is a Linux compatible MLX version. It has the exact same functions and shares the same function calls. Do mind, that using memory magic on images can differ as object implementations are architecture specific. Next, you should unzip the MLX for Linux in a new folder, in the root of your project, called mlx_linux.

<img width="1666" alt="Ekran Resmi 2022-11-26 ÖS 4 51 10" src="https://user-images.githubusercontent.com/98288229/204092213-e65c4834-f2aa-4472-8167-75f1f2aefc3d.png">
