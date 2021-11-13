#pragma once
#include <boost/uuid/detail/md5.hpp>
#include "Hashier.h"

class CMd5Hashier : public IHashier
{
public:
	CMd5Hashier();
	~CMd5Hashier();

	/*calculate hash from put data block*/
	virtual std::string calculate(const std::vector<uint8_t>& incomingBuffer);

private:
	std::string toString(const boost::uuids::detail::md5::digest_type& digest);
};