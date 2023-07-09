#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Car {
    string driverName;
    string carName;
    string carId;
    int timeStay;
};

class ParkingLot {
private:
    vector<Car> parkedCars;
    string fileName;

public:
    ParkingLot(const string& filename);
    void parkCar();
    void displayCarDetails();
    void removeCar();
    void saveToFile();
};

ParkingLot::ParkingLot(const string& filename) : fileName(filename) {}

void ParkingLot::parkCar() 
{
    system("cls");
    Car newCar;
    cout << "Enter driver name: ";
    cin.ignore();
    getline(cin, newCar.driverName);
    cout << "Enter car name: ";
    getline(cin, newCar.carName);
    cout << "Enter car ID: ";
    getline(cin, newCar.carId);
    cout << "Enter time of stay (in hours): ";
    cin >> newCar.timeStay;
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

    /*
    This function returns an iterator to the first element in the range [first, last) for which pred(Unary Function) returns true. 
    If no such element is found, the function returns last
    */
    // auto it = find_if(parkedCars.begin(), parkedCars.end(), [&](const Car& car) {
    //     return car.carId == carId;
    // });

    vector<Car>::iterator it = parkedCars.begin();
    while(it != parkedCars.end())
    {
        if(it -> carId == carId) break;
        it++;
    }

    if (it != parkedCars.end()) 
    {
        cout << "Car Details:" << endl;
        cout << "Driver Name: " << it->driverName << endl;
        cout << "Car Name: " << it->carName << endl;
        cout << "Car ID: " << it->carId << endl;
        cout << "Time of Stay: " << it->timeStay << " hours" << endl;
        cout << "Fee: " << it->timeStay * 80 << ".000 (VND)" << endl;
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

    // auto it = find_if(parkedCars.begin(), parkedCars.end(), [&](const Car& car) {
    //     return car.carId == carId;
    // });
    
    vector<Car>::iterator it = parkedCars.begin();
    while(it != parkedCars.end())
    {
        if(it -> carId == carId) break;
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

    for (const auto& car : parkedCars) 
    {
        outputFile << "Driver Name: " << car.driverName << endl;
        outputFile << "Car Name: " << car.carName << endl;
        outputFile << "Car ID: " << car.carId << endl;
        outputFile << "Time of Stay: " << car.timeStay << " hours" << endl;
        outputFile << "----------------------" << endl;
    }

    outputFile.close();
    cout << "Data saved to file!" << endl;
}

int main() 
{
    ParkingLot parkingLot("parking_lot.txt");
    int choice;
    do {
        system("cls");
        cout << "Car Parking Management System" << endl;
        cout << "1. Park a Car" << endl;
        cout << "2. Display Car Details" << endl;
        cout << "3. Remove a Car" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                parkingLot.parkCar();
                break;
            case 2:
                parkingLot.displayCarDetails();
                break;
            case 3:
                parkingLot.removeCar();
                break;
            case 4:
                system("cls");
                cout << "SEE YOU AGAIN..." << endl;
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("pause");

    }while (choice != 4);
    return 0;
}
