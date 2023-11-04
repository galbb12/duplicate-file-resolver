#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "DuplicateFilesCollection.hpp"

using namespace std;
namespace fs = std::filesystem;
void remove_duplicate(filesystem::path folder_path);

int main(int argc, char *argv[])
{
	// root_run_path is the path which the program will start running on it means that the program will run on all sub directories of the directory in the path
	string root_run_path = "";
	if (argc < 2)
	{
		filesystem::path cwd = filesystem::current_path();
		root_run_path = cwd.string();
	}
	else
	{
		root_run_path = argv[1];
	}

	filesystem::path folder_path = fs::path(root_run_path);

	if (!filesystem::exists(folder_path))
	{
		cout << "The path: " << root_run_path << "doesn't exist" << endl;
		return -1;
	}
	cout << "The selected root path is: " << root_run_path << endl;

	cout << "Starting scan..." << endl;

	remove_duplicate(folder_path);
}

void remove_duplicate(filesystem::path folder_path)
{
	long int file_count = 0;
	long int duplicate_count = 0;
	vector<DuplicateFileCollection> vector_of_files_collections;
	for (const fs::path &file : fs::recursive_directory_iterator(folder_path))
	{
		if (filesystem::is_regular_file(file))
		{
			FileMetadata curr_file(file);
			int found_duplicate_flag = 0;
			for (vector<DuplicateFileCollection>::iterator ptr = vector_of_files_collections.begin(); ptr < vector_of_files_collections.end(); ptr++)
			{
				if (ptr->processFile(curr_file))
				{
					found_duplicate_flag = 1;
					//cout << "found duplicate: " << curr_file.path << " " << ptr->file_list.at(0).path << endl;
					duplicate_count++;
					break;
				}
			}
			if(!found_duplicate_flag){
				vector_of_files_collections.push_back(DuplicateFileCollection(curr_file));
				cout << "\rfile count: " << file_count << ", duplicate_filterd_count: " << vector_of_files_collections.size();
			}
			file_count++;
		}
	}
	cout << endl;
}
