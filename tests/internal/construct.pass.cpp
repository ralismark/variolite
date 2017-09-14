/*
 * check factories in v2::detail
 */

#include "variolite/bits/construct.hpp"
#include "variolite/bits/vector.hpp"

#include <cassert>
#include <utility>

template <typename T>
struct conv
{
	T val;

	template <typename U>
	operator U() const
	{
		return static_cast<U>(val);
	}
};

int main()
{
	// check array convert
	auto arr1 = v2::detail::array_factory<int, 3>{}(3, conv<double>{3.1}, conv<unsigned int>{3u});
	assert((std::is_same<std::array<int, 3>, decltype(arr1)>::value) && "Check type");
	assert((arr1[0] == 3 && arr1[1] == 3 && arr1[2] == 3) && "Check values");

	// check value convert
	auto val = v2::detail::value_factory<char>{}(conv<double>{3.1});
	assert((std::is_same<char, decltype(val)>::value) && "Check type");
	assert((val == 3) && "Check value");

	// check vector deduction
	auto vec = v2::detail::deduce_vector_factory{}((unsigned char)(3), (int)(3));
	assert((std::is_same<v2::vector<int, 2>, decltype(vec)>::value) && "Check type");
	assert((vec[0] == 3 && vec[1] == 3) && "Check values");
}
