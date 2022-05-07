#include <iostream>
#include <string>
#include <cstring>
#include <array>

using namespace std;

class ruleOfFive
{
public:

    // Default constructor
    // initialize everything to 0 or nullptr
    ruleOfFive()
        : var(0)
        , len(0)
        , buffer(nullptr)
    {
        cout << "Default constructor " << endl;
    }

    // User defined constructor
    // Use this to simply initialize the object
    ruleOfFive(int _var, int _len, char* _buffer)
        : var(_var)
        , len(_len)
    {
        buffer = new char(len);
        strncpy(buffer, _buffer, len);
    }

    // Copy constructor
    // This helps us perform obj1(obj2) effectively
    ruleOfFive(const ruleOfFive& obj)
    {
        if(this != &obj)
        {
            var = obj.var;
            len = obj.len;
            buffer = new char(len);
            strncpy(buffer, obj.buffer, len);
        }
    }

    // Assignment operator overloading
    // This helps us perform obj1 = obj2 effectively
    // obj1,obj2 are the objects of ruleOfFive
    ruleOfFive& operator=(const ruleOfFive& obj)
    {
        if(this != &obj)
        {
            if(buffer != nullptr)
                delete buffer;
            var = obj.var;
            len = obj.len;
            buffer = new char(len);
            strncpy(buffer, obj.buffer, len);
        }
        return *this;
    }

    // Move assignment operator overloading
    // This helps us perform obj1 = move(obj2)
    ruleOfFive& operator=(ruleOfFive&& obj)
    {
        // If we do not delete buffer here, it will be overwritten by a new memory address
        // That causes the previous buffer to be incapable of accessing, thus making it impossible to delete
        if(this != &obj)
        {
            if (buffer != nullptr)
                delete buffer;
            var = obj.var;
            len = obj.len;
            buffer = new char(len);
            strncpy(buffer, obj.buffer, len);
            delete obj.buffer;
            obj.buffer = nullptr;
            obj.var = 0;
            obj.len = 0;
        }

        return *this;
    }

    // Move constructor
    // This helps us perform obj1(move(obj2))
    ruleOfFive(ruleOfFive &&obj)
    {

        var = obj.var;
        len = obj.len;
        buffer = new char(len);
        strncpy(buffer, obj.buffer, len);
        obj.buffer = nullptr;
        obj.var = 0;
        obj.len = 0;
    }


    // Destructor
    ~ruleOfFive()
    {
        if(this->buffer!= nullptr)
        {
            delete buffer;
            buffer = nullptr;
        }

        cout << "Destructor " << endl;
    }

    int getVar()
    {
        return var;
    }

    int getLen()
    {
        return len;
    }

    char* getBuffer()
    {
        return buffer;
    }

private:
    int var;
    int len;
    char *buffer;

};

int main()
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Testing
    char s[] = "AttackOnTitan";
    ruleOfFive obj1(1,sizeof(s), s);
    ruleOfFive obj2(obj1);            // testing copy constructor
    ruleOfFive obj3;
    obj3 = obj1;                      // testing assignment operator
    ruleOfFive obj4(move(obj2));      // testing move constructor
    ruleOfFive obj5 = move(obj1);     // testing move assignment operator
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "obj2 = ";
    for(int i=0; i<obj2.getLen(); i++)
    {
        cout << *(obj2.getBuffer()+i);
    }

    cout << endl;

    cout << "obj3 = ";
    for(int i=0; i<obj3.getLen(); i++)
    {
        cout << *(obj3.getBuffer()+i);
    }

    cout << endl;

    cout << "obj4 = ";
    for(int i=0; i<obj4.getLen(); i++)
    {
        cout << *(obj4.getBuffer()+i);
    }

    cout << endl;

    cout << "obj5 = ";
    for(int i=0; i<obj5.getLen(); i++)
    {
        cout << *(obj5.getBuffer()+i);
    }

    cout << endl;



    return 0;
}
