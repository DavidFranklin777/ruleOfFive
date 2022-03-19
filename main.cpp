#include <iostream>
#include <string>
#include <cstring>
#include <array>

using namespace std;

class ruleOfFive
{
public:
    int var;
    int *buffer;

    // Assignment operator overloading
    // This helps us perform obj1 = obj2 effectively
    // obj1,obj2 are the objects of ruleOfFive
    ruleOfFive& operator=(const ruleOfFive& obj)
    {
        if(this != &obj)
        {
            var = obj.var;
            copy(obj.buffer, obj.buffer+sizeof(obj.buffer), buffer);
        }
        return *this;
    }

    // Copy constructor
    // This helps us perform obj1(obj2) effectively
    ruleOfFive(const ruleOfFive& obj)
    {
        var = obj.var;
        copy(obj.buffer, obj.buffer+sizeof(obj.buffer), buffer);
    }

    // Default constructor
    ruleOfFive()
        : var(0)
        , buffer(nullptr)
    {
    }

    // Move assignment operator overloading
    // This helps us perform obj1 = move(obj2)
    ruleOfFive& operator=(ruleOfFive&& obj)
    {
        swap(var, obj.var);
        swap(buffer, obj.buffer);
        obj.buffer = NULL;
        obj.var = 0;
        return *this;
    }

    // Move constructor
    // This helps us perform obj1(move(obj2))
    ruleOfFive(ruleOfFive &&obj)
    {
        swap(var, obj.var);
        swap(buffer, obj.buffer);
        obj.buffer = NULL;
        obj.var = 0;
    }


    // Destructor
    ~ruleOfFive()
    {
        delete buffer;
        buffer = NULL;
    }

};

int main()
{
    // Testing
    ruleOfFive obj1, obj2;
    obj1.var = 1;
    obj1.buffer = new int;
    obj1.buffer[0] = 55;
    cout << "initial " << obj1.buffer[0] << endl;
    obj2 = move(obj1);

    //cout << "obj1 var = " << obj1.var << " buf " << obj1.buffer[0] << endl;
    cout << "obj2 var = " << obj2.var << " buf " << obj2.buffer[0] << endl;

    return 0;
}
