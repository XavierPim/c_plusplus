#include <cstdio>
#include <vector>
#include <iosfwd>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem> // C++17 and later

#pragma once

using namespace std;

class FileReader
{
public:
    const int ZERO = 0;
    const int ONE  = 1;

    FileReader() : infile("connectivity.txt")
    {
        // Debug: Print current working directory
        cout << "Current working directory: " << filesystem::current_path() << endl;

        // Debug: Check if file exists
        ifstream file_check("connectivity.txt");
        if (!file_check)
        {
            cerr << "Error: 'connectivity.txt' does not exist in the current working directory." << endl;
            exit(EXIT_FAILURE);
        }

        try
        {
            if (!infile.is_open())
            {
                throw ifstream::failure("Error: Failed to open 'connectivity.txt'");
            }
        }
        catch(const std::ifstream::failure& e)
        {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    vector<double> parseFile();

private:
    ifstream infile;
};
