#ifndef UNSIGNED_INTEGER_H
#define UNSIGNED_INTEGER_H

#include "BitArray.h"
//无符号整数
template<size_t size>
class UnsignedInteger
    :public BitArray<size>{
public:
    typedef BitArray<size> Base;
    const static size_t arraySize = size;

public:
    UnsignedInteger(){};
    UnsignedInteger(const std::string& str):Base(str){};
    UnsignedInteger(const Base& baseInstance):Base(baseInstance){};
    UnsignedInteger(const UnsignedInteger& instance):Base(instance){};
    UnsignedInteger(Base&& baseInstance):Base(std::move(baseInstance)){};
    UnsignedInteger(UnsignedInteger&& instance):Base(std::move(instance)){};
    UnsignedInteger(uint64_t value){
        int index=0;//存储到第几位
        while(value&&index<arraySize){
            this->data[index++] = value&1;
            value>>=1;
        }
    }

    UnsignedInteger& operator=(const UnsignedInteger& instance){
        this->data = instance.data;
        return *this;
    }
    UnsignedInteger& operator=(UnsignedInteger&& instance){
        this->data = std::move(instance.data);
        return *this;
    }
};

#endif // !UNSIGNED_INTEGER_H