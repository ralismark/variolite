#pragma once

#include "fwd.hpp"

#include <boost/fusion/support/tag_of_fwd.hpp>

namespace boost { namespace fusion { namespace traits {

	template <typename T, unsigned int N>
	struct tag_of<v2::vector<T, N>>
	{
		using type = v2::vector_fusion_tag;
	};

	template <typename T, unsigned int N>
	struct tag_of<v2::vector_iterator<T, N>>
	{
		using type = v2::vector_fusion_tag;
	};

} } } // namespace boost::fusion::traits
