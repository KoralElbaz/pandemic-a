#include <map>
#include "Board.hpp"

using namespace std;
namespace pandemic
{
    bool Board::isConnect(City& city1 , City& city2){
        if(connect.at(city1).count(city2)!=0) {return true;}
        else {return false;}
    }
    void Board::build_research_stations(City c){
        list_research_stations.insert(c);
    }
    bool Board::is_research_stations(City c){
        if(list_research_stations.count(c)!=0)
        {return true;}
        return false;
    }
    


    int& Board::operator[](City c)
    {
        return infection_level[c];

    }
    std::ostream &operator<<(std::ostream &os, const Board &c)
    {
        return os;
    }
    bool Board::is_clean(){
        return true;
    }
   

    std::map<City, std::set<City>> Board::connect
           {
            {SanFrancisco,{LosAngeles, Chicago, Tokyo, Manila}},
            {Chicago,{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
            {Atlanta,{Chicago, Miami, Washington}},
            {Montreal,{Chicago, Washington, NewYork}},
            {NewYork,{Montreal, Washington, London, Madrid}},
            {Washington,{Atlanta, NewYork, Montreal, Miami}},
            {London,{NewYork, Madrid, Essen, Paris}},
            {Madrid,{London, NewYork, Paris, SaoPaulo, Algiers}},
            {Paris,{Algiers, Essen, Madrid, Milan, London}},
            {Essen,{London, Paris,Milan, StPetersburg}},
            {Milan,{Essen, Paris, Istanbul}},
            {StPetersburg,{Essen, Istanbul, Moscow}},

            {LosAngeles,{SanFrancisco, Chicago, MexicoCity, Sydney}},
            {MexicoCity,{LosAngeles, Chicago, Miami, Lima, Bogota}},
            {Miami,{Atlanta, MexicoCity, Washington, Bogota}},
            {Bogota,{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
            {Lima,{MexicoCity, Bogota, Santiago}},
            {Santiago,{Lima}},
            {BuenosAires,{Bogota, SaoPaulo}},
            {SaoPaulo,{Bogota, BuenosAires, Lagos, Madrid}},
            {Lagos,{SaoPaulo, Khartoum, Kinshasa}},
            {Khartoum,{Cairo ,Lagos, Kinshasa, Johannesburg}},
            {Kinshasa,{Lagos, Khartoum, Johannesburg}},
            {Johannesburg,{Kinshasa, Khartoum}}
        };

}