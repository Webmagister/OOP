#pragma once

#include <string>

enum class Direction
{
    reverse,
    stand,
    forward
};

class CCar
{
public:
    CCar() = default;

    ~CCar() = default;

    bool SetGear(int gear);

    int GetGear() const;

    bool SetSpeed(int speed);

    int GetSpeed() const;

    bool TurnOnEngine();

    bool TurnOffEngine();

    bool IsEngineOn() const;

    void SetDirection();

    std::string GetDirection() const;

private:
    int m_currGear = 0;
    int m_currSpeed = 0;
    Direction m_direction = Direction::stand;
    bool m_engineOnTurn = false;
};