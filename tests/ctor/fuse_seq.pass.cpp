/*
 * Check that a permitted sequence can be constructed
 */

#include "variolite/all.hpp"

#include <boost/fusion/include/make_vector.hpp>

#include <cassert>

int main()
{
	using v2i = v2::vector<int, 2>;

	v2i a(boost::fusion::make_vector(1, 2));
	assert((a.x == 1 && a.y == 2) && "Construct from permitted sequence");
}
