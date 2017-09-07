#pragma once

#include <boost/fusion/support/is_sequence.hpp>

#include <type_traits>

namespace v2 {

	template <typename T>
	using permitted = typename boost::fusion::traits::is_sequence<std::decay_t<T>>::type;

} // namespace v2
