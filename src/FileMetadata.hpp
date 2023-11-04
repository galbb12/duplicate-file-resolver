#ifndef FILE_MEADATA_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <openssl/md5.h>
#include <cstdio>	
#include <iostream>
#include <fstream>
#define FILE_MEADATA_HPP

using namespace std;

class FileMetadata{
  private:
     string md5_hash_cache_;
  public:
	 FileMetadata(filesystem::path _path);
	 ~FileMetadata();
	 string getMd5Hash();
	 filesystem::path path;
	 int file_size;
};

#endif
