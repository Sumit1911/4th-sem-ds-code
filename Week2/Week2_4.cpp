#include<iostream>
using namespace std;

struct Car {
    int car_ID;
    string make;
    string model;
    string year;
    double rental_price_per_day;
    int from_date;
    int to_date;
};

const int MAX_CARS = 100; // Maximum number of cars
Car cars[MAX_CARS]; // Array to store cars
int numCars = 0; // Variable to keep track of the number of cars

void addRentalCarData() {
    if (numCars >= MAX_CARS) {
        cout << "Maximum number of cars reached." << endl;
        return;
    }
    Car& C = cars[numCars++];
    cout<<"Enter Id, make, model, year, rentalPrice, fromDate, toDate"<<endl;
    cin>>C.car_ID>>C.make>>C.model>>C.year>>C.rental_price_per_day>>C.from_date>>C.to_date;
}

void rentalCost() {
    int noOfDays = (cars->to_date)-(cars->from_date);
    double totalRentalPrice = cars->rental_price_per_day*noOfDays;
    cout<<"Total Rental Price : "<<totalRentalPrice<<endl;
}

int main() {
    while (true) {
        cout<<"1. Add Car Details"<<endl<<"2. Check Rental Price"<<endl<<"3. Exit"<<endl;
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
                addRentalCarData();
                break;
            case 2:
                // {
                //     int carNo;
                //     cout<<"Enter Car No. (0-99) : ";
                //     cin>>carNo;
                //     rentalCost(carNo);
                // }
                rentalCost();
                break;
            case 3:
                return 0;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}