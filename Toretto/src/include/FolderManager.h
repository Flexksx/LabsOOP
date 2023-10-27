#ifndef FOLDER_MANAGER_H
#define FOLDER_MANAGER_H

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class FolderManager {
private:
    fs::path path;
public:
    FolderManager(fs::path _path);
    void listAllFiles(fs:: path, int depth); // Updated function signature
    void listAllFiles();
    fs::path getPath();
};

#endif
