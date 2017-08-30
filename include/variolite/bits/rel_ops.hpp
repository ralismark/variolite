#pragma once

// this does everything we need
#include <boost/fusion/sequence/comparison.hpp>

namespace v2 { namespace ops {

	using boost::fusion::operator>;
	using boost::fusion::operator<;
	using boost::fusion::operator>=;
	using boost::fusion::operator<=;
	using boost::fusion::operator==;
	using boost::fusion::operator!=;

} } // namespace v2::ops
