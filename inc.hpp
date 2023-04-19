#include <SDL2/SDL.h>
#include <vector>

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

void draw_pixel(SDL_Renderer*, Color, Pos2D);
void draw_line(SDL_Renderer*, Color, Pos2D, Pos2D);

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

class Line{
    public:
        Pos2D p1, p2;
        Line(Pos2D, Pos2D);
};

class Map{
    private:
        std::vector<Line> walls;
        Pos2D size;
    public:
        Map(int w, int h);
        void create_wall(Pos2D, Pos2D);
        void draw(SDL_Renderer* r);
};


