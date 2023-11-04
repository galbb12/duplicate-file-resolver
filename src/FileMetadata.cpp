#include "FileMetadata.hpp"

using namespace std;

//@todo change hash generation method
FileMetadata::FileMetadata(filesystem::path _path)
{
	this->path = _path;
	this->file_size = filesystem::file_size(FileMetadata::path);
	this->md5_hash_cache_ = nullptr;
}

unsigned char* FileMetadata::getMd5Hash()
{
	if (this->md5_hash_cache_ == nullptr)
	{
		ifstream file_stream(((string)this->path), ios::in | ios::binary);
		if (file_stream.is_open())
		{
			char *file_data = new char[this->file_size];
			this->md5_hash_cache_ = new unsigned char[MD5_DIGEST_LENGTH];
			MD5_CTX md5;
			MD5_Init(&md5);
			file_stream.read(file_data, this->file_size);
			MD5_Update(&md5, file_data, file_stream.gcount());
			MD5_Final((unsigned char*) this->md5_hash_cache_, &md5);
			delete[] file_data;
			file_stream.close();
		}
	}
	return this->md5_hash_cache_;
}

void FileMetadata::ClearMd5(){
    if(this->md5_hash_cache_ != nullptr){
		delete[] this->md5_hash_cache_;
		this->md5_hash_cache_ = nullptr;
	}
}
