#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int main()
{
    try
    {

        std::fstream read;
        read.open("file.txt", std::ios::ate|std::ios::app|std::ios::binary);
        if (!read.is_open())
        {
            throw std::runtime_error("Open error");
            return 1;
        }
        std::string stream;
        std::stringstream ss("Hello world\n");
        // read.seekg(0); // for writing at pos start
        // std::getline(read, stream,'\n');
        // read.write(ss.str().c_str(),sizeof(ss.str().c_str())); // c_string specific byte write
        std::streamsize size = read.tellg();
        std::cout << size<<'\n';
        read.close();
    }
    catch (std::runtime_error e)
    {
        std::cerr << e.what();
    }
}