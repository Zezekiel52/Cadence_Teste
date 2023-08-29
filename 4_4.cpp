#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> StringVector;

void myMethod(StringVector& input, StringVector& output)
{
    StringVector::iterator first = std::find(input.begin(), input.end(), "Fabiano");
    StringVector::iterator last = std::find(input.begin(), input.end(), "Vector");

    if (first != input.end() && last != input.end())
    {
        *last = "Victor";

        for (StringVector::iterator it = first; it != last; ++it)
        {
            std::cout << *it << std::endl;
        }

        input.insert(last, "XXX");

        for (const std::string& str : input)
        {
            output.push_back(str);
        }
    }
    else
    {
        std::cout << "Strings not found in input." << std::endl;
    }
}

int main()
{
    StringVector input = {"Hello", "Fabiano", "World", "Vector", "Test"};
    StringVector output;

    myMethod(input, output);

    std::cout << "Output:" << std::endl;
    for (const std::string& str : output)
    {
        std::cout << str << std::endl;
    }

    return 0;
}
