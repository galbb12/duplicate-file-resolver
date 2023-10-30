#include <iostream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <openssl/md5.h>
#include <cstdio>	

#ifndef FILE_MEADATA_HPP

#define FILE_MEADATA_HPP

using namespace std;

string md5(unsigned char* data,long int size);

class file_metadata{



  
  public:
	 file_metadata(filesystem::path _path);
	 ~file_metadata();
	 string get_md5_hash();
	 filesystem::path path;
	 int file_size;
};

#endif
