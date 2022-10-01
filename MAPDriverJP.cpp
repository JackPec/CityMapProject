#include <iostream>
#include "Input_prot2.h"
#include "point.h"
#include "city.h"



//function prototypes

//////////
void menu(std::vector<City> &vec);
void distanceTwoCities(std::vector<City> &vec);
void cityInput(std::vector<City> &vec);
void citySort( std::vector<City> &vec);
void listoutput(std::vector<City> &vec);

bool insert(std::vector<City> & vec,
            std::vector<City>::size_type before_me,
            City new_item,
            std::vector<City>::size_type end);

void insertion(std::vector<City> & vec,short typeOfSort);
/////////////


int main()
{

    std::vector<City> cityList;
    menu(cityList);

    return 0;
}

///////////////




void menu(std::vector<City> &vec){

bool valid = true;
    while(valid){
        std::cout << " 1) Enter city Information" << std::endl;
        std::cout << " 2) calculate Distance between two cities"<< std::endl;
        std::cout << " 3) Print All cities"<< std::endl;
        std::cout << " 4) Sort the cities"<< std::endl;
        std::cout << " 5) Quit"<< std::endl;

        char menuChoice = input_protect<char>(" ");

        if(menuChoice == '1'||menuChoice == 'E'||menuChoice == 'I'){
            cityInput(vec);

        }
        else if(menuChoice == '2'||menuChoice == 'D'){
            distanceTwoCities(vec);

        }
        else if(menuChoice == '3'
                ||menuChoice == 'P'
                ||menuChoice == 'A'){
            listoutput(vec);
        }
        else if(menuChoice == '4'||menuChoice == 'S'){
            citySort(vec);
        }
        else if(menuChoice == '5'||menuChoice == 'Q'){
            valid = false;

        }

    }



}

void distanceTwoCities(std::vector<City> &vec){
    size_t indexCity1;
    size_t indexCity2;
    double distance;

  if (vec.size() < 2) {
      std::cout
      << "Need 2 or more cities to find distance." <<std::endl;

  }
  else if(vec.size()< 3){
    distance = vec[0].distance(vec[1]);
    std::cout << "Distance between " << vec[0].get_name()
    << " and " << vec[1].get_name() << " is: "
    << distance << std::endl;

  }
  else if(vec.size() >=  3){
        listoutput(vec);
        std::cout << "Select 2 indexes for 2 Citys:" <<std::endl;
        indexCity1 = input_protect("Index 1: ",
                     1, static_cast<int>(vec.size()));
        indexCity2 = input_protect("Index 2: ",
                     1, static_cast<int>(vec.size()));



        while(indexCity1 == indexCity2){
        std::cout << "Cant pick the same city twice: ";
        indexCity1 = input_protect("Index 1: ",
                     1, static_cast<int>(vec.size()));
        indexCity2 = input_protect("Index 2: ",
                     1, static_cast<int>(vec.size()));



        }

        indexCity1 = indexCity1 -1;
        indexCity2 = indexCity2 -1;

        if(indexCity1 != indexCity2){
        distance = vec[indexCity1].distance(vec[indexCity2]);
        std::cout << "Distance between "
        << vec[indexCity1].get_name()
        << " and " << vec[indexCity2].get_name()
        << " is: " << distance <<std::endl;



        }



  }


}

void cityInput(std::vector<City> &vec){


    bool valid = true;
    while(valid){


        City cityToAdd;

        std::string input;
        std::cout << "City Name: ";
            if (std::cin.peek() == '\n')
            {
                std::cin.ignore();
            }
        std::getline(std::cin,input);



        cityToAdd.set_name(input);

      //  double x,y;

      //   x = input_protect<double>("X value: ");

     //    y = input_protect<double>("Y value: ");

        Point newP;
        newP.Input();

        cityToAdd.set_location(newP);


        vec.push_back(cityToAdd);

      //  citySort(vec);

        bool stillvalid = input_protectChoiceBool(
                          "Want to proceed? Y/N ", "YyNn");

        if(stillvalid){

        }
        else{
          valid = false;
        }

        listoutput(vec);


    }


}



void citySort( std::vector<City> &vec){
    short typeOfSort = -1;
    // 1 is by name, 2 by x, 3 by y

bool valid = true;
    while(valid){
        std::cout << " 1) sort by Name: " << std::endl;
        std::cout << " 2) sort by X"<< std::endl;
        std::cout << " 3) sort by Y"<< std::endl;
        std::cout << " 4) Quit"<< std::endl;
       char menuChoice = input_protect<char>(" ");

        if(menuChoice == '1'||menuChoice == 'N'){
            typeOfSort = 1;

        }
        else if(menuChoice == '2'||menuChoice == 'X'){
            typeOfSort = 2;

        }
        else if(menuChoice == '3'||menuChoice == 'Y'){
            typeOfSort = 3;

        }
         else if(menuChoice == '4'||menuChoice == 'Q'){
            valid = false;

        }

        insertion(vec,typeOfSort);

        listoutput(vec);
    }

}


void listoutput(std::vector<City> &cityList){
    std::cout <<  "\n  City List: \n"  << std::endl;

     for (std::vector<City>::size_type i = 0;
     i < cityList.size(); ++i)
    {
        std::cout << i+1 <<":  "+ cityList[i].get_name() << " ("
        << cityList[i].get_location().get_x() <<","
        << cityList[i].get_location().get_y() <<")" << std::endl;
    }

    std::cout <<  "\n"  << std::endl;

}



bool insert(std::vector<City> & vec,
            std::vector<City>::size_type before_me,
            City new_item, std::vector<City>::size_type end)
{
    bool okay = before_me < end;
    if (okay)
    {
        for (std::vector<City>::size_type pos = end;
        pos > before_me; pos--)
        {
            vec[pos] = City(vec[pos-1]);
        }
        vec[before_me] = new_item;
    }
    return okay;
}



void insertion(std::vector<City> & vec, short typeOfSort)
{
    std::vector<City>::size_type dest;
    Point p;
    City holder("City", p); //should fix the city warnings
    if(typeOfSort == 1){
        for (std::vector<City>::size_type next = 1;
        next < vec.size(); ++next)
        {
            holder = City(vec[next]);
            dest = next;
            while (dest > 0 &&           // look amongst the already sorted
                   vec[dest-1].get_name() > holder.get_name()) // for where the new guy goes (in front)
                   //change this gator to change ascending order
            {
                --dest;
            }
            if (dest != next)               // not already in place?
            {
                insert(vec, dest, holder, next);    // insert 'im in front of dest
            }
        }
    }
    else if (typeOfSort == 2){
        for (std::vector<City>::size_type next = 1;
        next < vec.size(); ++next)
        {
            holder = vec[next];
            dest = next;
            while (dest > 0 && // look amongst the already sorted
                   vec[dest-1].get_location().get_x() < holder.get_location().get_x())
                   // for where the new guy goes (in front)
                   //change this gator to change ascending order
            {
                --dest;
            }
            if (dest != next)               // not already in place?
            {
                insert(vec, dest, holder, next);    // insert 'im in front of dest
            }
        }


    }
    else if (typeOfSort == 3){
        for (std::vector<City>::size_type next = 1; next < vec.size(); ++next)
        {
            holder = vec[next];
            dest = next;
            while (dest > 0 &&           // look amongst the already sorted
                   vec[dest-1].get_location().get_y() < holder.get_location().get_y())
                   // for where the new guy goes (in front)
                   //change this gator to change ascending order
            {
                --dest;
            }
            if (dest != next)               // not already in place?
            {
                insert(vec, dest, holder, next);    // insert 'im in front of dest
            }
        }


    }
    return;
}


