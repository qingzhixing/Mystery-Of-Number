#include<iostream>
using namespace std;
#include "../BitArray.h"
int main(){
    typedef BitArray<10> TestType;
    TestType array("111111111111111111111");
    cout<<array.DataToString()<<':'<<endl;

    TestType array2(array);
    cout<<"Clear()"<<endl;
    array2.Clear();
    cout<<array2.DataToString()<<endl;

    TestType array3(array);
    cout<<"SetAt(1,false)"<<endl;
    array3.SetAt(1,false);
    cout<<array3.DataToString()<<endl;

    cout<<"GetAt(3)"<<endl;
    cout<<array.GetAt(3)<<endl;

    TestType array4(array);
    cout<<"SetAll(true)"<<endl;
    array4.SetAll(true);
    cout<<array4.DataToString()<<endl;

    TestType array5(array);
    cout<<"FlipAt(3)"<<endl;
    array5.FlipAt(3);
    cout<<array5.DataToString()<<endl;

    TestType array6(array);
    cout<<"FlipAll()"<<endl;
    array6.FlipAll();
    cout<<array6.DataToString()<<endl;

    TestType array7(array);
    cout<<"SetRange(1,3,false)"<<endl;
    array7.SetRange(1,3,false);
    cout<<array7.DataToString()<<endl;

    TestType array8(array);
    cout<<"FlipRange(1,3)"<<endl;
    array8.FlipRange(1,3);
    cout<<array8.DataToString()<<endl;

    cout<<"ToBinString()"<<endl;
    cout<<array.ToBinString()<<endl;

    cout<<"ToHexString()"<<endl;
    cout<<array.ToHexString()<<endl;
}