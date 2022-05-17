#include<iostream>
using namespace std;
#include "../UnisgnedInteger.h"
int main(){
    UnsignedInteger<32> empty;
    cout<<empty.DataToString()<<endl;
    UnsignedInteger<32> array("1111111111111111111111111111111111111111111111111111111111111111");
    cout<<array.DataToString()<<endl;
    UnsignedInteger<32> instanceByInstance(empty);
    cout<<instanceByInstance.DataToString()<<endl;
    BitArray<32> instanceByUnsignedInteger(empty);
    cout<<instanceByUnsignedInteger.DataToString()<<endl;
    return 0;
}