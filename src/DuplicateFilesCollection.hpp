#include <vector>
#include <filesystem>
#include <vector>
#include <cstring>
#include "FileMetadata.hpp"

using namespace std;

class DuplicateFileCollection{
    public:
     DuplicateFileCollection(FileMetadata& init_file_metadata);
     void clear();
     string hash;
     long int file_size;
     vector<FileMetadata> file_list;
     int processFile(FileMetadata& file_metadata);
};