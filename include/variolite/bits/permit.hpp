#pragma once

#include <boost/fusion/support/is_sequence.hpp>

namespace v2 {

	template <typename T>
	using permitted = typename boost::fusion::traits::is_sequence<T>::type;

} // namespace v2
