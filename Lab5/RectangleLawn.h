#pragma once
#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{

	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		unsigned int GetArea() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetMinimumFencesCount() const;
		RectangleLawn(unsigned int x, unsigned int y);
		virtual ~RectangleLawn();
	private:
		unsigned int mX;
		unsigned int mY;
	};
}
