# variolite
Boost (fusion)-compatible n-dimensional generic (math) vector

This library contains a vector class that works well with other (specified)
fusion sequences (inc. Operators and casting). As you might expect, this library
depends on Boost - specifically Boost fusion and Boost MPL.

## Installation/Usage

Variolite is header only. Copy the contents of the include/ folder into your
include directory.

Include `variolite/all.hpp` if you want everything. If you want only a certain
part of the library, include the following headers for:
1. The core vector class (include `variolite/vector.hpp`)
2. Fusion adapters for the class (include `variolite/fusion_adapt.hpp`)
3. Operators overloads (include `variolite/ops.hpp`)

Everything is in the namespace `v2`, including the main vector class
`v2::vector<T, N>`. No proxy classes are used - everything that you think is a
reference is a reference.

```c++
// initialise everything to zero
v2::vector<int, 5> z; // z = (0 0 0 0 0)

// initialise by specifying all elements (note: all must be specified)
v2::vector<int, 5> a = {1, 2, 3, 4, 5};

// swizzling
v2::vector<int, 3> b = a.xyz; // b = (1 2 3)

// named dimensions (x, y, z, w)
int c = b.x * b.y + a.z * a.w; // c = 1 * 2 + 3 * 4 = 14

// access with index
int d = c + a[4]; // d = 14 + 5
```

## Working with boost sequences

Variolite is able to work well with other types; however, support is not
automatically given to all types. To add support, specialise
`v2::extension::permit<T>` to inherit `boost::mpl::true_`, like this:

```c++
// Adding support for my_seq

namespace v2 { namespace extension {

	template <>
	struct permit<my_seq>
		: boost::mpl::true_
	{
	};

} }
```

A second template parameter that defaults to void is available for SFINAE. Also,
the sequence must fit the requirements for a fusion sequence. See boost
documentation for more details on making a type a boost sequence.

> Note: types do not have to be fusion's own containers - adapted/extended types
> are fine
