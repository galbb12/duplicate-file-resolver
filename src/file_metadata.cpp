#include "file_metadata.hpp"

using namespace std;

file_metadata::file_metadata(filesystem::path _path){
	file_metadata::path = _path; 
	file_metadata::file_size = filesystem::file_size(file_metadata::path);
	file_metadata::hash_value = filesystem::hash_value(file_metadata::path);

}



file_metadata::~file_metadata(){
	
}  
