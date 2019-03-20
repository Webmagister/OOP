/*
    Разработайте программу replace.exe, выполняющую замену всех вхождений подстроки
    в текстовом файле на другую строку, и записывающей результат в выходной файл
    (отличный от входного). Формат командной строки:
    replace.exe <input file> <output file> <search string> <replace string>

    Атайкин Павел, ПС-21
*/

#include <iostream>
#include <fstream>
#include <string>

struct InputParams
{
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string needle;
    std::string replace;
};

void ReplaceAllSubstring(std::string &str, const std::string &needle, const std::string &replace)
{
    size_t startPosition = 0;
    size_t replaceLength = replace.length();

    while ((startPosition = str.find(needle, startPosition)) != std::string::npos)
    {
        str.replace(startPosition, needle.length(), replace);
        startPosition += replaceLength;
    }
}

bool GetInputParams(InputParams &inputParams, int argc, char *argv[])
{
    if (argc < 5)
    {
        std::cout << "There are not enough arg." << std::endl;
        return false;
    }

    if (static_cast<std::string>(argv[1]) == static_cast<std::string>(argv[2]))
    {
        std::cout << "Files is equal." << std::endl;
        return false;
    }

    inputParams.inputFile.open(argv[1]);
    inputParams.outputFile.open(argv[2]);

    if (!inputParams.inputFile.is_open() || !inputParams.outputFile.is_open())
    {
        std::cout << "File does not open." << std::endl;
        return false;
    }


    inputParams.needle = argv[3];
    inputParams.replace = argv[4];

    return true;
}

void ProcessFile(InputParams &inputParams)
{
    std::string str;

    while (std::getline(inputParams.inputFile, str))
    {
        if (!inputParams.needle.empty())
        {
            ReplaceAllSubstring(str, inputParams.needle, inputParams.replace);
        }

        inputParams.outputFile << str << std::endl;
    }
}

int main(int argc, char *argv[])
{
    InputParams inputParams;

    if (!GetInputParams(inputParams, argc, argv))
    {
        return 1;
    }

    ProcessFile(inputParams);

    return 0;
}
