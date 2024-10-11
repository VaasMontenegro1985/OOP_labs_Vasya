#include <gtest/gtest.h> 
#include <stdexcept> 
#include "../include/point.h"
#include "../include/figure.h"
#include "../include/rhombus.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}