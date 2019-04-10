#include "Car.hpp"
#include "gtest/gtest.h"

TEST(CarEngineTest, EngineTest)
{
    CCar testCar;

    ASSERT_TRUE(testCar.TurnOnEngine());
    ASSERT_TRUE(testCar.TurnOffEngine());

    testCar.TurnOnEngine();

    testCar.SetGear(1);
    testCar.SetSpeed(15);
    ASSERT_FALSE(testCar.TurnOffEngine());

    testCar.SetGear(0);
    ASSERT_FALSE(testCar.TurnOffEngine());

    testCar.SetSpeed(0);
    ASSERT_TRUE(testCar.TurnOffEngine());
}

TEST(CarGearTest, GetGearTest)
{
    CCar testCar;

    ASSERT_EQ(testCar.GetGear(), 0);

    testCar.TurnOnEngine();
    testCar.SetGear(-1);
    ASSERT_EQ(testCar.GetGear(), -1);

    testCar.SetSpeed(10);
    ASSERT_EQ(testCar.GetGear(), -1);

    testCar.SetSpeed(0);
    testCar.SetGear(0);
    ASSERT_EQ(testCar.GetGear(), 0);

    testCar.SetGear(1);
    ASSERT_EQ(testCar.GetGear(), 1);
}


TEST(CarGearTest, SetGearTest)
{
    CCar testCar;

    ASSERT_FALSE(testCar.SetGear(-1));
    ASSERT_TRUE(testCar.SetGear(0));
    ASSERT_TRUE(testCar.TurnOnEngine());

    ASSERT_TRUE(testCar.SetGear(-1));

    testCar.SetSpeed(1);
    ASSERT_FALSE(testCar.SetGear(1));
    testCar.SetSpeed(0);
    ASSERT_TRUE(testCar.SetGear(1));

    ASSERT_TRUE(testCar.SetGear(-1));
    testCar.SetSpeed(1);
    ASSERT_TRUE(testCar.SetGear(0));
    ASSERT_FALSE(testCar.SetGear(1));
    testCar.SetSpeed(0);
    ASSERT_TRUE(testCar.SetGear(1));

    ASSERT_FALSE(testCar.SetGear(2));
    testCar.SetSpeed(21);
    ASSERT_TRUE(testCar.SetGear(2));

    ASSERT_FALSE(testCar.SetGear(3));
    testCar.SetSpeed(31);
    ASSERT_TRUE(testCar.SetGear(3));

    ASSERT_FALSE(testCar.SetGear(4));
    testCar.SetSpeed(41);
    ASSERT_TRUE(testCar.SetGear(4));

    ASSERT_FALSE(testCar.SetGear(5));
    testCar.SetSpeed(51);
    ASSERT_TRUE(testCar.SetGear(5));

    testCar.SetSpeed(91);

    ASSERT_FALSE(testCar.SetGear(4));
    testCar.SetSpeed(61);
    ASSERT_TRUE(testCar.SetGear(4));

    ASSERT_FALSE(testCar.SetGear(3));
    testCar.SetSpeed(51);
    ASSERT_TRUE(testCar.SetGear(3));

    ASSERT_FALSE(testCar.SetGear(2));
    testCar.SetSpeed(31);
    ASSERT_TRUE(testCar.SetGear(2));

    ASSERT_FALSE(testCar.SetGear(1));
    testCar.SetSpeed(21);
    ASSERT_TRUE(testCar.SetGear(1));

    ASSERT_TRUE(testCar.SetGear(0));

    ASSERT_FALSE(testCar.SetGear(-1));
    testCar.SetSpeed(0);
    ASSERT_TRUE(testCar.SetGear(-1));
}

TEST(CarSpeedTest, SetSpeedTest)
{
    CCar testCar;

    ASSERT_FALSE(testCar.SetSpeed(0));

    ASSERT_TRUE(testCar.TurnOnEngine());

    ASSERT_FALSE(testCar.SetSpeed(10));

    testCar.SetGear(-1);
    ASSERT_FALSE(testCar.SetSpeed(21));
    ASSERT_TRUE(testCar.SetSpeed(1));

    testCar.SetGear(0);
    ASSERT_FALSE(testCar.SetSpeed(2));
    ASSERT_TRUE(testCar.SetSpeed(0));
    ASSERT_FALSE(testCar.SetSpeed(151));

    testCar.SetGear(1);
    ASSERT_FALSE(testCar.SetSpeed(31));
    ASSERT_TRUE(testCar.SetSpeed(21));

    testCar.SetGear(2);
    ASSERT_FALSE(testCar.SetSpeed(51));
    ASSERT_FALSE(testCar.SetSpeed(19));
    ASSERT_TRUE(testCar.SetSpeed(35));

    testCar.SetGear(3);
    ASSERT_FALSE(testCar.SetSpeed(61));
    ASSERT_FALSE(testCar.SetSpeed(29));
    ASSERT_TRUE(testCar.SetSpeed(45));

    testCar.SetGear(4);
    ASSERT_FALSE(testCar.SetSpeed(91));
    ASSERT_FALSE(testCar.SetSpeed(39));
    ASSERT_TRUE(testCar.SetSpeed(55));

    testCar.SetGear(5);
    ASSERT_FALSE(testCar.SetSpeed(151));
    ASSERT_FALSE(testCar.SetSpeed(39));
    ASSERT_TRUE(testCar.SetSpeed(90));

    ASSERT_TRUE(testCar.SetSpeed(testCar.GetSpeed()));
}

TEST(CarSpeedTest, GetSpeedTest)
{
    CCar testCar;

    ASSERT_EQ(testCar.GetSpeed(), 0);

    testCar.TurnOnEngine();
    testCar.SetGear(1);
    testCar.SetSpeed(15);
    ASSERT_EQ(testCar.GetSpeed(), 15);

    testCar.SetSpeed(10);
    ASSERT_EQ(testCar.GetSpeed(), 10);
}

TEST(CarDirectionTest, DirectionTest)
{
    CCar testCar;

    ASSERT_EQ(testCar.GetDirection(), "stand");

    testCar.TurnOnEngine();
    testCar.SetGear(-1);
    ASSERT_EQ(testCar.GetDirection(), "stand");

    testCar.SetSpeed(10);
    ASSERT_EQ(testCar.GetDirection(), "reverse");

    testCar.SetGear(0);
    ASSERT_EQ(testCar.GetDirection(), "reverse");

    testCar.SetSpeed(0);
    ASSERT_EQ(testCar.GetDirection(), "stand");

    testCar.SetGear(1);
    testCar.SetSpeed(10);
    ASSERT_EQ(testCar.GetDirection(), "forward");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}