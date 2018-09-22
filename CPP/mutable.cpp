#include <iostream>

using namespace std; //Not good practise!!

class Entity
{
private:
    mutable string m_Name;
public:
    const string& GetName() const
    {
        m_Name = "blah"; //This works even though constructor is const since m_Name is mutable
        return m_Name;
    }

};


int main ()
{


    return 0;
}
