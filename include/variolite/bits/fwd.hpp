#pragma once

namespace v2 {

	template <typename T, unsigned int N>
	struct vec_base;

	template <typename T, unsigned int N>
	struct vector;

	struct vector_fusion_tag;

	template <typename Vec, unsigned int Pos>
	struct vector_iterator;

} // namespace v2
