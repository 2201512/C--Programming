#ifndef BITS_H
#define BITS_H

#include "cont.h"

namespace hlp2 {
	class bits : public cont
	{
	public:
		bits(size_t = 100);
		bits(bits const& rhs);
		~bits();
		bits& operator=(bits const&);
		size_t size() const override;
		void clear() override;
	private:
		size_t siz = 100;
		bool* ar = nullptr;
	};
}

#endif