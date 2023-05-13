#include "Lab2.h"
#include <iomanip>

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        using namespace std;
        int number;
        string trash;


        out << setw(12) << right << "oct"
            << setw(11) << "dec"
            << setw(9)  << "hex" << "\n";

        out << setw(13) << setfill('-') << right << '.'
            << setw(11) << '.'
            << setw(9)  << "\n";


        while (!in.eof()) 
        {
            in >> number;

            if (in.fail()) 
            {
                in.clear();
                in >> trash;
            }
            else 
            {
                out << setfill(' ') << uppercase
                    << oct << setw(12) << right << number;
                out << dec << setw(11) << number;
                out << hex << setw(9)  << number << "\n";
            }
        }
        in.ignore(LONG_MAX);
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        using namespace std;

        float number;
        float max = FLT_MIN;
        string trash;

        out << "printmaxfloat";
        while (!in.eof())
        {
            in >> number;

            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << setw(5) << ' ' << setw(15) << internal 
                    << showpos << setprecision(3) << number << "\n";

                if (max < number)
                {
                    max = number;
                }
            }
        }
        out << setw(5) << "max:" << setw(15) << internal
            << fixed << showpos << setprecision(3) << max << "\n";
    }
}