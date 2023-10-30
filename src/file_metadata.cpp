#include "file_metadata.hpp"

using namespace std;

//@todo change hash generation method
file_metadata::file_metadata(filesystem::path _path)
{
	file_metadata::path = _path;
	file_metadata::file_size = filesystem::file_size(file_metadata::path);
}

string file_metadata::get_md5_hash()
{
	FILE *file_stream = fopen(((string)this->path).c_str(), "rb");
	unsigned char* file_data = (unsigned char *)malloc(1024 * sizeof(unsigned char));
	unsigned char hash[MD5_DIGEST_LENGTH];
	MD5_CTX md5;
	MD5_Init(&md5);
	while (long int num_of_bytes = fread(file_data, sizeof(unsigned char), 1024, file_stream))
	{
		MD5_Update(&md5, file_data, num_of_bytes);
	}
	MD5_Final(hash, &md5);

	std::stringstream ss;

	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
	}
	string md5_string = ss.str();
	free(file_data);
	fclose(file_stream);
	return md5_string;
}

string md5(unsigned char *data, long int size)
{
	unsigned char hash[MD5_DIGEST_LENGTH];

	MD5_CTX md5;
	MD5_Init(&md5);
	MD5_Update(&md5, data, size);
	MD5_Final(hash, &md5);

	std::stringstream ss;

	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
	}
	return ss.str();
}

file_metadata::~file_metadata()
{
}
