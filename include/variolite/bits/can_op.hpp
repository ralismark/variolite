#pragma once

#include "fwd.hpp"
#include "permit.hpp"

namespace v2 {

	template <bool B>
	struct sfinae_helper
		: boost::mpl::false_
	{
	};

	template <>
	struct sfinae_helper<true>
		: boost::mpl::true_
	{
		using sfinae = void;
	};

	template <typename T>
	struct is_vector
		: boost::mpl::false_
	{
	};

	template <typename T, unsigned int N>
	struct is_vector<v2::vector<T, N>>
		: boost::mpl::true_
	{
		using sfinae = void;
	};

	template <typename T1, typename T2>
	using can_op = sfinae_helper<
		(is_vector<T1>::value || is_vector<T2>::value) &&
		(permitted<T1>::value && permitted<T2>::value)
		>;

	template <typename T1, typename T2>
	using can_weak_op = sfinae_helper<
		is_vector<T1>::value || is_vector<T2>::value
		>;

	template <typename T1, typename T2>
	using can_compound_op = sfinae_helper<
		is_vector<T1>::value && permitted<T2>::value
		>;

	template <typename T1, typename T2>
	using can_weak_compound_op = sfinae_helper<
		is_vector<T1>::value
		>;

} // namespace v2
