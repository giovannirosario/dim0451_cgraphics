#include "Polygon.h"
#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"
#include "Line.h"

Polygon::Polygon() {}

Polygon::Polygon(std::vector<Point2D> points, Color stroke_color) {
    this->stroke_color = stroke_color;
    this->fill = false;
    this->points = points;
}

Polygon::Polygon(std::vector<Point2D> points, Color stroke_color, Color fill_color) {
    this->stroke_color = stroke_color;
    this->fill_color = fill_color;
    this->fill = false;
    this->points = points;
}

Polygon::~Polygon() {}

void Polygon::draw_shape(Canvas& canvas) {
    for(unsigned int i = 0; i < points.size()-1; i++){
        Line temp_line = Line(points[i], points[i+1], this->stroke_color);
        temp_line.draw_shape(canvas);
    }

    Line temp_line = Line(points.back(), points[0], this->stroke_color);
    temp_line.draw_shape(canvas);
    
    if (fill) {
        //fill algo
    }

}