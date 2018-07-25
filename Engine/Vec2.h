#pragma once

class Vec2
{
public:
	Vec2() = default;
	Vec2(float in_x, float in_y);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(float rhs);
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator-=(const Vec2& rhs);
	float GetLength()const;
	float GetLengthSq()const;
	Vec2& Normalized();
	Vec2 GetNormailzed()const;
public:
	float x;
	float y;
};

