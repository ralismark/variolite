/*
 * Check construction requirements
 */

#include "variolite/all.hpp"

int main()
{
	using v2i = v2::vector<int, 2>;

	v2i a(1); // not enough arguments
}
