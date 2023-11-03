#ifndef FILE_MEADATA_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <openssl/md5.h>
#include <cstdio>	
#include <iostream>
#include <fstream>
#include "utils.hpp"
#define FILE_MEADATA_HPP

using namespace std;

class file_metadata{


  string md5_hash_cache;
  public:
	 file_metadata(filesystem::path _path);
	 ~file_metadata();
	 string get_md5_hash();
	 filesystem::path path;
	 int file_size;
};

#endif
