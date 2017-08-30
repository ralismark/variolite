#pragma once

#include <type_traits>

#include "fusion_iterator.hpp"
#include "fusion_sequence.hpp"

namespace boost { namespace fusion { namespace extension {

	template <typename>
	struct begin_impl;

	template <>
	struct begin_impl<v2::vector_fusion_tag>
	{
		template <typename Seq>
		struct apply
		{
			using type = v2::vector_iterator<Seq, 0>;

			static type call(Seq& seq)
			{
				return type{seq};
			}
		};
	};

	template <typename>
	struct end_impl;

	template <>
	struct end_impl<v2::vector_fusion_tag>
	{
		template <typename Seq>
		struct apply
		{
			using type = v2::vector_iterator<Seq, Seq::size::value>;

			static type call(Seq& seq)
			{
				return type{seq};
			}
		};
	};

	template <typename>
	struct size_impl;

	template <>
	struct size_impl<v2::vector_fusion_tag>
	{
		template <typename Seq>
		struct apply
			: mpl::int_<Seq::size::value>
		{
		};
	};

	template <typename>
	struct value_at_impl;

	template <>
	struct value_at_impl<v2::vector_fusion_tag>
	{
		template <typename Seq>
		struct apply
		{
			using type = typename Seq::value_type;
		};
	};

	template <typename>
	struct at_impl;

	template <>
	struct at_impl<v2::vector_fusion_tag>
	{
		template <typename Seq, typename N>
		struct apply
		{
			using type = typename mpl::if_<std::is_const<Seq>,
				typename Seq::value_type const&,
				typename Seq::value_type&>::type;

			static type call(Seq& seq)
			{
				return seq.data[N::value];
			}
		};
	};

} } } // namespace boost::fusion::extension
