#include "Metrics.h"
#include "Arduino.h"

/*
    Vector2 Class defentitions
*/

// define static members
const Vector2 Vector2::up(0, 1);
const Vector2 Vector2::down(0, -1);
const Vector2 Vector2::left(-1, 0);
const Vector2 Vector2::right(1, 0);
const Vector2 Vector2::one(1, 1);
const Vector2 Vector2::zero(0, 0);

// functions
Vector2 Vector2::rotate(int16_t deg) {
    int16_t rad = -deg * (PI / 180); // deg2rad
    float x = X * cos(rad) - Y * sin(rad);
    float y = X * sin(rad) + Y * cos(rad);
    return Vector2(x, y);
}

float Vector2::magnitude() {
    return sqrt(pow(X, 2) + pow(Y, 2));
}

Vector2 Vector2::unit() {
    return (*this / magnitude());
}

Vector2 Vector2::normalized() {
    return (*this / magnitude());
}

void Vector2::normalize() {
    Vector2 Normalized = normalized();
    X = Normalized.X;
    Y = Normalized.Y;
}

Vector2 Vector2::lerp(Vector2 Vector, float a) {
    float x = X + (Vector.X - X) * a;
    float y = Y + (Vector.Y - Y) * a;
    return Vector2(x, y);
}

Vector2 Vector2::clamp(Vector2 Min, Vector2 Max) {
    return Vector2(
        constrain(X, Min.X, Max.X),
        constrain(Y, Min.Y, Max.Y)
    );
}

Vector2 Vector2::absolute() {
    return Vector2(
        abs(X),
        abs(Y)
    );
}

float Vector2::dot(Vector2 Vector) {
    return X * Vector.X + Y * Vector.Y;
}

float Vector2::distance(Vector2 Vector) {
    return (*this - Vector).magnitude();
}

// math operators
Vector2 Vector2::operator+(const Vector2& other) {
    return Vector2(
        X + other.X,
        Y + other.Y
    );
}

Vector2 Vector2::operator-(const Vector2& other) {
    return Vector2(
        X - other.X,
        Y - other.Y
    );
}

Vector2 Vector2::operator*(const Vector2& other) {
    return Vector2(
        X * other.X,
        Y * other.Y
    );
}

Vector2 Vector2::operator/(const Vector2& other) {
    return Vector2(
        X / other.X,
        Y / other.Y
    );
}

Vector2 Vector2::operator*(const float& value) {
    return Vector2(
        X * value,
        Y * value
    );
}

Vector2 Vector2::operator/(const float& value) {
    return Vector2(
        X / value,
        Y / value
    );
}

Vector2& Vector2::operator+=(const Vector2& other) {
    this -> X += other.X;
    this -> Y += other.Y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    this -> X -= other.X;
    this -> Y -= other.Y;

    return *this;
}

Vector2& Vector2::operator*=(const Vector2& other) {
    this -> X *= other.X;
    this -> Y *= other.Y;

    return *this;
}

Vector2& Vector2::operator/=(const Vector2& other) {
    this -> X /= other.X;
    this -> Y /= other.Y;
 
    return *this;
}

Vector2& Vector2::operator*=(const float& value) {
    this -> X *= value;
    this -> Y *= value;

    return *this;
}

Vector2& Vector2::operator/=(const float& value) {
    this -> X /= value;
    this -> Y /= value;

    return *this;
}

Vector2& Vector2::operator=(const IVector2 &other) {
    this -> X = other.X;
    this -> Y = other.Y;

    return *this;
}

// bool operators
bool Vector2::operator==(const Vector2& other) {
    return X == other.X && Y == other.Y;
}

bool Vector2::operator!=(const Vector2& other) {
    return X != other.X || Y != other.Y;
}

/*
    IVector2 Class defentitions
*/

// define static members
const IVector2 IVector2::up(0, 1);
const IVector2 IVector2::down(0, -1);
const IVector2 IVector2::left(-1, 0);
const IVector2 IVector2::right(1, 0);
const IVector2 IVector2::one(1, 1);
const IVector2 IVector2::zero(0, 0);

// functions
IVector2 IVector2::rotate(int16_t deg) {
    int16_t rad = -deg * (PI / 180); // deg2rad
    int16_t x = round(X * cos(rad) - Y * sin(rad));
    int16_t y = round(X * sin(rad) + Y * cos(rad));
    return IVector2(x, y);
}

float IVector2::magnitude() {
    return sqrt(pow(X, 2) + pow(Y, 2));
}

IVector2 IVector2::unit() {
    return (*this / magnitude());
}

IVector2 IVector2::normalized() {
    return (*this / magnitude());
}

void IVector2::normalize() {
    IVector2 Normalized = normalized();
    X = Normalized.X;
    Y = Normalized.Y;
}

IVector2 IVector2::lerp(IVector2 Vector, float a) {
    float x = round(X + (Vector.X - X) * a);
    float y = round(Y + (Vector.Y - Y) * a);
    return IVector2(x, y);
}

IVector2 IVector2::clamp(IVector2 Min, IVector2 Max) {
    return IVector2(
        constrain(X, Min.X, Max.X),
        constrain(Y, Min.Y, Max.Y)
    );
}

IVector2 IVector2::absolute() {
    return IVector2(
        abs(X),
        abs(Y)
    );
}

float IVector2::dot(IVector2 Vector) {
    return X * Vector.X + Y * Vector.Y;
}

float IVector2::distance(IVector2 Vector) {
    return (*this - Vector).magnitude();
}

// math operators
IVector2 IVector2::operator+(const IVector2& other) {
    return IVector2(
        X + other.X,
        Y + other.Y
    );
}

IVector2 IVector2::operator-(const IVector2& other) {
    return IVector2(
        X - other.X,
        Y - other.Y
    );
}

IVector2 IVector2::operator*(const IVector2& other) {
    return IVector2(
        X * other.X,
        Y * other.Y
    );
}

IVector2 IVector2::operator/(const IVector2& other) {
    return IVector2(
        X / other.X,
        Y / other.Y
    );
}

IVector2 IVector2::operator*(const float& value) {
    return IVector2(
        X * value,
        Y * value
    );
}

IVector2 IVector2::operator/(const float& value) {
    return IVector2(
        X / value,
        Y / value
    );
}

IVector2& IVector2::operator+=(const IVector2& other) {
    this -> X += other.X;
    this -> Y += other.Y;

    return *this;
}

IVector2& IVector2::operator-=(const IVector2& other) {
    this -> X -= other.X;
    this -> Y -= other.Y;

    return *this;
}

IVector2& IVector2::operator*=(const IVector2& other) {
    this -> X *= other.X;
    this -> Y *= other.Y;

    return *this;
}

IVector2& IVector2::operator/=(const IVector2& other) {
    this -> X /= other.X;
    this -> Y /= other.Y;
 
    return *this;
}

IVector2& IVector2::operator*=(const float& value) {
    this -> X *= value;
    this -> Y *= value;

    return *this;
}

IVector2& IVector2::operator/=(const float& value) {
    this -> X /= value;
    this -> Y /= value;

    return *this;
}

IVector2& IVector2::operator=(const Vector2 &other) {
    this -> X = round(other.X);
    this -> Y = round(other.Y);

    return *this;
}

// bool operators
bool IVector2::operator==(const IVector2& other) {
    return X == other.X && Y == other.Y;
}

bool IVector2::operator!=(const IVector2& other) {
    return X != other.X || Y != other.Y;
}

/*
    Line functions
*/
Vector2 Line::getCenter() {
    return start->lerp(*end, .5f);
}

Vector2 Line::intersect(Line line) {
    float alpha = ((line.end->X - line.start->X) * (line.start->Y - start->Y) - (line.end->Y - line.start->Y) * (line.start->X - start->X)) /
        ((line.end->X - line.start->X) * (end->Y - start->Y) - (line.end->Y - line.start->Y) * (end->X - start->X));

    float beta = ((end->X - start->X) * (line.start->Y - start->Y) - (end->Y - start->Y) * (line.start->X - start->X)) /
        ((line.end->X - line.start->X) * (start->Y - start->Y) - (line.end->Y - line.start->Y) * (end->X - start->X));

    if (alpha + beta == 0 || beta == 0)
        return Vector2::zero;

    return Vector2(start->X + alpha * (end->X - start->X), start->Y + alpha * (end->Y - start->Y));
}