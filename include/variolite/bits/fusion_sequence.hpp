#pragma once

#include <boost/fusion/support/category_of.hpp>
#include <boost/mpl/bool.hpp>

#include "fusion_tag.hpp"

namespace boost { namespace fusion { namespace extension {

	template <typename>
	struct is_sequence_impl;

	template <>
	struct is_sequence_impl<v2::vector_fusion_tag>
	{
		template <typename>
		struct apply : mpl::true_
		{
		};
	};

	template <typename>
	struct category_of_impl;

	template <>
	struct category_of_impl<v2::vector_fusion_tag>
	{
		template <typename>
		struct apply
		{
			struct type
				: random_access_traversal_tag
			{
			};
		};
	};

	template <typename>
	struct is_view_impl;

	template <>
	struct is_view_impl<v2::vector_fusion_tag>
	{
		template <typename>
		struct apply : boost::mpl::false_
		{
		};
	};

} } } // namespace boost::fusion::extension
