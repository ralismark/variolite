#pragma once

#include "construct.hpp"
#include "fwd.hpp"
#include "permit.hpp"
#include "vec_base.hpp"

#include <boost/fusion/algorithm/iteration/for_each.hpp>

#include <type_traits>

namespace v2 {

	template <typename T, unsigned int N>
	struct vector
		: public vec_base<T, N>
	{
	public: // statics

		using value_type = T;
		using size = std::integral_constant<unsigned int, N>;

	public: // methods

		// basic constructors
		constexpr vector() = default;
		constexpr vector(vector&&) = default;
		constexpr vector(const vector&) = default;

		// all-dimension construction
		template <typename... Ts, typename = std::enable_if_t<(sizeof...(Ts) == N)>>
		constexpr vector(Ts&&... args)
			: vec_base<T, N>{{{{ std::forward<Ts>(args)... }}}}
		{
		}

		// from other permitted types
		template <typename Seq, typename = std::enable_if_t<permitted<Seq>::value>>
		constexpr vector(Seq&& seq)
			: vec_base<T, N>{{
				boost::fusion::invoke(detail::array_factory<T, N>{}, seq)
			}}
		{
		}

		// dimension access
		constexpr T& operator[](std::size_t idx)
		{
			return this->vec_base<T, N>::data[idx];
		}

		constexpr T const& operator[](std::size_t idx) const
		{
			return this->vec_base<T, N>::data[idx];
		}
	};

} // namespace v2
