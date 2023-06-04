#pragma once
#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{

	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(unsigned int x);
		virtual ~SquareLawn();
		unsigned int GetArea() const;
		unsigned int GetminimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mX;
	};
}
