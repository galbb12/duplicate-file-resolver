#include <vector>
#include <filesystem>
#include <string>
#include <vector>
#include "FileMetadata.hpp"

using namespace std;

class DuplicateFileCollection{
    public:
     DuplicateFileCollection(FileMetadata init_file_metadata);
     string hash;
     long int file_size;
     vector<FileMetadata> file_list;
     int processFile(FileMetadata file_metadata);
};