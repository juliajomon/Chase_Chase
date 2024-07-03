#include "raylib.h"
#include "raymath.h"

int main(){
    int width = 384;
    int height = 384;
    InitWindow(width,height,"Chase_Chase");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("WorldMap..png");
    
    Vector2 map_pos{0.0,0.0};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");

    float speed = 4.0;

    while (!WindowShouldClose())
    {
       BeginDrawing();
       ClearBackground(WHITE);
       
    

        Vector2 direction{};
        if(map_pos.x <= 0.0 && map_pos.y <= 0.0){
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D))  direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S))  direction.y += 1.0; 
        }
        else {if(map_pos.x >= 0.0) map_pos.x =0.0;
        else if(map_pos.y >= 0.0) map_pos.y =0.0;};
 


        if(Vector2Length(direction) != 0) {
            map_pos = Vector2Subtract(map_pos,Vector2Scale(Vector2Normalize(direction),speed)) ;
        }
       
       DrawTextureEx(map , map_pos , 0, 4.0 , WHITE);

       EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
    
}