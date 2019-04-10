#include "Car.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    CCar car;

    std::string command;
    while (command != "Exit")
    {
        std::cin >> command;

        if (command == "Info")
        {
            std::string direction = car.GetDirection();
            std::cout << "Направление: " << direction << std::endl;
            std::cout << "Скорость: " << car.GetSpeed() << std::endl;
            std::cout << "Передача: " << car.GetGear() << std::endl;

            if (car.IsEngineOn())
            {
                std::cout << "Двигатель: включен" << std::endl;
            }
            else
            {
                std::cout << "Двигатель: выключен" << std::endl;
            }
        }
        if (command == "EngineOn")
        {
            car.TurnOnEngine();
            if (car.IsEngineOn())
            {
                std::cout << "Двигатель включен." << std::endl;
            }
            else
            {
                std::cout << "Не удалось включить двигатель." << std::endl;
            }
        }
        if (command == "EngineOff")
        {
            car.TurnOffEngine();
            if (!car.IsEngineOn())
            {
                std::cout << "Двигатель выключен." << std::endl;
            }
            else
            {
                std::cout << "Не удалось выключить двигатель." << std::endl;
            }
        }
        if (command == "SetGear")
        {
            std::string gear;
            std::cin >> gear;

            if (car.SetGear(std::stoi(gear)))
            {
                std::cout << "Текущая передача: " << gear << std::endl;
            }
            else
            {
                std::cout << "Не удалось переключиться на передачу: " << gear << std::endl;
            }
        }
        if (command == "SetSpeed")
        {
            std::string speed;
            std::cin >> speed;

            if (car.SetSpeed(std::stoi(speed)))
            {
                std::cout << "Текущая скорость: " << speed << std::endl;
            }
            else
            {
                std::cout << "Не удалось изменить скорость на: " << speed << std::endl;
            }
        }
    }

    return 0;
}
