#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include<array>
#include<string>
#include <algorithm>
template<size_t size>
class BitArray{
public:
    typedef size_t SizeType;
    //防止size_t溢出
    const static SizeType arraySize = ((size>0)?size:1);
    typedef std::array<bool, arraySize> BoolArray;

public:
    BitArray(){};
    BitArray(const BitArray& instance){
        this->data = instance.data;
    }
    BitArray(BitArray&& instance){
        this->data = std::move(instance.data);
    }
    BitArray(const std::string& str){
        //检测string是否合法
        for(auto item:str){
            if(item!='1'&&item!='0'){
                throw std::invalid_argument("string must be composed of only '0' and '1'");
            }
        }
        const int strSize = str.size();
        // 低位在前高位在后
        for(int i=0;i<strSize;++i){
            //判断越界
            if(i>=arraySize){
                break;
            }
            this->data[i] = (str[strSize-1-i]=='1');
        }
    }

    BitArray& operator=(const BitArray& instance){
        this->data = instance.data;
        return *this;
    }
    BitArray& operator=(BitArray&& instance){
        this->data = std::move(instance.data);
        return *this;
    }
    bool operator==(const BitArray& instance)const{
        return this->data == instance.data;
    }

public:
    void Clear(){
        for(SizeType i = 0; i < arraySize; ++i){
            this->data[i] = false;
        }
    }
    void SetAt(SizeType index, bool value){
        //索引溢出检查
        if(index >= arraySize){
            throw std::out_of_range("index out of range");
        }
        this->data[index] = value;
    }
    bool GetAt(SizeType index)const{
        //索引溢出检查
        if(index >= arraySize){
            throw std::out_of_range("index out of range");
        }
        return this->data[index];
    }
    void SetAll(bool value){
        for(SizeType i = 0; i < arraySize; ++i){
            this->data[i] = value;
        }
    }
    void FlipAt(SizeType index){
        //索引溢出检查
        if(index >= arraySize){
            throw std::out_of_range("index out of range");
        }
        this->data[index] = !this->data[index];
    }
    void FlipAll(){
        for(SizeType i = 0; i < arraySize; ++i){
            this->data[i] = !this->data[i];
        }
    }
    //设置第start~end位的值为value
    void SetRange(SizeType start, SizeType end, bool value){
        //索引溢出检查
        if(start >= arraySize || end >= arraySize){
            throw std::out_of_range("index out of range");
        }
        //索引合法检测
        if(start >= end){
            throw std::invalid_argument("start index must be less than end index");
        }
        for(SizeType i = start; i <= end; ++i){
            this->data[i] = value;
        }
    }
    //反转第start~end位的值
    void FlipRange(SizeType start, SizeType end){
        //索引溢出检查
        if(start >= arraySize || end >= arraySize){
            throw std::out_of_range("index out of range");
        }
        //索引合法检测
        if(start >= end){
            throw std::invalid_argument("start index must be less than end index");
        }
        for(SizeType i = start; i <= end; ++i){
            this->data[i] = !this->data[i];
        }
    }
    std::string ToBinString()const{
        std::string str;
        for(SizeType i = 0; i < arraySize; ++i){
            str += this->data[i] ? '1' : '0';
        }
        std::reverse(str.begin(), str.end());
        return std::move(str);
    }
    std::string ToHexString()const{
        std::string str;
        const char decToHexDigits[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        //从低位到高位求16进制数字
        int sum=0;//每4位一组，求和
        for(int i=0;i<arraySize; ++i){
            sum+=this->data[i]<<(i%4);
            if(i%4==3){
                str=decToHexDigits[sum]+str;
                sum=0;
            }
        }
        if(sum!=0){
            str=decToHexDigits[sum]+str;
        }
        str="0x"+str;
        return std::move(str);
    }
    //注意，此时str是ToBinString()的返回值的反转
    std::string DataToString()const{
        std::string str;
        for(SizeType i = 0; i < arraySize; ++i){
            str += this->data[i] ? '1' : '0';
        }
        return std::move(str);
    }
    void LogicalShiftRight(SizeType distance){
        //distance>=arraySize时取模
        distance%=arraySize;
        //移位
        for(SizeType i = 0; i < arraySize; ++i){
            if(i<arraySize-distance){
                this->data[i] = this->data[i+distance];
            }else{
                this->data[i] = 0;
            }
        }
    }
    void LogicalShiftLeft(SizeType distance){
        //distance>=arraySize时取模
        distance%=arraySize;
        //移位
        //int i防止SizeType负溢出
        for(int i = arraySize-1; i >= 0; --i){
            if(i>=distance){
                this->data[i] = this->data[i-distance];
            }else{
                this->data[i] = 0;
            }
            
        }
    }

protected:
    //数据从0~arraySize-1
    //低位在前，高位在后
    BoolArray data; 
};

#endif // !BIT_ARRAY_H