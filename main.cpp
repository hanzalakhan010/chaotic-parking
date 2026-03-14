#include <iostream>
using namespace std;

struct Parking{
    int parking_slot_number;
    int parking_duration;
    float parking_fee;
};

struct Student{
    int student_id;
    char student_name[50];
    char vehicle_number[20];
    Parking parking;
};

float calculateFee(int duration){
    if(duration <= 2)
        return 0;
    else
        return (duration - 2) * 50;
}

void display(Student *s){
    cout << "\nStudent ID: " << s->student_id;
    cout << "\nName: " << s->student_name;
    cout << "\nVehicle: " << s->vehicle_number;
    cout << "\nParking Slot: " << s->parking.parking_slot_number;
    cout << "\nParking Duration: " << s->parking.parking_duration;
    cout << "\nParking Fee: Rs " << s->parking.parking_fee;
    cout << "\n---------------------------";
}

int main(){

    int no_of_students;

    cout << "WELCOME TO PARKING MANAGEMENT SYSTEM\n";

    cout << "Enter number of students: ";
    cin >> no_of_students;

    Student students[100];   // simple fixed array

    for(int i = 0; i < no_of_students; i++){

        students[i].student_id = i + 1;

        cout << "\nEnter Student Name: ";
        cin >> students[i].student_name;

        cout << "Enter Vehicle Number: ";
        cin >> students[i].vehicle_number;

        cout << "Enter Parking Slot Number: ";
        cin >> students[i].parking.parking_slot_number;

        cout << "Enter Parking Duration (hours): ";
        cin >> students[i].parking.parking_duration;

        students[i].parking.parking_fee =
            calculateFee(students[i].parking.parking_duration);
    }

    cout << "\n\n---- Parking Records ----\n";

    for(int i = 0; i < no_of_students; i++){
        display(&students[i]);
    }

}
