#include <iostream>
#include <cmath>
#include <vector>
#include "inc.hpp"

#include <SDL2/SDL.h>

#define PI           3.14159265358979323846


const int WIDTH = 200, HEIGHT = 600;

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

    while (true){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        //draw_line(renderer, red, p1, p2);
        //draw_line(renderer, red, p2, p3);
        //draw_line(renderer, red, p3, p1);
        
        //b1.draw(renderer);
        //b2.draw(renderer);

        for (int i = 0; i < WIDTH; i++){
            if (i == 0) {

            }
            else {
                bars[WIDTH -1 -i].set_len(bars[WIDTH - i].get_len());
            }
            bars[i].draw(renderer);
        }
        bars[WIDTH -1].set_len(bars[0].get_len());

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
