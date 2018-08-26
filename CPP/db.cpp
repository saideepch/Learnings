#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;

    void enter ()
    {
        cout << "Enter id: " << endl;
        cin >> id;
        cout << "Enter name: " << endl;
        cin >> name;
    }

    void update ()
    {
        cout << "Re-enter id: " << endl;
        cin >> id;
        cout << "Re-enter name" << endl;
        cin >> name;
    }

    void display ()
    {
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
    }
};

int main ()
{
    vector<Student> studs (10);
    int ch=0, i=0, sid=0;

    while (1)
    {
    cout << "1.Enter 2.Display 3.Update 4.Delete: ";
    cin >> ch;

    switch (ch) {
    case 1:
        for (i=0;i<studs.size();i++) {
            studs[i].enter();
        }
        break;
    case 2:
        for (i=0;i<studs.size();i++) {
            studs[i].display();
        }
        break;
    case 3:
        cout << "Enter id to search: ";
        cin >> sid;
        for(i=0;i<studs.size();i++) {
            if(sid==studs[i].id) {
                studs[i].update();
                break;
            }
        }
        break;
    case 4:
        cout << "Enter id to delete: ";
        cin >> sid;
        for(i=0;i<studs.size();i++) {
            if(sid==studs[i].id) {
                studs.erase(studs.begin()+i);
            }
        }

        break;
    }
    }
    return 0;
}
