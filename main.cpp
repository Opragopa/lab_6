#include<iostream>
#include <string>
#include <fstream>
#include "isReal.h"


//числа, например: 1.324876E+2 и 46542E-10 должны вывести "ДА"

int main()
{
    setlocale(LC_ALL, "Rus");
    const std::string PATH = "input.txt";
    int count = 1;
    while (true)
    {
        try
        {
            std::string str = openNewString(PATH);
            std::cout << count << ") ";
            std::cout << str << '\n';
            if (isFloatingPoint(str) || isMantissa2(str))
            {
                std::cout << "ДА\n";
            }
            else
            {
                std::cout << "НЕТ\n";
            }
        }
        catch (StrException& err)
        {
            std::cout << err.getError() << std::endl << std::endl;
            break;
        }
        count++;
    }

    std::string test = "E+3";
    int e = test.find('E', 0);
    std::cout << "test.length() = " << test.length() << " Символов после E = " << (test.length() - (e + 1));
    return 0;
}