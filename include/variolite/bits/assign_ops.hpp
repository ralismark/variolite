#pragma once

#include "can_op.hpp"
#include "compound.hpp"

namespace v2 { namespace ops {

	template <typename T1, typename T2, typename = typename can_compound_op<T1, T2>::sfinae>
	auto& operator+=(T1& a, T2&& b)
	{
		return compound(a, std::forward<T2>(b), [] (auto& x, auto&& y) { x += y; });
	}

	template <typename T1, typename T2, typename = typename can_compound_op<T1, T2>::sfinae>
	auto& operator-=(T1& a, T2&& b)
	{
		return compound(a, std::forward<T2>(b), [] (auto& x, auto&& y) { x -= y; });
	}

	template <typename T1, typename T2, typename = typename can_weak_compound_op<T1, T2>::sfinae>
	auto& operator*=(T1& a, T2&& b)
	{
		return compound(a, std::forward<T2>(b), [] (auto& x, auto&& y) { x *= y; });
	}

	template <typename T1, typename T2, typename = typename can_weak_compound_op<T1, T2>::sfinae>
	auto& operator/=(T1& a, T2&& b)
	{
		return compound(a, std::forward<T2>(b), [] (auto& x, auto&& y) { x /= y; });
	}

} } // namespace v2::ops
