#include "doctest.h"
#include <string>
#include <iostream>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"


using namespace std;
using namespace pandemic;


Board board;

//The players 
OperationsExpert builder_research_station{board, HongKong};
OperationsExpert operationsExpert{board, HongKong};
Dispatcher dispatcher{board, HongKong};
Scientist scientist{board, HongKong, 4};
Researcher researcher{board, HongKong};
Medic medic{board, HongKong};
Virologist virologist{board, HongKong};
GeneSplicer geneSplicer{board, HongKong};
FieldDoctor fieldDoctor{board, HongKong};

//all the players take card to this city
void all_players_take_card(City city) {
    operationsExpert.take_card(city);
    dispatcher.take_card(city);
    scientist.take_card(city);
    researcher.take_card(city);
    medic.take_card(city);
    virologist.take_card(city);
    geneSplicer.take_card(city);
    fieldDoctor.take_card(city);
}

void new_diff_start_pos(){

    operationsExpert.take_card(SanFrancisco);
        operationsExpert.fly_direct(SanFrancisco);
    dispatcher.take_card(Washington);
        operationsExpert.fly_direct(Washington);
    scientist.take_card(LosAngeles);
        operationsExpert.fly_direct(LosAngeles);
    researcher.take_card(Lagos);
        operationsExpert.fly_direct(Lagos);
    medic.take_card(Algiers);
        operationsExpert.fly_direct(Algiers);
    virologist.take_card(Chennai);
        operationsExpert.fly_direct(Chennai);
    geneSplicer.take_card(Tokyo);
        operationsExpert.fly_direct(Tokyo);
    fieldDoctor.take_card(Sydney);
        operationsExpert.fly_direct(Sydney);
   
        
}

void take_diff_card(){

    operationsExpert.take_card(SanFrancisco);
    dispatcher.take_card(Washington);
    scientist.take_card(LosAngeles);
    researcher.take_card(Lagos);
    medic.take_card(Algiers);
    virologist.take_card(Chennai);
    geneSplicer.take_card(Tokyo);
    fieldDoctor.take_card(Sydney);
   
        
}

void build_in_research_station(City city) {
    builder_research_station.take_card(city);
    builder_research_station.fly_direct(city);
    builder_research_station.build();
}



TEST_CASE("BOARD TEST")
{// start pos of number of disease

    CHECK(board.is_clean() == true);

    board[SanFrancisco] = 4;
            CHECK(board[SanFrancisco] == 4);

    board[LosAngeles] = 4;
            CHECK(board[LosAngeles] == 4);
            
    board[Moscow] = 4;
            CHECK(board[Moscow] == 4);

    board[Beijing] = 4;
            CHECK(board[Beijing] == 4);

    board[Chicago] = 4;
            CHECK(board[Chicago] == 4);

    board[MexicoCity] = 4;
            CHECK(board[MexicoCity] == 4);

    board[Istanbul] = 4;
            CHECK(board[Istanbul] == 4);

    board[Seoul] = 4;
            CHECK(board[Seoul] == 4);


    //Able to change the number of disease
    board[SanFrancisco] = 3;
            CHECK(board[SanFrancisco] == 3);

    board[LosAngeles] = 2;
            CHECK(board[LosAngeles] == 2);
            
    board[Moscow] = 3;
            CHECK(board[Moscow] == 3);

    board[Beijing] = 2;
            CHECK(board[Beijing] == 2);

    board[Chicago] = 3;
            CHECK(board[Chicago] == 3);

    board[MexicoCity] = 2;
            CHECK(board[MexicoCity] == 2);

    board[Istanbul] = 3;
            CHECK(board[Istanbul] == 3);

    board[Seoul] = 2;
            CHECK(board[Seoul] == 2);

    CHECK(board.is_clean() == false);

}

TEST_CASE("TEST drive")
{
//Able to drive to a nearby city in the same color.
            CHECK_NOTHROW(operationsExpert.drive(Bangkok));
            CHECK_NOTHROW(dispatcher.drive(Bangkok));
            CHECK_NOTHROW(scientist.drive(Bangkok));
            CHECK_NOTHROW(researcher.drive(Bangkok));
            CHECK_NOTHROW(medic.drive(Bangkok));
            CHECK_NOTHROW(virologist.drive(Bangkok));
            CHECK_NOTHROW(geneSplicer.drive(Bangkok));
            CHECK_NOTHROW(fieldDoctor.drive(Bangkok));
//Able to drive to a nearby city in a diff color.
            CHECK_NOTHROW(operationsExpert.drive(Kolkata));
            CHECK_NOTHROW(dispatcher.drive(Kolkata));
            CHECK_NOTHROW(scientist.drive(Kolkata));
            CHECK_NOTHROW(researcher.drive(Kolkata));
            CHECK_NOTHROW(medic.drive(Kolkata));
            CHECK_NOTHROW(virologist.drive(Kolkata));
            CHECK_NOTHROW(geneSplicer.drive(Kolkata));
            CHECK_NOTHROW(fieldDoctor.drive(Kolkata));
//Unable to drive to a non nearby city in the same color
            CHECK_THROWS(operationsExpert.drive(Istanbul));
            CHECK_THROWS(dispatcher.drive(Istanbul));
            CHECK_THROWS(scientist.drive(Istanbul));
            CHECK_THROWS(researcher.drive(Istanbul));
            CHECK_THROWS(medic.drive(Istanbul));
            CHECK_THROWS(virologist.drive(Istanbul));
            CHECK_THROWS(geneSplicer.drive(Istanbul));
            CHECK_THROWS(fieldDoctor.drive(Istanbul));
//Unable to drive to a non nearby city in a diff color
            CHECK_THROWS(operationsExpert.drive(Paris));
            CHECK_THROWS(dispatcher.drive(Paris));
            CHECK_THROWS(scientist.drive(Paris));
            CHECK_THROWS(researcher.drive(Paris));
            CHECK_THROWS(medic.drive(Paris));
            CHECK_THROWS(virologist.drive(Paris));
            CHECK_THROWS(geneSplicer.drive(Paris));
            CHECK_THROWS(fieldDoctor.drive(Paris));
}


TEST_CASE ("TEST fly_direct") 
{
    //Able to fly direct to Miami becouse we have Miami's card
    all_players_take_card(Miami);
    CHECK_NOTHROW(operationsExpert.fly_direct(Miami));
    CHECK_NOTHROW(dispatcher.fly_direct(Miami));
    CHECK_NOTHROW(scientist.fly_direct(Miami));
    CHECK_NOTHROW(researcher.fly_direct(Miami));
    CHECK_NOTHROW(medic.fly_direct(Miami));
    CHECK_NOTHROW(virologist.fly_direct(Miami));
    CHECK_NOTHROW(geneSplicer.fly_direct(Miami));
    CHECK_NOTHROW(fieldDoctor.fly_direct(Miami));

    all_players_take_card(Miami);
     //Unable to fly direct to Santiago (they can fly charter)
    // becouse we dont have Santiago's card
    CHECK_THROWS(operationsExpert.fly_direct(Santiago));
    CHECK_THROWS(dispatcher.fly_direct(Santiago));
    CHECK_THROWS(scientist.fly_direct(Santiago));
    CHECK_THROWS(researcher.fly_direct(Santiago));
    CHECK_THROWS(medic.fly_direct(Santiago));
    CHECK_THROWS(virologist.fly_direct(Santiago));
    CHECK_THROWS(geneSplicer.fly_direct(Santiago));
    CHECK_THROWS(fieldDoctor.fly_direct(Santiago));
    


}

TEST_CASE ("TEST fly_charter")
{
    //all the player now in Miami with card to Miami
    //able to fly charter to Miami
            CHECK_NOTHROW(operationsExpert.fly_charter(BuenosAires));
            CHECK_NOTHROW(dispatcher.fly_charter(BuenosAires));
            CHECK_NOTHROW(scientist.fly_charter(BuenosAires));
            CHECK_NOTHROW(researcher.fly_charter(BuenosAires));
            CHECK_NOTHROW(medic.fly_charter(BuenosAires));
            CHECK_NOTHROW(virologist.fly_charter(BuenosAires));
            CHECK_NOTHROW(geneSplicer.fly_charter(BuenosAires));
            CHECK_NOTHROW(fieldDoctor.fly_charter(BuenosAires));
    all_players_take_card(Taipei);
    //unable to fly direct to Taipei 
            CHECK_THROWS(operationsExpert.fly_charter(Taipei));
            CHECK_THROWS(dispatcher.fly_charter(Taipei));
            CHECK_THROWS(scientist.fly_charter(Taipei));
            CHECK_THROWS(researcher.fly_charter(Taipei));
            CHECK_THROWS(medic.fly_charter(Taipei));
            CHECK_THROWS(virologist.fly_charter(Taipei));
            CHECK_THROWS(geneSplicer.fly_charter(Taipei));
            CHECK_THROWS(fieldDoctor.fly_charter(Taipei));

}

TEST_CASE ("TEST fly_shuttle") 
{
    //all the player now in Miami with card to BuenosAires
     build_in_research_station(BuenosAires);
     build_in_research_station(Miami);


     //able to fly shuttle to Miami (a city with research station)
    CHECK_NOTHROW(operationsExpert.fly_shuttle(Miami));
    CHECK_NOTHROW(dispatcher.fly_shuttle(Miami));
    CHECK_NOTHROW(scientist.fly_shuttle(Miami));
    CHECK_NOTHROW(researcher.fly_shuttle(Miami));
    CHECK_NOTHROW(medic.fly_shuttle(Miami));
    CHECK_NOTHROW(virologist.fly_shuttle(Miami));
    CHECK_NOTHROW(geneSplicer.fly_shuttle(Miami));
    CHECK_NOTHROW(fieldDoctor.fly_shuttle(Miami));

     //unable to fly shuttle to Chicago (a city without research station)
    CHECK_THROWS(operationsExpert.fly_shuttle(Chicago));
    CHECK_THROWS(dispatcher.fly_shuttle(Chicago));
    CHECK_THROWS(scientist.fly_shuttle(Chicago));
    CHECK_THROWS(researcher.fly_shuttle(Chicago));
    CHECK_THROWS(medic.fly_shuttle(Chicago));
    CHECK_THROWS(virologist.fly_shuttle(Chicago));
    CHECK_THROWS(geneSplicer.fly_shuttle(Chicago));
    CHECK_THROWS(fieldDoctor.fly_shuttle(Chicago));

}



TEST_CASE ("TEST build") 
{
        new_diff_start_pos();
        take_diff_card();

        //able to build all over and **operationsExpert** didnt waste his card
            CHECK_NOTHROW(operationsExpert.build());
            CHECK_NOTHROW(operationsExpert.fly_charter(Miami)); //just now throwing the SanFrancisco card!
            CHECK_NOTHROW(dispatcher.build());
            CHECK_NOTHROW(scientist.build());
            CHECK_NOTHROW(researcher.build());
            CHECK_NOTHROW(medic.build());
            CHECK_NOTHROW(virologist.build());
            CHECK_NOTHROW(geneSplicer.build());
            CHECK_NOTHROW(fieldDoctor.build());
    //bringing operations expert back to SanFrancisco
    operationsExpert.take_card(SanFrancisco);
    operationsExpert.fly_direct(SanFrancisco);
    take_diff_card();
    //unable to build all over again but doesn't throw exception
            CHECK_NOTHROW(operationsExpert.build());
            CHECK_NOTHROW(operationsExpert.fly_charter(Miami)); //just now throwing the SanFrancisco card!
            CHECK_NOTHROW(dispatcher.build());
            CHECK_NOTHROW(scientist.build());
            CHECK_NOTHROW(researcher.build());
            CHECK_NOTHROW(medic.build());
            CHECK_NOTHROW(virologist.build());
            CHECK_NOTHROW(geneSplicer.build());
            CHECK_NOTHROW(fieldDoctor.build());
    //bringing operations expert back to SanFrancisco
    operationsExpert.take_card(SanFrancisco);
    operationsExpert.fly_direct(SanFrancisco);
}

// TEST_CASE ("TEST discover_cure") 
// {

// }

// TEST_CASE ("TEST treat") 
// {

// }