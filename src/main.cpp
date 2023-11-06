#include <filesystem>
#include <iostream>
#include <string>
#include <map>
#include <map>
#include <vector>

#include "DuplicateFilesCollection.hpp"

using namespace std;
namespace fs = std::filesystem;
void remove_duplicate(filesystem::path folder_path);

int main(int argc, char *argv[])
{
	// root_run_path is the path which the program will start running on it means
	// that the program will run on all sub directories of the directory in the
	// path
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
	 map<long int, map<string, DuplicateFileCollection>>
		*umapSize = new map<long int, map<string, DuplicateFileCollection>>();
	// map<string, DuplicateFileCollection> *umapCrc = new ;
	for (const fs::path &file : fs::recursive_directory_iterator(folder_path))
	{
		if (filesystem::is_regular_file(file))
		{
			FileMetadata curr_file(file);
			if (true)
			{
				map<string, DuplicateFileCollection> umapCrc;
				if (umapSize->contains(curr_file.file_size))
				{
					map<string, DuplicateFileCollection> umapCrc = umapSize->at(curr_file.file_size);
					if (umapCrc.contains(curr_file.getCrc()) &&
						umapCrc.at(curr_file.getCrc()).hash == curr_file.getMd5Hash())
					{
						umapCrc.at(curr_file.getCrc()).file_list.push_back(curr_file);
					}
					else
					{
						umapCrc.emplace(curr_file.getCrc(),
										DuplicateFileCollection(curr_file));
						duplicate_count++;
					}
				}
				else
				{
					map<string, DuplicateFileCollection> umapCrc;
					umapCrc.emplace(curr_file.getCrc(),
									DuplicateFileCollection(curr_file));
					umapSize->emplace(curr_file.file_size,umapCrc);
					duplicate_count++;
				}
				cout << "file count: " << file_count
					 << ", duplicate_filterd_count: " << duplicate_count << endl;
				file_count++;
			}
		}
	}
	delete umapSize;
	cout << endl;
}
