#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Car
{
private:
    string driverName;
    string carName;
    string carId;
    int timeStay;

public:
    Car(const string& driverName, const string& carName, const string& carId, int timeStay)
    {
        this->driverName = driverName;
        this->carName = carName;
        this->carId = carId;
        this->timeStay = timeStay;
    }

    string getDriverName() const
    {
        return driverName;
    }

    string getCarName() const
    {
        return carName;
    }

    string getCarId() const
    {
        return carId;
    }

    int getTimeStay() const
    {
        return timeStay;
    }
};

class ParkingLot
{
private:
    vector<Car> parkedCars;
    string fileName;

public:
    ParkingLot(const string& filename);
    void parkCar();
    void displayCarDetails();
    void removeCar();
    void saveToFile();
    void searchRecord();
};

ParkingLot::ParkingLot(const string& fileName)
{
    this -> fileName = fileName;
}

void ParkingLot::parkCar()
{
    system("cls");
    string driverName, carName, carId;
    int timeStay;

    cout << "Enter driver name: ";
    cin.ignore();
    getline(cin, driverName);

    cout << "Enter car name: ";
    getline(cin, carName);

    cout << "Enter car ID: ";
    getline(cin, carId);

    cout << "Enter time of stay (in hours): ";
    cin >> timeStay;
    cin.ignore();

    Car newCar(driverName, carName, carId, timeStay);
    parkedCars.push_back(newCar);
    cout << "Car parked successfully!" << endl;
    saveToFile();
}

void ParkingLot::displayCarDetails()
{
    system("cls");
    cout << "Enter car ID: ";
    string carId;
    cin.ignore();
    getline(cin, carId);

    // auto it = find_if(parkedCars.begin(), parkedCars.end(), [&](const Car& car)
    // {
    //     return car.getCarId() == carId;
    // });
    
    vector<Car>::iterator it = parkedCars.begin();
    while(it != parkedCars.end())
    {
        if(it -> getCarId() == carId) break;
        it++;
    }

    if (it != parkedCars.end())
    {
        cout << "Car Details:" << endl;
        cout << "Driver Name: " << it->getDriverName() << endl;
        cout << "Car Name: " << it->getCarName() << endl;
        cout << "Car ID: " << it->getCarId() << endl;
        cout << "Time of Stay: " << it->getTimeStay() << " hours" << endl;
        cout << "Fee: " << it->getTimeStay() * 40 << ".000 (VND)" << endl;
    }
    else
    {
        cout << "Car not found!" << endl;
    }
}

void ParkingLot::removeCar()
{
    system("cls");
    cout << "Enter car ID: ";
    string carId;
    cin.ignore();
    getline(cin, carId);

    // auto it = find_if(parkedCars.begin(), parkedCars.end(), [&](const Car& car)
    // {
    //     return car.getCarId() == carId;
    // });

    vector<Car>::iterator it = parkedCars.begin();
    while(it != parkedCars.end())
    {
        if(it -> getCarId() == carId) break;
        it++;
    }

    if (it != parkedCars.end())
    {
        parkedCars.erase(it);
        cout << "Car removed from the parking lot!" << endl;

        saveToFile();
    }
    else
    {
        cout << "Car not found!" << endl;
    }
}

void ParkingLot::saveToFile()
{
    ofstream outputFile(fileName);

    if (!outputFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    for (const auto& car : parkedCars)
    {
        outputFile << "Driver Name: " << car.getDriverName() << endl;
        outputFile << "Car Name: " << car.getCarName() << endl;
        outputFile << "Car ID: " << car.getCarId() << endl;
        outputFile << "Time of Stay: " << car.getTimeStay() << " hours" << endl;
        outputFile << "Fee: " << car.getTimeStay() * 40 << ".000 (VND)"<< endl;  
        outputFile << "----------------------" << endl;
    }

    outputFile.close();
}

void ParkingLot::searchRecord()
{
    int choice;
    do {
        system("cls");
        cout << "\n\n\t\t\t--------------------------------------------------\n";
        cout << "\t\t\t\t    Car Parking Management System\n";
        cout << "\t\t\t--------------------------------------------------\n";
        cout << "\t\t\t\t1. Park a Car" << endl;
        cout << "\t\t\t\t2. Display Car Details" << endl;
        cout << "\t\t\t\t3. Remove a Car" << endl;
        cout << "\t\t\t\t4. Exit" << endl;
        cout << "\n\t\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            parkCar();
            cout << "Press any key to continue......\n";
            break;
        case 2:
            displayCarDetails();
            cout << "Press any key to continue......\n";
            break;
        case 3:
            removeCar();
            cout << "Press any key to continue......\n";
            break;
        case 4:
            system("cls");
            cout << "SEE YOU AGAIN..." << endl;
            break;
        default:
            system("cls");
            cout << "Invalid choice. Please try again." << endl;
            cout << "Press any key to continue......\n";
            cin.ignore();
        }
        cout << endl;
        cin.ignore();

    } while (choice != 4);
}

int main()
{
    ParkingLot parkingLot("parking_lot.txt");
    parkingLot.searchRecord();
    return 0;
}