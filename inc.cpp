#include <SDL2/SDL.h>
#include <vector>
#include "inc.hpp"

Color::Color(int x,int y, int z, int q): r(x),g(y),b(z),a(q) {}
Color::Color(int x, int y, int z): Color(x,y,z,255) {}
Color::Color(): Color(0,0,0,255) {}

Pos2D::Pos2D(int a, int b): x(a),y(b) {}
Pos2D::Pos2D(): Pos2D(0,0) {}

void draw_pixel(SDL_Renderer* R, Color c, Pos2D p)
{
    SDL_SetRenderDrawColor(R,c.r,c.g,c.b,c.a);
    SDL_RenderDrawPoint(R,p.x,p.y);
}

void draw_line(SDL_Renderer* R, Color c, Pos2D p1, Pos2D p2)
{
    SDL_SetRenderDrawColor(R,c.r,c.g,c.b,c.a);
    SDL_RenderDrawLine(R, p1.x, p1.y, p2.x, p2.y);
}

Bar::Bar(int x, int len, int h, int r, int g, int b) {
    height = h;
    start.x = x;
    start.y = h/2 - len/2;
    end.x = x;
    end.y = h/2 + len/2;
    length = len;
    color.r = r;
    color.g = g;
    color.b = b;
}
void Bar::set_len(int l){
    length = l;
    start.y = height/2 - l/2;
    end.y = height/2 + l/2;
}
int Bar::get_len(){
    return length;
}
void Bar::draw(SDL_Renderer* r){
    draw_line(r, color, start, end);
}

//implementation of the Wall
Line::Line(Pos2D p1, Pos2D p2): p1(p1),p2(p2) {}

Map::Map(int w, int h){
    size.x = w;
    size.y = h;
}
void Map::create_wall(Pos2D a, Pos2D b){
    walls.push_back(Line(a,b));
}
void Map::draw(SDL_Renderer* r){
    for (int i = 0; i < walls.size(); i++)
    {
        draw_line(r, Color(255,255,255,255), walls[i].p1, walls[i].p2);
    }
}
