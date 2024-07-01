#include "raylib.h"
int main(){
    int width = 384;
    int height = 384;
    InitWindow(width,height,"Chase_Chase");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("WorldMap..png");
    Vector2 map_pos{0.0,0.0};

    while (!WindowShouldClose())
    {
       BeginDrawing();
       ClearBackground(WHITE);

       DrawTextureEx(map , map_pos , 0, 4.0 , WHITE);

       EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
    
}