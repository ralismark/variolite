/*
 * Check index operators
 */

#include "variolite/all.hpp"

#include <cassert>

int main()
{
	using v5i = v2::vector<int, 5>;

	v5i a{0,1,2,3,4};

	for(int i = 0; i < 5; ++i) {
		assert((a[i] == i) && "Index value");
		a[i] = -i + 1;
		assert((a[i] == -i + 1) && "Set index value");
	}
}
