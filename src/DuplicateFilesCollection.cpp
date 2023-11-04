#include "DuplicateFilesCollection.hpp"

using namespace std;

DuplicateFileCollection::DuplicateFileCollection(FileMetadata& init_file_metadata){
    this->file_size = init_file_metadata.file_size;
    this->hash = "";
    this->file_list.push_back(init_file_metadata);
}


void DuplicateFileCollection::clear(){
    for(int i = 0; i < this->file_list.size();i++){
        this->file_list[i].ClearMd5();
    }
}

int DuplicateFileCollection::processFile(FileMetadata& file_metadata){
    if(file_metadata.file_size == this->file_size && memcmp(file_metadata.getMd5Hash(),this->file_list.at(0).getMd5Hash(),MD5_DIGEST_LENGTH*sizeof(unsigned char)) == 0){
        this->file_list.push_back(file_metadata);
        return 1;
    }
    file_metadata.ClearMd5();
    return 0;
}