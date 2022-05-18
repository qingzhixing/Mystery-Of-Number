#include<iostream>
using namespace std;
#include "../UnisgnedInteger.h"
int main(){
    typedef UnsignedInteger<64> TestType;
    TestType empty;
    cout<<empty.DataToString()<<endl;
    TestType array("1111111111111111111111111111111111111111111111111111111111111111");
    cout<<array.DataToString()<<endl;
    TestType instanceByInstance(empty);
    cout<<instanceByInstance.DataToString()<<endl;
    TestType::Base instanceByUnsignedInteger(empty);
    cout<<instanceByUnsignedInteger.DataToString()<<endl;
    TestType instanceByUInt(1145141919810U);
    instanceByUInt.LogicalShiftLeft (4);
    cout<<instanceByUInt.ToHexString()<<endl;
    return 0;
}