#include "DuplicateFilesCollection.hpp"

using namespace std;

DuplicateFileCollection::DuplicateFileCollection(
    FileMetadata &init_file_metadata)
{
    this->file_size = init_file_metadata.file_size;
    this->hash = init_file_metadata.getMd5Hash();
    this->crc = init_file_metadata.getMd5Hash();
    this->file_list.push_back(init_file_metadata);
}

int DuplicateFileCollection::processFile(FileMetadata &file_metadata)
{
    if (file_metadata.file_size == this->file_size &&
        !file_metadata.getMd5Hash().empty() &&
        file_metadata.getMd5Hash() == this->file_list.at(0).getMd5Hash())
    {
        this->file_list.push_back(file_metadata);
        return 1;
    }
    return 0;
}