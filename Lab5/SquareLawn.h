#pragma once

#include "RectangleLawn.h"

namespace lab5
{

	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int x);
		virtual ~SquareLawn();
		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mX;
	};
}
