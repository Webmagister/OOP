#include "Car.hpp"

bool IsSpeedInRange(int expectedGear, int minSpeed, int maxSpeed, int speed, int gear)
{
    return ((maxSpeed >= speed) && (minSpeed <= speed)) && (gear == expectedGear);
}

bool IsSpeedInGear(int gear, int speed)
{
    return IsSpeedInRange(-1, 0, 20, speed, gear) ||
           IsSpeedInRange(0, -20, 150, speed, gear) ||
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
    if (!m_engineOnTurn && gear != 0)
    {
        return false;
    }
    if (gear == m_currGear)
    {
        return true;
    }
    if (gear == -1 && m_currSpeed != 0)
    {
        return false;
    }
    if (gear == 1 && m_direction == Direction::reverse && m_currSpeed != 0)
    {
        return false;
    }

    if (!IsSpeedInGear(gear, m_currSpeed))
    {
        return false;
    }

    m_currGear = gear;

    SetDirection();

    return true;
}

bool CCar::SetSpeed(int speed)
{
    if (m_currGear == 0 && speed > m_currSpeed)
    {
        return false;
    }
    if (m_engineOnTurn && IsSpeedInGear(m_currGear, speed))
    {
        m_currSpeed = speed;

        SetDirection();
        return true;
    }

    return false;
}

int CCar::GetSpeed() const
{
    return m_currSpeed;
}

int CCar::GetGear() const
{
    return m_currGear;
}

bool CCar::IsEngineOn() const
{
    return m_engineOnTurn;
}

void CCar::SetDirection()
{
    if (m_currGear == -1 && m_currSpeed != 0)
    {
        m_direction = Direction::reverse;

        return;
    }

    if (m_currGear == 0 && m_direction == Direction::reverse && m_currSpeed != 0)
    {
        m_direction = Direction::reverse;

        return;
    }

    if (m_currSpeed == 0)
    {
        m_direction = Direction::stand;

        return;
    }

    m_direction = Direction::forward;
}

std::string CCar::GetDirection() const
{
    switch (m_direction)
    {
        case Direction::stand:
            return "stand";
        case Direction::reverse:
            return "reverse";
        case Direction::forward:
            return "forward";
        default:
            return "";
    }
}
