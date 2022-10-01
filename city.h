#ifndef CITY_H_INC
#define CITY_H_INC

#include <iostream>

#include <string>
#include "city.h"

//City Header file


class City
    {
        Point location;
        std::string name;
    public:

        //getters
        double distance(const City & other) const
        {
            return location.distance(other.location);
        }

        Point get_location(void) const
        {
            return location;
        }

        std::string get_name(void) const{
            return name;
        }

        //setters
        void set_location(Point &p)
        {
           location.set_x(p.get_x());
           location.set_y(p.get_y());

        }
        /*
        void set_location(double x, double y)
        {
           location.set_x(x);
           location.set_y(y);

        }
        */

        void set_name(std::string input){
            name = input;

        }




    // other methods and constructors here




    //constructors
    City(void)
        :
          location{},
          name{"City"}

    {

    }

    City(const City & cityObj)
        :
          location{cityObj.location},
          name{cityObj.name}

    {

    }

    City(std::string nameIN, Point & p)
        : City{}
    {
       set_location(p);
       set_name(nameIN);


    }

    City & operator=(const City & c) = default;
    /*
     City(std::string nameIN, double x, double y)
        : City{}
    {
       set_location(x,y);
       set_name(nameIN);


    }
    */

    };






#endif
