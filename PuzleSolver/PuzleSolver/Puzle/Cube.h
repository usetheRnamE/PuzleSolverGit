#pragma once

#include "Puzle.h"

namespace Puzle
{
	class Cube : public Puzle
	{
	private:
		const int cubeSide = 6;

	public:
		const int GetSideCount() { return cubeSide; } 
	};
}
