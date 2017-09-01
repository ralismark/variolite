#pragma once

#include "fwd.hpp"

#include <boost/fusion/support/is_sequence.hpp>
#include <boost/mpl/bool.hpp>

#include <type_traits>

namespace v2 { namespace extension {

	template <typename, typename = void>
	struct permit
		: boost::mpl::false_
	{
	};

	template <typename T, unsigned int N>
	struct permit<v2::vector<T, N>>
		: boost::mpl::true_
	{
	};

} } // namespace v2::extension

namespace v2 {

	template <typename T, typename = void>
	struct permitted_back
	{
		using type = boost::mpl::bool_<extension::permit<T>::value>;
	};

	template <typename T>
	struct permitted_back<T, std::enable_if_t<
			extension::permit<T>::value &&
			!boost::fusion::traits::is_sequence<T>::type::value
		>>
	{
		static_assert(boost::fusion::traits::is_sequence<T>::type::value,
			"Permitted types must be a boost fusion sequence - check your permit specialisation");
		using type = boost::mpl::false_;
	};

	template <typename T>
	using permitted = typename permitted_back<std::decay_t<T>>::type;

} // namespace v2
