#include <iostream>
#include "functest.hpp"

using namespace std;

int main(){

    FuncTest foo;

    cout << "Hello World!" << endl;

    foo.BuildQ();
    foo.Execute();  ;

    return 0;
}

