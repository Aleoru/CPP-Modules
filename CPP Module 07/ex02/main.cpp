#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {

		std::cout << "\033[33;1m[    My own test    ]\033[0m" << std::endl;
        Array<std::string> array(MAX_VAL);
        array[0] = "Hello World!";
        array[1] = "42 is cool";
        array[2] = "Some random string";
        Array<std::string> something(array);

        std::cout << "array:" << std::endl;
        std::cout << array[0] << std::endl;
        std::cout << array[1] << std::endl;
        std::cout << array[2] << std::endl;
        std::cout << std::endl;
        std::cout << "something:" << std::endl;
        std::cout << something[0] << std::endl;
        std::cout << something[1] << std::endl;
        std::cout << something[2] << std::endl;
        std::cout << std::endl;
		std::cout << "\033[33;1m[    Subject test    ]\033[0m" << std::endl;

    }
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }
    return 0;
}