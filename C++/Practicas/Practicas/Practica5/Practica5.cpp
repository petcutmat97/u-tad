// Practica5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>

using namespace std;

//Fichero en carpeta Debug

template <typename T>
void OpenFile(T & _file, const char* _filename, const char* _mode) {

    if (_mode == "r") {
        _file.open(_filename, std::ios_base::in);
    }
    else if (_mode == "w") {
        _file.open(_filename, std::ios_base::out);
    }
    else {
        printf("Modo incorrecto, introducir r o w");
    }
}

template <typename T>
void CloseFile(T & _file) {
    _file.close();
}

void ReadFile(ifstream & _file) {
    
    string line;
    
    if (_file.is_open())
    {
        while (getline(_file, line))
        {
            cout << line << '\n';
        }
        _file.close();
    }

    else printf("No se pudo abrir el archivo");

}

void WriteFile(ofstream & _file, string _s) {
    if (_file.is_open())
    {
        _file << _s << "\n";
        _file.close();
    }
    else printf("No se pudo abrir el archivo");
}

int main()
{
    ifstream inmainFile;
    OpenFile(inmainFile,"fichero.txt","r");
    ReadFile(inmainFile);
    CloseFile(inmainFile);

    ofstream ofmainFile;
    OpenFile(ofmainFile, "fichero.txt", "w");
    WriteFile(ofmainFile, "hola2");
    CloseFile(ofmainFile);
    
    OpenFile(inmainFile, "fichero.txt", "r");
    ReadFile(inmainFile);
    CloseFile(inmainFile);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
