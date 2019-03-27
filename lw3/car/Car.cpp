#include <iostream>
#include "Car.hpp"

bool IsSpeedInRange(int expectedGear, int minSpeed, int maxSpeed, int speed, int gear)
{
    return ((maxSpeed >= speed) && (minSpeed <= speed)) && (gear == expectedGear);
}

bool IsSpeedInGear(int gear, int speed)
{
    return IsSpeedInRange(-1, 0, 20, speed, gear) ||
           IsSpeedInRange(1, 0, 30, speed, gear) ||
           IsSpeedInRange(2, 20, 50, speed, gear) ||
           IsSpeedInRange(3, 30, 60, speed, gear) ||
           IsSpeedInRange(4, 40, 90, speed, gear) ||
           IsSpeedInRange(5, 50, 150, speed, gear);
}

bool CCar::TurnOnEngine()
{
    if (!m_engineOnTurn)
    {
        m_engineOnTurn = true;
        return true;
    }

    return false;
}

bool CCar::TurnOffEngine()
{
    if ((m_engineOnTurn) && (m_currSpeed == 0) && (m_currGear == 0))
    {
        m_engineOnTurn = false;
        return true;
    }

    return false;
}

bool CCar::SetGear(int gear)
{
    if (gear == m_currGear)
    {
        return true;
    }
    if (m_engineOnTurn)
    {
        if (gear == 0)
        {
            m_currGear = 0;
            return true;
        }
        else if (gear == -1)
        {
            if ((m_currGear == 0 || m_currGear == 1) && (m_currSpeed == 0))
            {
                m_currGear = -1;
                return true;
            }
        }
        else if (IsSpeedInGear(gear, m_currSpeed))
        {
            m_currGear = gear;
            return true;
        }
    }

    return false;
}

bool CCar::SetSpeed(int speed)
{
    if (m_engineOnTurn && (IsSpeedInGear(m_currGear, speed) || (m_currGear == 0 && abs(m_currSpeed) >= speed)))
    {
        if (m_currGear == -1)
        {
            speed = -speed;
        }
        m_currSpeed = speed;

        return true;
    }

    return false;
}

int CCar::GetSpeed() const
{
    return std::abs(m_currSpeed);
}

int CCar::GetGear() const
{
    return m_currGear;
}

bool CCar::IsEngineOn() const
{
    return m_engineOnTurn;
}

Direction CCar::GetDirection() const
{
    if (m_currSpeed > 0)
    {
        return Direction::forward;
    }
    if (m_currSpeed < 0)
    {
        return Direction::reverse;
    }

    return Direction::stand;
}