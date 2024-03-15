#ifndef METRICS_H
#define METRICS_H
#include "Arduino.h"
// pre-define
struct Vector2;
struct IVector2;

struct Vector2 {
public:
  // Constructors
  Vector2() : X(0), Y(0) {}
  Vector2(float x, float y) : X(x), Y(y) {}

  // Properties
  float X;
  float Y;

  // Static
  static const Vector2 up;
  static const Vector2 down;
  static const Vector2 left;
  static const Vector2 right;
  static const Vector2 one;
  static const Vector2 zero;

  // Methods
  Vector2 rotate(int16_t deg);
  float magnitude();
  Vector2 unit();
  Vector2 normalized();
  void normalize();
  Vector2 lerp(Vector2 Vector, float a);
  Vector2 clamp(Vector2 Min, Vector2 Max);
  Vector2 absolute();
  float dot(Vector2 Vector);
  float distance(Vector2 Vector);

  // Math Operators
  Vector2 operator+(const Vector2 &other);
  Vector2 operator-(const Vector2 &other);
  Vector2 operator*(const Vector2 &other);
  Vector2 operator/(const Vector2 &other);
  Vector2 operator*(const float &value);
  Vector2 operator/(const float &value);
  Vector2& operator+=(const Vector2 &other);
  Vector2& operator-=(const Vector2 &other);
  Vector2& operator*=(const Vector2 &other);
  Vector2& operator/=(const Vector2 &other);
  Vector2& operator*=(const float &value);
  Vector2& operator/=(const float &value);
  Vector2& operator=(const IVector2 &other); // converts IVector2 to Vector2

  // Bool Operators
  bool operator==(const Vector2 &other);
  bool operator!=(const Vector2 &other);
};

struct IVector2 {
public:
  // Constructors
  IVector2() : X(0), Y(0) {}
  IVector2(int16_t x, int16_t y) : X(x), Y(y) {}

  // Properties
  int16_t X;
  int16_t Y;

  // Static
  static const IVector2 up;
  static const IVector2 down;
  static const IVector2 left;
  static const IVector2 right;
  static const IVector2 one;
  static const IVector2 zero;

  // Methods
  IVector2 rotate(int16_t deg);
  float magnitude();
  IVector2 unit();
  IVector2 normalized();
  void normalize();
  IVector2 lerp(IVector2 Vector, float a);
  IVector2 clamp(IVector2 Min, IVector2 Max);
  IVector2 absolute();
  float dot(IVector2 Vector);
  float distance(IVector2 Vector);

  // Math Operators
  IVector2 operator+(const IVector2 &other);
  IVector2 operator-(const IVector2 &other);
  IVector2 operator*(const IVector2 &other);
  IVector2 operator/(const IVector2 &other);
  IVector2 operator*(const float &value);
  IVector2 operator/(const float &value);
  IVector2& operator+=(const IVector2 &other);
  IVector2& operator-=(const IVector2 &other);
  IVector2& operator*=(const IVector2 &other);
  IVector2& operator/=(const IVector2 &other);
  IVector2& operator*=(const float &value);
  IVector2& operator/=(const float &value);
  IVector2& operator=(const Vector2 &other); // converts Vector2 to IVector2

  // Bool Operators
  bool operator==(const IVector2 &other);
  bool operator!=(const IVector2 &other);
};

struct Line {
public:
	Line(Vector2* Start, Vector2* End) : start(Start), end(End) {}
	Vector2 getCenter();
	Vector2 intersect(Line line);

private:
	Vector2* start;
	Vector2* end;
};

#endif
