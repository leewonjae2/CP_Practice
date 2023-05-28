#pragma once

namespace lab4
{
	class Point
	{
		friend Point operator*(const float operend, const Point& rhs);
	public:
		Point(float x, float y);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;

		float GetX() const;
		float GetY() const;

	private:
		float mX;
		float mY;
	};
}