#pragma once

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

    Direction GetDirection() const;

private:
    int m_currGear = 0;
    int m_currSpeed = 0;
    bool m_engineOnTurn = false;
};