#include <filesystem>
#include <iostream>

// past argv[0] surely identify specific location
int main(int argc, char* argv[]){ 
    std::filesystem::path exec_path = std::filesystem::canonical(argv[0]);
    std::filesystem::path exec_dir=exec_path.parent_path();

    std::cout<<"Exec location: "<< exec_path<<'\n';
    std::cout<<"Exec directory: "<< exec_dir<<'\n';

}