#include <iostream>
#include <string>
#include <filesystem>
#include "file_metadata.hpp"

using namespace std;
namespace fs = std::filesystem;

int main(int argc,char* argv[]){
	//root_run_path is the path which the program will start running on it means that the program will run on all sub directories of the directory in the path
	string root_run_path = "";
	if(argc < 2){
	  filesystem::path cwd = filesystem::current_path();
          root_run_path = cwd.string();
	}
	else{
	   root_run_path = argv[1];
	}

        filesystem::path folder_path = fs::path(root_run_path);

        if(!filesystem::exists(folder_path)){
		cout << "The path doesn't exist" << endl;
		return -1;
	}
	cout << "The selected root path is: " << root_run_path << endl;

	cout << "Starting scan..." << endl;
}

void remove_duplicate(filesystem::path folder_path){
	
}
