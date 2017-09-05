/*
 * Check construction for v2::vector
 */

#include "variolite/all.hpp"

#include <cassert>

int main()
{
	using v2i = v2::vector<int, 2>;

	v2i a{}; // default
	assert((a.x == 0 && a.y == 0) && "Default initialisation should be 0");

	v2i b{1, 2}; // all elements explicitly
	assert((b.x == 1 && b.y == 2) && "Explicit all elements");

	v2i c{b}; // copy construct
	assert((c.x == 1 && c.y == 2) && "Copy construct");

	v2i d{std::move(b)}; // move construct
	assert((c.x == 1 && c.y == 2) && "Copy construct");
}
