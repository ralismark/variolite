#pragma once

#include <array>
#include <utility>

#include "fwd.hpp"

namespace v2 {

// Anonymous structs are generally well supported, but non-standard and issue warnings
// This suppresses these warnings for common compilers.
// If it's not supported for your compiler, I'm sorry.
#if defined(__llvm__)
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
	#pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined(_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable: 4201)
#elif defined(__GNUC__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpedantic"
#endif

	template <typename T>
	struct vec_base<T, 0>
	{
	};

	template <typename T>
	struct vec_base<T, 1>
	{
		union {
			std::array<T, 1> data;
			struct {
				T x;
			};
		};
	};

	template <typename T>
	struct vec_base<T, 2>
	{
		union {
			std::array<T, 2> data;
			struct {
				T x, y;
			};
		};
	};

	template <typename T>
	struct vec_base<T, 3>
	{
		union {
			std::array<T, 3> data;
			struct {
				T x, y, z;
			};
			vector<T, 2> xy;
		};
	};

	template <typename T>
	struct vec_base<T, 4>
	{
		union {
			std::array<T, 4> data;
			struct {
				T x, y, z, w;
			};
			vector<T, 2> xy;
			vector<T, 3> xyz;
		};
	};

	template <typename T, unsigned int N>
	struct vec_base // N >= 4
	{
		union {
			std::array<T, N> data;
			struct { // named goes up to 4
				T x, y, z, w;
			};
			vector<T, 2> xy;
			vector<T, 3> xyz;
			vector<T, 4> xyzw;
		};
	};

#if defined(__llvm__)
	#pragma clang diagnostic pop
#elif defined(_MSC_VER)
	#pragma warning(pop)
#elif defined(__GNUC__)
	#pragma GCC diagnostic pop
#endif

} // namespace v2
