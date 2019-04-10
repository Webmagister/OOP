include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CAR Car.cpp Car.hpp)
set(SOURCES main.cpp Car.cpp Car.hpp)
set(TEST_SOURCES сar.test.cpp ${CAR})

add_executable(car ${SOURCES})
add_executable(car.test ${TEST_SOURCES})

target_link_libraries(car.test gtest gtest_main)
add_test( NAME car.test COMMAND car.test )
