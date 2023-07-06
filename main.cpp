#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

struct car
{
    string driver;
    string carname;
    string carid;
    int time;
};

class Parking
{
public:
    void park(Parking);
    void car_detail();
    void add_expense(car CAR[], int);
    void expense();
    void remove_car();
};

int num = 0;

void Parking ::park(Parking obj)
{
   cout << "                        -------------> Car Parking System <-------------" << endl;
   ofstream out;
   car CAR[100];
   out.open("parking.txt", _S_app); 
   /*
   _S_app is an openmode flag that specifies the mode in which the file is opened. 
   In this case, _S_app stands for "append mode," 
   which means that the content will be added to the end of the file if it already exists. 
   If the file does not exist, a new file will be created.
   */
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your name : ";
    getchar();
    getline(cin, CAR[num].driver);

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your car's name : ";
    getline(cin, CAR[num].carname);

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your car's number plate: ";
    cin >> CAR[num].carid;

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your time stay (In hours) : ";
    cin >> CAR[num].time;

    out << "Car Name : " << CAR[num].carname << endl
        << "Car Id : " << CAR[num].carid << endl
        << "Driver Name : " << CAR[num].driver << endl
        << "Car Time Stay : " << CAR[num].time << " hours" << endl;

    add_expense(CAR, num);

    num++;
    out.close();
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Your car is parked!!!" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    getch();
}

void Parking ::car_detail()
{
    system("cls");
    int i = 0;
    string id;
    string line;
    ifstream in;
    cout << "                        -------------> Your Car's Details <-------------" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your CarID : ";
    cin >> id;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    in.open("parking.txt");
    while(in.eof() == 0)
    {
        getline(in, line);
        size_t found = line.find(id);
        if (found != string::npos)
        {
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Your car's details are : " << endl;
            cout << line;
            getline(in, line);
            cout << endl;
            cout << line << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To Return" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            getch();
            in.close();
            i++;
            break;
        }
    }

    in.close();
    if (i == 0)
    {
        cout << "CarID " << id << " Not Found" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "TRY AGAIN! (Use correct CarID)" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Press Enter Key To Return" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        getch();
    }
}

void Parking ::add_expense(car CAR[], int num)
{
    ofstream out;

    out.open("parking.txt", _S_app);

    out << "Car ID: " << CAR[num].carid << endl
        << "Car Name: " << CAR[num].carname << endl
        << "Driver Name: " << CAR[num].driver << endl
        << "Car Time Stay: " << CAR[num].time << " hours" << endl
        << "Total Expense: " << CAR[num].time * 100 << " Rupees" << endl;

    out.close();
}

void Parking ::expense()
{
    system("cls");
    string id, line;
    int i = 0;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "                        -------------> Car Parking Expenses <-------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    cout << "Enter your CarID : ";
    cin >> id;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    in.open("parking.txt");
    while (in.eof() == 0)
    {
    getline(in, line);
    size_t found = line.find(id);
    if (found != string::npos)
        {
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Your car parking expense details are : " << endl;
            cout << line;
            getline(in, line);
            cout << endl;
            cout << line << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To Return" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            getch();
            in.close();
            i++;
            break;
        }
    }

    in.close();

    if (i == 0)
    {
        cout << "CarID " << id << " Not Found" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "TRY AGAIN! (Use correct CarID)" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Press Enter Key To Return" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        getch();
    }
}

void Parking ::remove_car()
{
    system("cls");
    string id;
    string line, nextline;

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "                        -------------> Car Parking Check Out System <-------------"
         << endl;
    cout << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    cout << "Enter your CarID : ";
    cin >> id;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;    

    ifstream in;
    ofstream out;
    in.open("parking.txt");
    out.open("tmp.txt", _S_app);
    while (in.eof() == 0)
    {
        getline(in, line);
        size_t found = line.find(id);
        if (found != string::npos)
        {
            getline(in, line);
            getline(in, line);
        }
        out << line;
        out << endl;
    }

    in.close();
    out.close();

    remove("parking.txt");
    rename("temp.txt", "parking.txt");

    in.open("parking_expense.txt");
    out.open("tmp_expense.txt", _S_app);
    while (in.eof() == 0)
    {
        getline(in, nextline);
        size_t found = nextline.find(id);
        if (found != string::npos)
        {
            getline(in, nextline);
            getline(in, nextline);
        }
        out << nextline;
        out << endl;
    }

    in.close();
    out.close();

    remove("parking_expense.txt");
    rename("tmp_expense.txt", "parking_expense.txt");

    cout << "Good Bye" << endl
         << "Thanks For Choosing Us!" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    getch();

}

int main()
{
    system("cls");
    Parking obj;
    while (1)
    {
        system("cls");
        int choice;
        cout << "                        -------------> Car Parking System <-------------" << endl
             << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "1. Park Your Car " << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "2. View Your Car Details" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "3. Check Expenses" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "4. Remove Your Car" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "5. EXIT" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            char yn;
            cout << "Do Your Want To Continue (y/n) : ";
            cin >> yn;
            system("cls");
            if (yn == 'y')
            {
                obj.park(obj);
            }
            system("cls");
            break;

        case 2:
            obj.car_detail();
            break;

        case 3:
            obj.expense();
            break;

        case 4:
            obj.remove_car();
            break;

        case 5:
            cout << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To EXIT";
            getch();
            exit(0);

        default:
            system("cls");
            cout << "You Entered A Wrong Choice!" << endl;
            break;
        }
    }

    return 0;
}