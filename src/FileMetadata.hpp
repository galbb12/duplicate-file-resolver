#ifndef FILE_MEADATA_HPP

#include <openssl/md5.h>

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#define FILE_MEADATA_HPP
#define CRC_READ_SIZE 100

using namespace std;

class FileMetadata
{
private:
	string md5_hash_cache_;
	string md5_crc_cache_;

public:
	FileMetadata(filesystem::path _path);
	string &getMd5Hash();
	string &getCrc();
	filesystem::path path;
	long int file_size;
};

#endif
