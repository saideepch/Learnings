#include <iostream>

using namespace std; //Not good practise!!

//using String = std::string; //This works, so do this for cout endl etc. to avoid prefixing std::

class Entity
{
private:
    string m_Name;
public:
    Entity()
        : m_Name("Unknown") {}

    const string& GetName() const
    {
        return m_Name;
    }
};


int main ()
{
    Entity entity;
    //Entity entity("Saideep");
    //Entity entity = Entity("Saideep");
    Entity* entity2 = new Entity("Saideep"); //For heap alloc
    // int *a = new int;
    cout << entity.GetName() << endl;

    return 0;
}
