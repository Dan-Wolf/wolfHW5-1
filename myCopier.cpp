/* A program that opens a text file for reading, read its contents line by line and write them into another file.
 * Both file names are provided as command-line arguments.
 * When there are no more lines to read, the application will close both files and exit.
 * The text file should be placed in /home/debian for this to work.
 * The new text file will be placed in /home/debian
 */

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define FILE_PATH "/home/debian"

int main(int argc, char* argv[]){
	if(argc!=3){
		cout << endl;
		cout << "Usage is myCopier name of read file and name of write file" << endl;
		cout << "e.g. myCopier read.txt write.txt" << endl;
		return 2;
	}

	string cmd_read(argv[1]);
	string cmd_write(argv[2]);

	cout << endl;
	cout << "Starting myCopier program" << endl;
	cout << "The current FILE Path is: " << FILE_PATH << endl;
	cout << "The read file name passed in is: " << cmd_read << endl;
	cout << "The write file name passed in is: " << cmd_write << endl;
	cout << endl;

	fstream fs_read, fs_write;
	string line, path(FILE_PATH);

	fs_read.open((path+"/"+cmd_read).c_str(), std::fstream::in);
	fs_write.open((path+"/"+cmd_write).c_str(), std::fstream::out);

	while(getline(fs_read,line)){
		fs_write << line << endl;
	}
	
	fs_read.close();
	fs_write.close();

	cout << "Finished myCopier Program" << endl;
	cout << endl;
	
	return 0;
}

