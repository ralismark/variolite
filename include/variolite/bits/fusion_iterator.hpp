#pragma once

#include <boost/fusion/support/category_of.hpp>
#include <boost/fusion/support/iterator_base.hpp>
#include <boost/mpl/int.hpp>

#include "fusion_tag.hpp"

namespace v2 {

	template <typename Vec, unsigned int Pos>
	struct vector_iterator
		: public boost::fusion::iterator_base<vector_iterator<Vec, Pos>>
	{
		// equals permits end iterator
		static_assert(Pos <= Vec::size::value, "Iterator out of range");

	public: // statics

		using next = vector_iterator<Vec, Pos + 1>;
		using prev = vector_iterator<Vec, Pos - 1>;

		using vector_type = Vec;
		using index = boost::mpl::int_<Pos>;
		using category = boost::fusion::random_access_traversal_tag;

	public: // variables

		vector_type& vec;

	public: // methods

		constexpr vector_iterator(vector_type& init)
			: vec(init)
		{
		}
	};

} // namespace v2
