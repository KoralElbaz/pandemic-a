#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>

using namespace std;

namespace pandemic
{

    class Board
    {
        static std::map<City, std::set<City>> connect;
        std::map<City, int> infection_level;
        std::set<City> list_research_stations;


        public:
            Board(){}    
            int& operator[](City c);
            friend std::ostream &operator<<(std::ostream &os, const Board &c);
            bool is_clean();
            void remove_cures(){};

            //----------- help function -----------//
            bool isConnect(City& city1 , City& city2);
            void build_research_stations(City c);
            bool is_research_stations(City c);





    };
}