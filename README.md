# Lab-04
CS 370 LAB04
TopDownShmup - Sam Tyler & Logan Puntous

Step 1: Open UProject to generate files, and click the option to rebuild missing modules.

If you get an error stating to rebuild from Source manually, either redownload/reopen the project or follow these steps:

a. Open Terminal (cmd+spacebar and type terminal)
b. Type this in the Terminal: cd "/Users/Shared/Epic\ Games/UE_5.0/Engine/Build/BatchFiles/Mac" and press enter
c. Then type this: sh "/Users/Shared/Epic\ Games/UE_5.0/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="/Path/To/Project/TestProj/TestProj.uproject" -game and press enter


Step 2: The game should be playable from launch, if you encounter errors, find the SpawnManager within the outliner and go to its details page. In the "Spawn" section, ensure that "Current Target" & "Dwarf Class" are set to BP_Dwarf.