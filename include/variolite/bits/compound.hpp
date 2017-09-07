#pragma once

#include "permit.hpp"

#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/view/zip_view.hpp>

namespace v2 { namespace detail {

	template <int... Is>
	auto make_int_vector_back(std::integer_sequence<int, Is...>)
	{
		return boost::fusion::vector<boost::mpl::int_<Is>...>();
	}

	template <int I>
	auto make_int_vector()
	{
		return make_int_vector_back(std::make_integer_sequence<int, I>());
	}

	template <typename T1, typename T2, typename F>
	void compound_dispatch(T1& a, boost::mpl::false_, const T2& b, F f)
	{
		boost::fusion::for_each(a, [&] (auto& x) { f(x, b); });
	}

	template <typename T1, typename T2, typename F>
	void compound_dispatch(T1& a, boost::mpl::true_, T2&& b, F f)
	{
		using size = typename boost::fusion::result_of::size<std::decay_t<T1>>::type;
		boost::fusion::for_each(make_int_vector<size::value>(), [&] (auto&& v) {
				using index = std::decay_t<decltype(v)>;
				f(boost::fusion::at<index>(a), boost::fusion::at<index>(b));
			});
	}

} } // namespace v2::detail

namespace v2 {

	template <typename T1, typename T2, typename F>
	auto& compound(T1& a, T2&& b, F f)
	{
		detail::compound_dispatch(a, v2::permitted<T2>(), std::forward<T2>(b), f);
		return a;
	}

} // namespace v2
