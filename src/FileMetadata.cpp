#include "FileMetadata.hpp"

using namespace std;

//@todo change hash generation method
FileMetadata::FileMetadata(filesystem::path _path)
{
	this->path = _path;
	this->file_size = filesystem::file_size(FileMetadata::path);
	this->md5_hash_cache_ = "";
	this->md5_crc_cache_ = "";
}

string &FileMetadata::getCrc()
{
	if (this->md5_crc_cache_.empty())
	{
		ifstream file_stream(((string)this->path), ios::in | ios::binary);
		if (file_stream.is_open())
		{
			char *file_data = new char[CRC_READ_SIZE];
			char md5_hash_tmp[MD5_DIGEST_LENGTH];
			MD5_CTX md5;
			MD5_Init(&md5);
			file_stream.read(file_data, CRC_READ_SIZE);
			MD5_Update(&md5, file_data, file_stream.gcount());
			MD5_Final((unsigned char *)md5_hash_tmp, &md5);
			md5_crc_cache_ = string(md5_hash_tmp);
			delete[] file_data;
		}
	}
	return this->md5_crc_cache_;
}

string &FileMetadata::getMd5Hash()
{
	if (this->md5_hash_cache_.empty())
	{
		ifstream file_stream(((string)this->path), ios::in | ios::binary);
		if (file_stream.is_open())
		{
			char *file_data = new char[this->file_size];
			char md5_hash_tmp[MD5_DIGEST_LENGTH];
			MD5_CTX md5;
			MD5_Init(&md5);
			file_stream.read(file_data, this->file_size);
			MD5_Update(&md5, file_data, file_stream.gcount());
			MD5_Final((unsigned char *)md5_hash_tmp, &md5);
			md5_hash_cache_ = string(md5_hash_tmp);
			delete[] file_data;
		}
	}
	return this->md5_hash_cache_;
}
