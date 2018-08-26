#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Exam {
public:
    int IRA_SCR;
    int OS_SCR;
    int PS_SCR;
    int IM_SCR;
    Exam () : IRA_SCR(0),OS_SCR(0),PS_SCR(0),IM_SCR(0) { }

};

class Faculty {
public:
    string techlead;
    string bizlead;
    string seniorfaculty;
};

class Trainee : public Exam, public Faculty {
public:
    string name;
    long empid;
    string lg;
    string batch;
    int ch;

    void createTrainee ()
    {
        cout << "Enter employee id: ";
        cin >> empid;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter batch: ";
        cin >> batch;
        cout << "Enter LG: ";
        cin >> lg;
        cout << "Enter IRA score: ";
        cin >> IRA_SCR;
        cout << "Enter OS score: ";
        cin >> OS_SCR;
        cout << "Enter PS score: ";
        cin >> PS_SCR;
        cout << "Enter IM score: ";
        cin >> IM_SCR;
        cout << endl;
        assignFaculty ();
    }

    void assignFaculty ()
    {
        if (lg=="MCU87" || lg=="mcu87") {
            techlead="James";
            bizlead="Robert";
            seniorfaculty="Clara";
        } else if (lg=="MCU88" || lg=="mcu88") {
            techlead="George";
            bizlead="Francis";
            seniorfaculty="Paul";
        } else if (lg=="MCU89" || lg=="mcu89") {
            techlead="Jessy";
            bizlead="Mary";
            seniorfaculty="John";
        }
    }

    void updateTrainee ()
    {
        while(1)	{
            cout << endl;
            cout << "Select item to update 1.Employee ID 2.Name 3.LG 4.Batch 5.Return : ";
            cin >> ch;
            switch (ch) {
            case 1:
                cout << "Enter new employee ID: ";
                cin >> empid;
                cout << "Successfully updated!\n";
                break;
            case 2:
                cout << "Enter new name: ";
                cin >> name;
                cout << "Successfully updated!\n";
                break;
            case 3:
                cout << "Enter new LG: ";
                cin >> lg;
                cout << "Successfully updated!\n";
                assignFaculty ();
                break;
            case 4:
                cout << "Enter new batch: ";
                cin >> batch;
                cout << "Successfully updated!\n";
                break;
            case 5:
                return;
            }
        }
    }

    void display ()
    {
        cout << endl;
        cout << "Employee ID is: " << empid<<endl;
        cout << "Name is: " << name<<endl;
        cout << "Batch is: " << batch<<endl;
        cout << "LG is: " << lg<<endl;
        cout << endl;
    }
};

struct Compare {
    bool operator () (const Trainee& a, const Trainee& b) {
        return(a.IRA_SCR > b.IRA_SCR);
    }
};

//bool Compare (const Trainee& a, const Trainee& b){
//	return(a.IRA_SCR > b.IRA_SCR);
//}

int main ()
{
    int SIZE=0;
    cout << "Enter number of trainees: ";
    cin >> SIZE;
    vector <Trainee> tr (SIZE);
    int ch, ch2, i;
    long empid;
    string lg;
    while(1) {
        cout << "\nSelect option:\n 1.Create trainee details\n 2.Update trainee details\n 3.Display score details by LG and subject\n 4.View employee's trainers\n 5.Second highest scorer in IRA\n 6.View all trainees\n 7.Exit application\n";
        cin >> ch;
        switch (ch) {
        case 1:
            for(i=0; i<tr.size(); i++) {
                cout << "\nEnter associate number "<<i+1<<" details.."<<endl;
                tr[i].createTrainee ();
            }
            cout << "Details successfully entered!\n";
            break;
        case 2:
            cout << "Select associate employee ID to update data: ";
            cin >> empid;
            for(i=0; i<tr.size(); i++) {
                if(empid==tr[i].empid) {
                    tr[i].updateTrainee ();
                    break;
                }
            }
            break;
        case 3:
            cout << "Enter LG: ";
            cin >> lg;
            cout << "Select exam:\n 1.IRA Score\n 2.OS Score\n 3.PS Score\n 4.IM Score\n 5.All scores\n";
            cin >> ch2;
            for(i=0; i<tr.size(); i++) {
                if(lg==tr[i].lg) {
                    switch(ch2) {
                    case 1:
                        cout << "IRA Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].IRA_SCR<<endl;
                        break;
                    case 2:
                        cout << "OS Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].OS_SCR<<endl;
                        break;
                    case 3:
                        cout << "PS Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].PS_SCR<<endl;
                        break;
                    case 4:
                        cout << "IM Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].IM_SCR<<endl;
                        break;
                    case 5:
                        cout << "IRA Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].IRA_SCR<<endl;
                        cout << "OS Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].OS_SCR<<endl;
                        cout << "PS Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].PS_SCR<<endl;
                        cout << "IM Score of "<<tr[i].name<<" with employee ID "<<tr[i].empid<<" is " <<tr[i].IM_SCR<<endl;
                        break;
                    }
                }
            }
            break;
        case 4:
            cout << "Enter employee id: ";
            cin >> empid;
            for(i=0; i<tr.size(); i++) {
                if(empid==tr[i].empid) {
                    cout << "\nTech lead is "<<tr[i].techlead <<"\n"<< "Bizskill lead is "<<tr[i].bizlead <<"\n"<< "Senior faculty is "<<tr[i].seniorfaculty<<endl ;
                    cout<<endl;
                    break;
                }
            }
            break;
        case 5:
            sort(tr.begin(),tr.end(),Compare());
            cout << "\nThe second highest score is: "<<tr[1].IRA_SCR << endl;
            cout << "Employee id is " << tr[1].empid<<endl;
            cout << "Name is " << tr[1].name<<endl;
            cout << "Batch is " << tr[1].batch<<endl;
            cout << "LG is " << tr[1].lg<<endl<<endl;
            break;
        case 6:
            for(i=0; i<tr.size(); i++) {
                cout<<"\nAssociate number "<<i+1<<" :\n";
                tr[i].display ();
            }
            break;
        case 7:
            cout<<"Quitting.."<<endl;
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
