#include "file_metadata.hpp"

using namespace std;

//@todo change hash generation method
file_metadata::file_metadata(filesystem::path _path)
{
	this->path = _path;
	this->file_size = filesystem::file_size(file_metadata::path);
	this->md5_hash_cache = "";
}

string file_metadata::get_md5_hash()
{
	if (this->md5_hash_cache.empty())
	{
		ifstream file_stream(((string)this->path), ios::in | ios::binary);
		if (file_stream.is_open())
		{
			char *file_data = new char[this->file_size];
			unsigned char hash[MD5_DIGEST_LENGTH];
			MD5_CTX md5;
			MD5_Init(&md5);
			file_stream.read(file_data, this->file_size);
			MD5_Update(&md5, file_data, file_stream.gcount());
			MD5_Final(hash, &md5);

			std::stringstream ss;

			for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
			{
				ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
			}
			string md5_string = ss.str();
			this->md5_hash_cache = md5_string;
			delete[] file_data;
			file_stream.close();
		}
	}
	return this->md5_hash_cache;
}

file_metadata::~file_metadata()
{
}
