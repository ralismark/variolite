#pragma once

#include "can_op.hpp"
#include "binary.hpp"

namespace v2 { namespace ops {

	template <typename T1, typename T2, typename = typename can_op<T1, T2>::sfinae>
	auto operator+(T1&& a, T2&& b)
	{
		return binary(std::forward<T1>(a), std::forward<T2>(b),
			[] (auto&& x, auto&& y) { return x + y; }
			);
	}

	template <typename T1, typename T2, typename = typename can_op<T1, T2>::sfinae>
	auto operator-(T1&& a, T2&& b)
	{
		return binary(std::forward<T1>(a), std::forward<T2>(b),
			[] (auto&& x, auto&& y) { return x - y; }
			);
	}

	template <typename T1, typename T2, typename = typename can_weak_op<T1, T2>::sfinae>
	auto operator*(T1&& a, T2&& b)
	{
		return binary(std::forward<T1>(a), std::forward<T2>(b),
			[] (auto&& x, auto&& y) { return x * y; }
			);
	}

	template <typename T1, typename T2, typename = typename can_weak_op<T1, T2>::sfinae>
	auto operator/(T1&& a, T2&& b)
	{
		return binary(std::forward<T1>(a), std::forward<T2>(b),
			[] (auto&& x, auto&& y) { return x / y; }
			);
	}

} } // namespace v2::ops
