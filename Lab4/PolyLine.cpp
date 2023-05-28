#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mSize(0)
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			mList[i] = NULL;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mSize(other.mSize)
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mList[i] = new Point(other.mList[i]->GetX(), other.mList[i]->GetY());
		}

	}

	PolyLine::~PolyLine()
	{
		delete[] mList;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize < 10)
		{
			mList[mSize] = new Point(x, y);
			mSize++;

			return true;
		}
		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize < 10)
		{
			mList[mSize] = point;
			mSize++;

			return true;
		}
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i < mSize)
		{
			delete mList[i];
			for (unsigned int index = i; index < mSize - 1; index++)
			{
				mList[index] = mList[index + 1];
			}
			mSize--;
			mList[mSize] = NULL;

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


		if (mSize > 0)
		{
			min_x = mList[0]->GetX();
			min_y = mList[0]->GetY();
			max_x = min_x;
			max_y = min_y;
			if (mSize > 1)
			{
				for (unsigned int i = 1; i < mSize; i++)
				{
					if (min_x > mList[i]->GetX())
					{
						min_x = mList[i]->GetX();
					}

					if (min_y > mList[i]->GetY())
					{
						min_y = mList[i]->GetY();
					}

					if (max_x < mList[i]->GetX())
					{
						max_x = mList[i]->GetX();
					}

					if (max_y < mList[i]->GetY())
					{
						max_y = mList[i]->GetY();
					}
				}
			}
			Point minPoint(min_x, min_y);
			Point maxPoint(max_x, max_y);

			*outMin = minPoint;
			*outMax = maxPoint;

			return true;

		}

		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < mSize)
		{
			return mList[i];
		}
		return NULL;
	}

	void PolyLine::operator=(const PolyLine& rhs)
	{
		mSize = rhs.mSize;
		const Point* temp;

		for (unsigned int i = 0; i < mSize; i++)
		{
			temp = mList[i];
			mList[i] = new Point(rhs.mList[i]->GetX(), rhs.mList[i]->GetY());
			delete temp;
		}


	}
}