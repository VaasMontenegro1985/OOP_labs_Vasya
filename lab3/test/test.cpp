#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/point.h"
#include "../include/figure.h"
#include "../include/rhombus.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"

TEST(UtilsTest, testeqDouble)
{
    double a = 3.0;
    double b = 2.0;
    double c = 5.0;
    bool result = Utils::eqDouble(a + b, c);
    ASSERT_TRUE(result == true);
}

TEST(UtilsTest, testSTriangle)
{
    double a = 3.0;
    double b = 4.0;
    double c = 5.0;
    double s = 6.0;
    bool result = Utils::eqDouble(s, Utils::STriangle(a, b, c));
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testConctructor)
{
    Point a = Point();
    Point b(0.0, 0.0);
    bool result = (a == b);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testSummarize)
{
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c = a + b;
    Point d(2.0, 3.0);
    bool result = (c == d);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testSubstraction)
{
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c(2.0, 3.0);
    Point d = c - b;
    bool result = (a == d);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testProductNumber)
{
    Point a(1.0, 3.0);
    Point b = a * 3;
    Point c(3.0, 9.0);
    bool result = (b == c);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testPosAbs) {
    Point p1(3, 4);
    bool result = Utils::eqDouble(p1.abs(), 5.0);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testNegAbs) {
    Point p1(-3, -4);
    bool result = Utils::eqDouble(p1.abs(), 5.0);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testZerosAbs) {
    Point p1(0.0, 0.0);
    bool result = Utils::eqDouble(p1.abs(), 0.0);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testOperatorEqual) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    bool result = (p1 == p2);
    ASSERT_TRUE(result == true);
}

TEST(PointTest, testCopy) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3 = p1;
    bool result = (p1 == p3);
    ASSERT_TRUE(result == true);
}

TEST(TrapezoidTest, ConstructorTrapezoid) {
    Trapezoid trapezoid = Trapezoid();
    Point a(0.0, 0.0), b(1.0, 1.0), c(2.0, 1.0), d(3.0, 0.0);
    Trapezoid t(a, b, c, d);
    bool result = (trapezoid == t);
    ASSERT_TRUE(result == true);
}

TEST(TrapezoidTest, InvalidTrapezoid) {
    Point a(0.0, 0.0), b(1.0, 1.0), c(2.0, 0.0), d(3.0, 3.0);
    EXPECT_THROW({
        Trapezoid t(a, b, c, d);
    }, std::invalid_argument);
}

TEST(TrapezoidTest, ValidTrapezoid) {
    Point a(0.0, 0.0), b(4.0, 0.0), c(3.0, 2.0), d(1.0, 2.0);
    EXPECT_NO_THROW({
        Trapezoid t(a, b, c, d);
    });
}

TEST(TrapezoidTest, ConstructorAndArea) {
    Point a(0.0, 0.0), b(4.0, 0.0), c(3.0, 2.0), d(1.0, 2.0);
    Trapezoid trapezoid(a, b, c, d);
    bool result = Utils::eqDouble((double)(trapezoid), 6.0);
    ASSERT_TRUE(result == true);
}

TEST(TrapezoidTest, validCenter) {
    Point a(0.0), b(4.0, 0.0), c(3.0, 2.0), d(1.0, 2.0);
    Trapezoid trapezoid(a, b, c, d);
    Point realCenter(2.0, 1.0);
    Point center = trapezoid.calcCentrRotation();
    bool result = (center == realCenter);
    ASSERT_TRUE(result == true);
}

TEST(TrapezoidTest, EqualTrapezoid) {
    Point a(3.0, 0.0), b(4.0, 1.0), c(5.0, 1.0), d(6.0, 0.0);
    Trapezoid trapezoid1(a, b, c, d);
    Point e(3.0, 1.0), f(4.0, 2.0), g(5.0, 2.0), h(6.0, 1.0);
    Trapezoid trapezoid2(e, f, g, h);
    bool result = (trapezoid1 == trapezoid2);
    ASSERT_TRUE(result == true);
}

TEST(TrapezoidTest, EqualTrapezoid1) {
    Point a(3.0, 0.0), b(4.0, 1.0), c(5.0, 1.0), d(6.0, 0.0);
    Trapezoid trapezoid1(a, b, c, d);
    Point e(3.0, 2.0), f(4.0, 1.0), g(5.0, 1.0), h(6.0, 2.0);
    Trapezoid trapezoid2(e, f, g, h);
    bool result = (trapezoid1 == trapezoid2);
    ASSERT_TRUE(result == true);
}

TEST(RectangleTest, ConstructorRectangle) {
    Rectangle rectangle = Rectangle();
    Point a(0.0, 0.0), b(1.0, 0.0), c(1.0, 1.0);
    Rectangle r(a, b, c);
    bool result = (rectangle == r);
    ASSERT_TRUE(result == true);
}

TEST(RectangleTest, InvalidRectangle) {
    Point a(0.0, 0.0), b(1.0, 1.0), c(-2.0, 0.0);
    EXPECT_THROW({
        Rectangle r(a, b, c);
    }, std::invalid_argument);
}

TEST(RectangleTest, ValidRectangle) {
    Point a(0.0, 0.0), b(1.0, 1.0), c(2.0, 0.0);
    EXPECT_NO_THROW({
        Rectangle r(a, b, c);
    });
}

TEST(RectangleTest, ConstructorAndArea) {
    Point a(0.0, 0.0), b(4.0, 0.0), c(4.0, 2.0);
    Rectangle rectangle(a, b, c);
    bool result = Utils::eqDouble((double)(rectangle), 8.0);
    ASSERT_TRUE(result == true);
}

TEST(RectangleTest, Center) {
    Point a(0.0, 0.0), b(4.0, 0.0), c(4.0, 2.0);
    Rectangle rectangle(a, b, c);
    Point realCenter(2.0, 1.0);
    Point center = rectangle.calcCentrRotation();
    bool result = (center == realCenter);
    ASSERT_TRUE(result == true);
}

TEST(RectangleTest, EqualRectangle) {
    Point a(0.0, 0.0), b(2.0, 0.0), c(2.0, 2.0);
    Rectangle rectangle1(a, b, c);
    Point d(1.0, 1.0),e(3.0, 1.0), f(3.0, 3.0);
    Rectangle rectangle2(d, e, f);
    bool result = (rectangle1 == rectangle2);
    ASSERT_TRUE(result == true);
}

TEST(RhombusTest, ConstructorRhombus) {
    Rhombus rhombus = Rhombus();
    Point a(1.0, 0.0), b(0.0, 0.0), c(0.0, 1.0);
    Rhombus r(a, b, c);
    bool result = (rhombus == r);
    ASSERT_TRUE(result == true);
}

TEST(RhombusTest, InvalidRectangle) {
    Point a(0.0, 0.0), b(1.0, 1.0), c(-2.0, 15.0);
    EXPECT_THROW({
        Rhombus r(a, b, c);
    }, std::invalid_argument);
}

TEST(RhombusTest, ValidTrapezoid) {
    Point a(0.0, 0.0), b(1.0, 1.0), c(2.0, 0.0);
    EXPECT_NO_THROW({
        Rhombus r(a, b, c);
    });
}


TEST(RhombusTest, ConstructorAndArea) {
    Point a(1.0, 0.0), b(2.0, 1.0), c(3.0, 0.0);
    Rhombus rhombus(a, b, c);
    bool result = Utils::eqDouble((double)(rhombus), 2.0);
    ASSERT_TRUE(result == true);
}

TEST(RhombusTest, Center) {
    Point a(1, 0), b(2, 1), c(3, 0);
    Rhombus rhombus(a, b, c);
    Point realCenter(2.0, 0.0);
    Point center = rhombus.calcCentrRotation();
    bool result = (center == realCenter);
    ASSERT_TRUE(result == true);
}

TEST(RhombusTest, EqualRhombus) {
    Point a(0.0, -1.0), b(2.0, 0.0), c(4.0, -1.0);
    Rhombus rhombus1(a, b, c);
    Point d(0.0, -1.0),e(1.0, 1.0), f(0.0, 3.0);
    Rhombus rhombus2(d, e, f);
    bool result = (rhombus1 == rhombus2);
    ASSERT_TRUE(result == true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}