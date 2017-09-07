#pragma once

#include "construct.hpp"
#include "permit.hpp"

#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/container/generation/vector_tie.hpp>

#include <utility>

namespace v2 { namespace detail {

	template <typename T, std::size_t... Is>
	auto fill_ref_back(T&& val, std::index_sequence<Is...>)
	{
		return boost::fusion::vector_tie(((void)Is, std::forward<T>(val))...);
	}

	template <unsigned int N, typename T>
	auto fill_ref(T&& val)
	{
		return fill_ref_back(std::forward<T>(val), std::make_index_sequence<N>());
	}

	template <typename T1, typename T2, typename F>
	auto binary_dispatch(boost::mpl::false_, const T1& a, boost::mpl::true_, T2&& b, F f)
	{
		using seq_size = typename boost::fusion::result_of::size<std::decay_t<T2>>::type;
		auto filled = fill_ref<seq_size::value>(a);
		return boost::fusion::invoke(detail::deduce_vector_factory{},
			boost::fusion::transform(filled, std::forward<T2>(b), f)
			);
	}

	template <typename T1, typename T2, typename F>
	auto binary_dispatch(boost::mpl::true_, T1&& a, boost::mpl::false_, const T2& b, F f)
	{
		using seq_size = typename boost::fusion::result_of::size<std::decay_t<T1>>::type;
		auto filled = fill_ref<seq_size::value>(b);
		return boost::fusion::invoke(detail::deduce_vector_factory{},
			boost::fusion::transform(std::forward<T1>(a), filled, f)
			);
	}

	template <typename T1, typename T2, typename F>
	auto binary_dispatch(boost::mpl::true_, T1&& a, boost::mpl::true_, T2&& b, F f)
	{
		return boost::fusion::invoke(detail::deduce_vector_factory{},
			boost::fusion::transform(std::forward<T1>(a), std::forward<T2>(b), f)
			);
	}

} } // namespace v2::detail

namespace v2 {

	template <typename T1, typename T2, typename F>
	auto binary(T1&& a, T2&& b, F f)
	{
		return detail::binary_dispatch(v2::permitted<T1>(), std::forward<T1>(a), v2::permitted<T2>(), std::forward<T2>(b), f);
	}

} // namespace v2
