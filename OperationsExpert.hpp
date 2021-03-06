
#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


namespace pandemic
{

    class OperationsExpert: public Player

    {
        public:
        OperationsExpert(Board& b, City c): Player(b, c, "OperationsExpert"){}
        Player& build() override;
    };
}