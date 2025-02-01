#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
#include "ulliststr.cpp"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;
    dat.push_back("a");
    dat.push_front("b");
    dat.push_back("c");
    cout << "finished" << endl;
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    // prints: 8 7 9
    cout << "before popback " << dat.size() << endl;  // prints 3 since there are 3 strings stored

    dat.pop_back();

    // prints: 8 7 9
    cout << "after popback/before popfront " << dat.size() << endl;  // prints 3 since there are 3 strings stored

    dat.pop_front();
    
    cout << "after popfront " << dat.size() << endl;  // prints 3 since there are 3 strings stored

    dat.push_back("l");

    dat.push_front("c");

    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;

    

}
