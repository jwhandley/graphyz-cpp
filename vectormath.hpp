#pragma once
#include <raymath.h>

Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2Add(lhs, rhs);
}

Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2Subtract(lhs, rhs);
}

Vector2 operator*(const Vector2 &lhs, const float &rhs) {
    return Vector2Scale(lhs, rhs);
}

Vector2 operator+=(Vector2 &lhs, const Vector2 &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Vector2 operator-=(Vector2 &lhs, const Vector2 &rhs) {
    lhs = lhs - rhs;
    return lhs;
}