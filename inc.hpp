#include <SDL2/SDL.h>

class Color
{
    public:
        int r = 0;
        int g = 0;
        int b = 0;
        int a = 255;
        Color(int,int,int,int);
        Color(int,int,int);
        Color(); 
};

class Pos2D{
    public:
        int x;
        int y;
        Pos2D(int,int);
        Pos2D();
};

void draw_pixel();
void draw_line();

class Bar{
    private:
        int length;
        int height;
        Pos2D start, end;
    public:
        Color color;
        Bar(int, int, int, int, int, int);
        void draw(SDL_Renderer *);
        void set_len(int);
        int get_len();
};


