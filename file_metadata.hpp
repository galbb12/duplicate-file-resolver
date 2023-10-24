#include <iostream>
#include <string>
#include <filesystem>
#include <cstdint>

#ifndef FILE_MEADATA_HPP

#define FILE_MEADATA_HPP

using namespace std;

class file_metadata{



  
 
  public:
	 file_metadata(filesystem::path& _path);
	 ~file_metadata();
	 filesystem::path path;
	 int file_size;
	 std::size_t hash_value;
};

#endif
