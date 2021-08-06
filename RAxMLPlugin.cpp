#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "RAxMLPlugin.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void RAxMLPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
 
}

void RAxMLPlugin::run() {
   
}

void RAxMLPlugin::output(std::string file) {
//./raxmlHPC -s input.ffn -n coregenome.tre -m GTRCAT -p 1234
char cwd[PATH_MAX];
   getcwd(cwd, sizeof(cwd));
   std::string command = "rm "+std::string(PluginManager::prefix())+"/*.tre >& /dev/null; raxmlHPC ";
 command += "-s "+std::string(PluginManager::prefix())+"/"+parameters["inputfile"];
 command += " -n "+file.substr(file.find_last_of("/")+1);
 command += " -m "+parameters["model"];
 command += " -p "+parameters["seed"]+" ";
 command += " -w "+std::string(cwd)+"/"+std::string(PluginManager::prefix());
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<RAxMLPlugin> RAxMLPluginProxy = PluginProxy<RAxMLPlugin>("RAxML", PluginManager::getInstance());
