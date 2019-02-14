/*
    Разработайте программу replace.exe, выполняющую замену всех вхождений подстроки
    в текстовом файле на другую строку, и записывающей результат в выходной файл
    (отличный от входного). Формат командной строки:
    replace.exe <input file> <output file> <search string> <replace string>

    Атайкин Павел, ПС-21
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceAllSubstring(std::string &str, const std::string &needle, const std::string &replace)
{
    size_t startPosition = 0;
    while ((startPosition = str.find(needle, startPosition)) != std::string::npos)
    {
        str.replace(startPosition, needle.length(), replace);
        startPosition += replace.length();
    }
}

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        std::cout << "There are not enough arg." << std::endl;
        return 1;
    }

    if (static_cast<std::string>(argv[1]) == static_cast<std::string>(argv[2]))
    {
        std::cout << "Files is equal." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cout << "File does not open." << std::endl;
        return 1;
    }

    const std::string needle = static_cast<std::string>(argv[3]);
    const std::string replace = static_cast<std::string>(argv[4]);

    while (!inputFile.eof())
    {
        std::string str;
        std::getline(inputFile, str);

        replaceAllSubstring(str, needle, replace);

        outputFile << str << std::endl;
    }

    return 0;
}
