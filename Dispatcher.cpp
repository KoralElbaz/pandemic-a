#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;


Player& Dispatcher::fly_direct(City c){
            if(board.is_research_stations(c))
            {
            this->city=c;
            return *this;
            }
            return Player::fly_direct(c);

        };