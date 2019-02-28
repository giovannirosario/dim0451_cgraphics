#include "Line.h"
#include "Canvas.h"

Line::Line() {}

Line::~Line() {}

void Line::draw(Canvas canvas) {
    unsigned int x1 = start.get_x();
    unsigned int y1 = start.get_y();
    unsigned int x2 = end.get_x();
    unsigned int y2 = end.get_y();
    
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float p_k = 2 * (delta_y - delta_x);

    unsigned int x = x1;
    unsigned int y = y1;

    canvas.draw_pixel(x,y,color);

    for(x = x + 1; x < x2; x++) {
        if (p_k < 0) {
            p_k += 2 * delta_y;
        }
            
        else {
            y++;
            p_k += 2 * delta_y - 2 * delta_x;
        }

        canvas.draw_pixel(x,y,color);
    }
}