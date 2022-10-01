#ifndef POINT_CLASS_HEADER_INCLUDED
#define POINT_CLASS_HEADER_INCLUDED

#include <cmath>

// A 2D point class
class Point
{
    double x, // x coordinate of point
           y; // y coordinate of point

public:


    void Output(void) const {
        std::cout << '(' << x << ", " << y << ')';
        return;
    };   // output this point
    void Input(void){
         char dummy;
         std::cin >> dummy
         >> x >> dummy >> y >> dummy;
         return;

    };          // input this point

    // distance between this point and other
    double distance(const Point & other) const{
        return sqrt(pow(x-other.x, 2.0) +
                    pow(other.y-y, 2.0));
    };
    // point in middle of this point and other
    Point midpoint(const Point & other) const{
         return Point((x+other.x)/2.0, (other.y+y)/2.0);


    };

    double get_x(void) const { return x; }  // accessors
    double get_y(void) const { return y; }

    void set_x(double new_x){
        x = new_x;
        return;

    };               // mutators
    void set_y(double new_y){
         y = new_y;
        return;

    };

    //constructors
    Point(void)
        :
        x{0},
        y{0}
    {

    }

    Point(const Point & p)
         :
          x {p.x},
          y {p.y}
    {

    }

     Point(double new_x, double new_y)
        :Point{}
        {
             set_x(new_x);
             set_y(new_y);

        }



    /////////////Unused
    Point flip_x(void) const; // new point is this one flipped
    Point flip_y(void) const; // about specified axis

    Point shift_x(double move_by) const;  // new point is this one
    Point shift_y(double move_by) const;  // shifted move_by in the
                                          // specified direction

    //   Point(void){ x = y = 0.0;};
   // Point(double new_x, double new_y){ set_x(new_x);set_y(new_y);};
  //  Point(const Point & p) { x = p.x; y = p.y;};

    ////////////////////////////

    Point & operator=(const Point & p) = default;
};

#endif
