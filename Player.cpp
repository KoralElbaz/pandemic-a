
#include "Player.hpp"

using namespace std;
using namespace pandemic;

    Player& Player::drive(City c){
        if(!board.isConnect(this->city , c)){
           // throw std::invalid_argument{"Illegal action "};  
           //-------------------------------------------------------------------- false
                 return *this;

        }
        this->city=c;
        return *this;
    }

    Player& Player::fly_direct(City c){ 
        if(cards.count(c)==0){
           // throw std::invalid_argument{"Illegal action , you dont have this card"};
           //-------------------------------------------------------------------- false
                   return *this;

        }
        this->city=c;
        cards.erase(c);
        return *this;
    }

    Player& Player::fly_charter(City c){
        return *this;
    }
    Player& Player::fly_shuttle(City c){
        return *this;
    }
    Player& Player::build(){
        return *this;
    }
    Player& Player::discover_cure(Color c){
        return *this;
    }
    Player& Player::treat(City c){
        return *this;
    }
    Player& Player::take_card(City c){
        return *this;
    }
