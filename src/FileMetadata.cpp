#include "FileMetadata.hpp"

using namespace std;

//@todo change hash generation method
FileMetadata::FileMetadata(filesystem::path _path)
{
	this->path = _path;
	this->file_size = filesystem::file_size(FileMetadata::path);
	this->md5_hash_cache_ = "";
}

string FileMetadata::getMd5Hash()
{
	if (this->md5_hash_cache_.empty())
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

			std::stringstream md5_string_stream;

			for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
			{
				md5_string_stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
			}
			string md5_string = md5_string_stream.str();
			this->md5_hash_cache_ = md5_string;
			
			delete[] file_data;
			file_stream.close();
		}
	}
	return this->md5_hash_cache_;
}

FileMetadata::~FileMetadata()
{
}
