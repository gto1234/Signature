#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

#include "Md5Hashier.h"
#include "DebugLogger.h"



CMd5Hashier::CMd5Hashier() {
}
CMd5Hashier::~CMd5Hashier() {
}

std::string CMd5Hashier::toString(const boost::uuids::detail::md5::digest_type& digest)
{
	const auto intDigest = reinterpret_cast<const int*>(&digest);
	std::string result;
	
	boost::algorithm::hex(intDigest, intDigest + (sizeof(boost::uuids::detail::md5::digest_type) / sizeof(int)), std::back_inserter(result));
	return result;
}

//TODO: link,Include Boost, get md5 here
std::string CMd5Hashier::calculate(const std::string& incomingBuffer)
{
	boost::uuids::detail::md5 hash;
	boost::uuids::detail::md5::digest_type digest;

	hash.process_bytes(incomingBuffer.data(), incomingBuffer.size());
	hash.get_digest(digest);	
	
	return toString(digest);
}
