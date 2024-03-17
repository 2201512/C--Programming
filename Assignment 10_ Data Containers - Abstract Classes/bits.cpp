#include "bits.h"

namespace hlp2 {
	bits::bits(size_t ip) : siz(ip), ar(siz ? new bool[siz] : nullptr)
	{
		clear();
	}
	bits::bits(bits const& rhs) : siz(rhs.siz), ar(siz ? new bool[siz] : nullptr)
	{
		for (size_t i{}; i < siz; ++i)
			ar[i] = rhs.ar[i];
	}
	bits::~bits()
	{
		delete[] ar;
	}
	bits& bits::operator=(bits const& rhs)
	{
		bool* tmp = rhs.siz ? new bool[rhs.siz] : nullptr;
		siz = rhs.siz;
		for (size_t i{}; i < siz; ++i)
			tmp[i] = rhs.ar[i];
		delete ar;
		ar = tmp;
		return *this;
	}
	size_t bits::size() const
	{
		return siz;
	}
	void bits::clear()
	{
		for (size_t i{}; i < siz; ++i)
			ar[i] = false;
	}
}