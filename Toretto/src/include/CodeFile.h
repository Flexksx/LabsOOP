#ifndef CODE_FILE_MANAGER_H
#define CODE_FILE_MANAGER_H

#include "GenericFile.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class CodeFile : public GenericFile {
protected:
  std::string fileExtension;
public:
  CodeFile(std::string _filePath, int* date);
  std::string getFileExtension();
  int getNrOfLines();
  void showInfo() override;
  CodeFile(int* date);
  virtual int getNrOfClasses();
  bool isCodeFileExtension();
};

#endif