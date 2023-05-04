#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "inc.hpp"

#include <SDL2/SDL.h>

#define PI           3.14159265358979323846


const int WIDTH = 800, HEIGHT = 600;

int main(){

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH,HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    if (NULL == window){
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;

        return EXIT_FAILURE;
    }

    SDL_Event windowEvent;

    int i = 0, j = 0;
    Color red(255,255,0,255);
    Pos2D po(0,0), p1(15,7), p2(30,70), p3(123,34);

    //Bar b1(0,30,255,255,255), b2(1,35,200,200,200);

    std::vector<Bar> bars;
    
    for (int i = 0; i < WIDTH; i++){
        bars.push_back(Bar(i,(double)HEIGHT/WIDTH * i,HEIGHT,(255 - ((double)255/WIDTH) * i),255,255));
    }

    Map map(100,100);
    map.create_wall(Pos2D(0,0),Pos2D(30,27));
    map.create_wall(Pos2D(30, 10),Pos2D(50,67));
    for(int i = 0; i < 10; i++){
        map.create_wall(Pos2D(std::rand() % 100,std::rand() % 100),Pos2D(std::rand() % 100,std::rand() % 100));
    }


    while (true){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        //draw_line(renderer, red, p1, p2);
        //draw_line(renderer, red, p2, p3);
        //draw_line(renderer, red, p3, p1);
        
        //b1.draw(renderer);
        //b2.draw(renderer);

        for (int i = 0; i < WIDTH; i++){
            if(i != WIDTH - 1){
                bars[i].set_len(bars[i+1].get_len());
            }
            bars[i].draw(renderer);
        }

        bars[WIDTH - 1].set_len(std::rand() % (HEIGHT/10));

        map.draw(renderer); 

        if( SDL_PollEvent( &windowEvent)){
            if ( SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
        SDL_RenderPresent(renderer);
    }
    //yo
    SDL_DestroyWindow( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}
