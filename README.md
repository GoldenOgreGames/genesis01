### What is this?

Getting started in my journey to develop a Sega Genesis game using SGDK. 

### How to use it
Clone repo to a folder that contains the newest SGDK in its own folder. In my case, C:\SEGA_DEV\ has a folder called SGDK. with the clone in it's own folder, go into that folder and create a make.bat and type 
"C:\SEGA_DEV\SGDK\bin\make" -f "C:\SEGA_DEV\SGDK\makelib.gen" (change folder names or path if not set up the same way. After you run that, change makelib.gen to makefile.gen and save.

Now all you have to do is go into the CMD window, go into that directory and just run that batch file to compile. It will create new directories and with any luck, you'll have an object file and and OUT folder with a compiled rom called rom.bin. Use that in your favorite SEGA emulator and that's that. 
