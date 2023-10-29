#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "file_metadata.hpp"

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
	vector<file_metadata> vector_of_files;
	for (const fs::path &file : fs::recursive_directory_iterator(folder_path))
	{
		if (!filesystem::is_directory(file))
		{
			file_metadata curr_file = file_metadata(file);
			cout << curr_file.hash_value <<"," << curr_file.path<< endl;
			for (vector<file_metadata>::iterator ptr = vector_of_files.begin(); ptr < vector_of_files.end(); ptr++)
			{
				if ((*ptr).hash_value == curr_file.hash_value)
				{
					cout << file << endl;
				}
			}
			vector_of_files.push_back(file_metadata(file));
		}
	}
}
