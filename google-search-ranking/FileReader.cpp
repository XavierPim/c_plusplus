#include <vector>
#include <ostream>
#include <sstream>
#include "FileReader.hpp"

using namespace std;

vector<double> FileReader::parseFile()
    {
        vector<double> parsedVec;
        string line;

        try
        {
            while (getline(infile, line))
            {
                istringstream iss(line);
                double value;

                while(iss >> value)
                {
                    if(value == ZERO || value == ONE)
                    {
                        parsedVec.push_back(value);
                    }
                    else
                    {
                        throw invalid_argument("Invalid Matrix value!");
                    }
                }
            }
        }
        catch(const invalid_argument& e)
        {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }


        return parsedVec;
}
