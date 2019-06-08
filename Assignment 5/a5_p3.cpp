/*
CH08-320143
a5_p3.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
using namespace std;

class Motor {
    public:
        Motor() {
            throw "This motor has problems";
        }
        ~Motor() {}
};

class Car {
    private:
        Motor *motor = nullptr;
    public:
        Car() {
            try {
                motor = new Motor();
            }
            catch(const char * e) {
                cerr << e << endl;
                throw "The car in this garage has problems with the motor";
            }
        }
        ~Car() {}
};

class Garage {
    private:
        Car *car = nullptr;
    public:
        Garage() {
            try {
                car = new Car();
            }
            catch (const char *e) {
                throw e;
            }
        }
        ~Garage() {}
        void dummy() {
            cout << "Program is good" << endl;
        }
};

int main() {
    Garage *garage = nullptr;

    try {
        garage = new Garage();
    }
    catch(const char* e) {
        cerr << e << endl;
        return 1;
    }
    garage->dummy(); // will not be executed
    return 0;
}