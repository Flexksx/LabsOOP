#include "src/include/CodeFile.h"
#include "src/include/Commander.h"
#include "src/include/Folder.h"
#include "src/include/GenericFile.h"
#include "src/include/ImageFile.h"
#include "src/include/Stater.h"
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  int *date = new int[6];
  Folder *fm = new Folder();
  GenericFile *gfm = new GenericFile(date);
  ImageFile *ifm = new ImageFile(date);
  CodeFile *cfm = new CodeFile(date);
  Stater *st = new Stater(date, "log.txt", gfm, ifm, cfm, fm);
  Commander *comm = new Commander(date, fm, st, gfm, cfm, ifm);
  if (argc == 2) {
    std::string command = argv[1];
    if (command == "run") {
      comm->run();
    } else if (command == "listall") {
      st->listRettos();
    } else {
      comm->giveCommand(command);
      comm->run(command);
    }
  } else if (argc == 3) {
    std::string command = argv[1];
    if (command == "info") {
      if (fs::exists(argv[2])) {
        comm->sl(argv[2]);
        comm->info();
      } else {
        std::cout << "Path does not exist." << std::endl;
        // TODO: make function for retto info
      }
    }
    if (command == "init") {
      std::string name;
      std::cout << "Give a name to this Rettository: ";
      std::string rettoName;
      std::cin >> rettoName;
      comm->sl(argv[2]);
      comm->init(rettoName);
    }
    if (command == "commit") {
      std::string rettoName = argv[2];
      comm->commit(rettoName);
    }
  } else if (argc == 4) {
    std::string command = argv[1];
    std::string path = argv[2];
    std::string name = argv[3];
    if (command == "init") {
      comm->sl(path);
      comm->init(name);
    }
  }
}

// {
//   if (argc == 2) {
//     Commander cmd = Commander(argv[1]);
//     cmd.run();
//   } else {

//     int *date = new int[5];
//     fs::path path = argv[2];
//     while (!fs::exists(path)) {
//       cout << "Path does not exist. Please enter a valid path: (Main)";
//       cin >> path;
//     }
//     string command = argv[1];
//     fs::path logFile = "log.txt";
//     Folder *fm = new Folder(path);
//     GenericFile *gfm = new GenericFile(date);
//     ImageFile *ifm = new ImageFile(date);
//     CodeFile *cfm = new CodeFile(date);
//     Stater *stater = new Stater(date, logFile, gfm, ifm, cfm, fm);
//     stater->readRettos();
//     Commander commander(command, date, fm, stater, gfm, cfm, ifm);
//     std::cout << "Hello, welcome to Toretto file state manager!" <<
//     std::endl; commander.run(); commander.run("help"); while (cin >>
//     command)
//     {
//       commander.run(command);
//     }
//     delete fm;
//     delete ifm;
//     delete cfm;
//     delete gfm;
//     delete[] date;
//   }
//   return 0;
// }
