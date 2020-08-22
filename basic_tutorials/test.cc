#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream sst;
    sst << 123;
    cout << sst.str().c_str()[0] << endl;
    cout << sst.str().c_str()[1] << endl;
    cout << sst.str().c_str()[2] << endl;
    cout << sst.str().c_str()[3] << endl;
}