#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: max(0)
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			list[i] = NULL;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: max(other.max)
	{
		for (unsigned int i = 0; i < max; i++)
		{
			list[i] = other.list[i];
		}

	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < max; i++)
		{
			delete list[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (max < 10)
		{
			list[max] = new Point(x, y);
			max++;

			return true;
		}
		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (max < 10)
		{
			list[max] = point;
			max++;

			return true;
		}
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i < max)
		{
			delete list[i];
			for (unsigned int index = i; index < max - 1; index++)
			{
				list[index] = list[index + 1];
			}
			max--;
			delete list[max];
			list[max] = NULL;

			return true;
		}
		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float min_x;
		float min_y;

		float max_x;
		float max_y;

		if (max > 1)
		{
			min_x = list[0]->GetX();
			min_y = list[0]->GetY();
			max_x = min_x;
			max_y = min_y;

			for (unsigned int i = 1; i < max; i++)
			{
				if (min_x > list[i]->GetX())
				{
					min_x = list[i]->GetX();
				}

				if (min_y > list[i]->GetY())
				{
					min_y = list[i]->GetY();
				}

				if (max_x < list[i]->GetX())
				{
					max_x = list[i]->GetX();
				}

				if (max_y < list[i]->GetY())
				{
					max_y = list[i]->GetY();
				}
			}

			if (min_x == max_x || min_y == max_y)
			{
				return false;
			}
			delete outMin;
			delete outMax;
			outMin = new Point(min_x, min_y);
			outMax = new Point(max_x, max_y);

			return true;

		}

		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		return list[i];
	}
}