// Practica6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

template <typename T>
void OpenFile(T& _file, const char* _filename, const char* _mode) {

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
void CloseFile(T& _file) {
    _file.close();
}

void CountWordOcurrence(string _word, ifstream & _file) {
    string str;
    int count = 0;

    if (_file.fail()) {
        cout << "Error al abrir el archivo" << endl;
    }
    else {
        while (_file >> str)
        {
            if (str == _word)
                count++;
        }
        printf("\nLa palabra '%s' se repite %d veces", _word.c_str(), count);
    }
}

void SumAllNumbers(ifstream& _file) {
    int sum = 0;

    if (_file.fail()) {
        cout << "Error al abrir el archivo" << endl;
    }
    else {
        //conversion ifstream a stringstream
        std::streampos p = _file.tellg();
        stringstream ss;
        ss << _file.rdbuf();
        _file.seekg(p);


        while (ss.good()) {

            string substr;
            getline(ss, substr, ','); //separa por comas

            int subsum = 0;

            for (int i = 0; i < substr.length(); i++) { //si es mas de un char suma sus digitos
                int power = substr.length() - 1 - i;
                printf("\n");
                if (isdigit(substr[i])) { //es un n�mero?
                    int digit = substr[i] - '0';
                    subsum += (digit * pow(10, power));
                }
            }
            sum += subsum;

        }
        printf("\nLa suma de todos los numeros separados por coma es: ");
        printf("%d", sum);
        printf("\n");
    }
}


int main()
{
    //numero de apariciones de una cadena en un fichero
    ifstream inmainFile;
    OpenFile(inmainFile, "fichero1.txt", "r");
    string word = "hola";
    CountWordOcurrence(word, inmainFile);
    CloseFile(inmainFile);
    
    //suma de numeros enteros separados por coma en un fichero
    OpenFile(inmainFile, "fichero2.txt", "r");
    SumAllNumbers(inmainFile);
    CloseFile(inmainFile);

    return 0;
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
