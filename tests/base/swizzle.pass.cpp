/*
 * Try to access swizzles that don't exist
 */

#include "variolite/all.hpp"

#include <cassert>

int main()
{
	v2::vector<int, 5> v5 = {1,2,3,4,5};
	v2::vector<int, 4> v4 = {1,2,3,4};
	v2::vector<int, 3> v3 = {1,2,3};
	v2::vector<int, 2> v2 = {1,2};

	assert((v5.xyzw == v4) && "4 element swizzle");
	assert((v5.xyz == v4.xyz && v4.xyz == v3) && "3 element swizzle");
	assert((v5.xy == v4.xy && v4.xy == v3.xy && v3.xy == v2) && "2 element swizzle");
}
