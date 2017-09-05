/*
 * Try to access swizzles that don't exist
 */

#include "variolite/all.hpp"

#include <cassert>

int main()
{
	using v2i = v2::vector<int, 2>;

	v2i a{};

	// if this succeeds, you have something seriously wrong
	(void)a.xy; // same dimensions does not exist
}
