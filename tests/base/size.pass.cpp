/*
 * Check the size of types
 */

#include "variolite/all.hpp"

#include <cassert>

template <unsigned int N>
void check()
{
	v2::vector<int, N> vec{};
	assert((vec.data.size() == N) && "Size of underlying array");
	assert((sizeof(vec) == sizeof(int) * N) && "Size of whole container");
}

int main()
{
	check<1>();
	check<2>();
	check<3>();
	check<4>();
	check<5>();
}
