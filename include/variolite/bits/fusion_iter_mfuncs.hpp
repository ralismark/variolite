#pragma once

#include "fusion_iterator.hpp"

#include <boost/mpl/equal.hpp>

#include <type_traits>

namespace boost { namespace fusion { namespace extension {

	template <typename>
	struct value_of_impl;

	template <>
	struct value_of_impl<v2::vector_fusion_tag>
	{
		template <typename Iterator>
		struct apply
		{
			using type = typename Iterator::vector_type::value_type;
		};
	};

	template <typename>
	struct deref_impl;

	template <>
	struct deref_impl<v2::vector_fusion_tag>
	{
		template <typename Iterator>
		struct apply
		{
			using type = typename mpl::if_<std::is_const<typename Iterator::vector_type>,
				typename Iterator::vector_type::value_type const&,
				typename Iterator::vector_type::value_type&>::type;

			static type call(Iterator const& it)
			{
				return it.vec[Iterator::index::value];
			}
		};
	};

	template <typename>
	struct next_impl;

	template <>
	struct next_impl<v2::vector_fusion_tag>
	{
		template <typename Iterator>
		struct apply
		{
			using type = typename Iterator::next;

			static type call(Iterator const& it)
			{
				return type{it.vec};
			}
		};
	};

	template <typename>
	struct equal_to_impl;

	template <>
	struct equal_to_impl<v2::vector_fusion_tag>
	{
		template <typename T1, typename T2>
		struct apply
			: mpl::bool_<std::is_same<T1, T2>::value>
		{
		};
	};

	template <typename>
	struct prior_impl;

	template <>
	struct prior_impl<v2::vector_fusion_tag>
	{
		template <typename Iterator>
		struct apply
		{
			using type = typename Iterator::prev;

			static type call(Iterator const& it)
			{
				return type{it.vec};
			}
		};
	};

	template <typename>
	struct distance_impl;

	template <>
	struct distance_impl<v2::vector_fusion_tag>
	{
		template <typename First, typename Last>
		struct apply
		{
			using type = mpl::int_<First::index::value - Last::index::value>;

			static type call(First const& /* first */, Last const& /* last */)
			{
				return {};
			}
		};
	};

	template <typename>
	struct advance_impl;

	template <>
	struct advance_impl<v2::vector_fusion_tag>
	{
		template <typename Iterator, typename N>
		struct apply
		{
			using vec_type = typename Iterator::vector_type;
			using index = typename Iterator::index;
			using type = v2::vector_iterator<vec_type, index::value + N::value>;

			static type call(Iterator const& it)
			{
				return type(it.vec);
			}
		};
	};

} } } // namespace boost::fusion::extension
