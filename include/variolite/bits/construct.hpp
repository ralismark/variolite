#pragma once

#include "fwd.hpp"

#include <boost/fusion/functional/invocation/invoke.hpp>

#include <array>

namespace v2 { namespace detail {

	template <typename Elem, unsigned int N>
	struct array_factory
	{
		template <typename... Ts>
		std::array<Elem, N> operator()(Ts&&... args)
		{
			return {{ args... }};
		}
	};

	template <typename T>
	struct value_factory
	{
		template <typename... Ts>
		T operator()(Ts&&... args)
		{
			return { args... };
		}
	};

	struct deduce_vector_factory
	{
		template <typename... Ts>
		vector<std::common_type_t<Ts...>, sizeof...(Ts)> operator()(Ts&&... args)
		{
			return { args... };
		}
	};

} } // namespace v2::detail
