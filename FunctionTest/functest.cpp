#include "functest.hpp"
#include <queue>
#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <chrono>

using namespace std;
FuncTest::FuncTest(){

    functions.push_back( &FuncTest::A );
    functions.push_back( &FuncTest::B );
    functions.push_back( &FuncTest::C );
    functions.push_back( &FuncTest::D );
    functions.push_back( &FuncTest::E );
    functions.push_back( &FuncTest::F );
    functions.push_back( &FuncTest::G );

}

void FuncTest::BuildQ(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed) ;
    uniform_int_distribution<int> distribution( 0, functions.size()-1 );
    auto dice = bind( distribution, generator );
    int num, qsize = dice() * dice() + 1;

    for( int i = 0; i < qsize; ++i){
        num = dice();
        q.push( functions[ num ] );
    }
}

void FuncTest::Execute(){

    while( !q.empty() ){
        (this->*q.front())();
        q.pop();
    }
}

void FuncTest::A(){ cout << "A" << endl;}
void FuncTest::B(){ cout << " B" << endl;}
void FuncTest::C(){ cout << "  C" << endl;}
void FuncTest::D(){ cout << "   D" << endl;}
void FuncTest::E(){ cout << "    E" << endl;}
void FuncTest::F(){ cout << "     F" << endl;}
void FuncTest::G(){ cout << "      G" << endl;}
