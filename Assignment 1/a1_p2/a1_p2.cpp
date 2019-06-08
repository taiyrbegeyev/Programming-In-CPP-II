/*
CH08-320143
a2_1.cpp
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    // open file in binary mode to append in it
    ofstream concat;
    concat.open("concatn.txt", ios::binary | ios::in);
    if (!concat.is_open()) {
        cerr << "Something went wrong. File has not been found" << endl;
        exit(1);
    }

    int n;
    cin >> n;

    string nameOfFile[n];
    for (int i = 0; i < n; i++) {
        // read file name
        cin >> nameOfFile[i];
    }

    for (int i = 0; i < n; i++) {
        // open a file for reading
        ifstream temp;
        temp.open(nameOfFile[i], ios::binary | ios::out);
        if (!temp.is_open()) {
            cerr << "Something went wrong. File has not been found" << endl;
            exit(2);
        }

        // reading files using read and write for the binary mode
        char *memblock; 
        int end;

        // move to the end and get the size of the file
        temp.seekg(0, ios::end);
        end = temp.tellg();

        // the address of an array of bytes where the read data
        // elements are stored or from where the data elements to be written are taken. 
        memblock = new char[end + 1];

        // move to the beginning and read the whole file
        temp.seekg(0, ios::beg);
        temp.read(memblock, end);

        memblock[end] = '\n';

        // append the data to the "concatn.txt"
        concat.write(memblock, end + 1);

        // deallocate and close 
        delete[] memblock;
        temp.close();
    }
    concat.close();
    return 0;
}