# 2D_GameEngine
This is a 2D Game engine using Cpp having all the basic methods plus a small game example.
this project was made using Visual Studio community.


this Project contains:
     
    -2D_engine.cpp/main.h and 2D_engine.cpp/main.cpp: the main function contains the main game loop with the core game_fucntions calls.
     
    -2D_engine.cpp/assets : this folder contains some textures (Dirt, Grass, Water, Player1 and Player2) made with photoshop.
    
    -2D_engine.cpp/Collision.h and 2D_engine.cpp/Collision.cpp: this is the collision class were the collision physics are calculated               using The positions of two rectangles and their width ( recA.x + recA.w >= recB.x&& ).
    
    -2D_engine.cpp/Game.h and 2D_engine.cpp/Game.cpp:  this is where the main game methods are defined,= like (handleEvents, Update and               Render) and where the game objects are initialized.
    
    -2D_engine.cpp/map.h and 2D_engine.cpp/map.cpp: This is where the map is created as a 20 by 25 matrix containing values between 0 (For             the water texture) 1 (for Grass) and 2 (for Dirt) by changing the values of the cases you can change the layout of the map.
    
    -2D_engine.cpp/Texturemanager.h and 2D_engine.cpp/Texturemanager.cpp: is responsible for applying a texture to a given object as part 
            of the initialization.
            
           
