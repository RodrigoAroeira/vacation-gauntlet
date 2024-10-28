// failed compiles:
// failed runs:
// time taken:

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>

#define KEY 4

std::string encrypt(const std::string &str) {
  std::string newStr;
  for (const char c : str) {
    newStr += c + KEY;
  }
  return newStr;
}

std::string decrypt(const std::string &str) {
  std::string newStr;

  for (const char c : str) {
    newStr += c - KEY;
  }
  return newStr;
}

std::vector<std::string> getFileLines(const std::string nomeArq) {
  std::ifstream arquivo(nomeArq);
  if (!arquivo.is_open())
    exit(1);

  std::vector<std::string> linhas;
  std::string linha;
  while (std::getline(arquivo, linha))
    linhas.push_back(linha);

  return linhas;
}

void encryptFile(const std::string nomeArq) {

  std::vector<std::string> linhas = getFileLines(nomeArq);

  std::ofstream arquivo(nomeArq);

  for (const auto &linha : linhas)
    arquivo << encrypt(linha) << std::endl;

  arquivo.close();
}

void decryptFile(const std::string nomeArq) {

  std::vector<std::string> linhas = getFileLines(nomeArq);

  std::ofstream arquivo(nomeArq);

  for (const auto &linha : linhas)
    arquivo << decrypt(linha) << std::endl;

  arquivo.close();
}

std::vector<std::string> getDirFiles(const std::string &path) {

  std::vector<std::string> files;

  try {

    for (const auto &entry : std::filesystem::directory_iterator(path)) {
      if (entry.is_regular_file() &&
          entry.path().filename().string()[0] != '.') {
        files.push_back(entry.path().filename().string());
      }
    }

  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Error opening directory: " << e.what() << std::endl;
  }

  return files;
}

int main() {

  std::vector<std::string> files = getDirFiles(".");
  int index = 1;

  int fileOpt, opOpt;

  std::vector operations = {encryptFile, decryptFile};

  std::cout << "Files in directory:\n";

  for (const auto &file : files) {
    std::cout << index++ << " - " + file << std::endl;
  }

  std::cout << "Digite o numero do arquivo que deseja manipular: ";
  std::cin >> fileOpt;

  std::cout << "Digite a operação desejada: " << std::endl;
  std::cout << "1 - Encriptar" << std::endl;
  std::cout << "2 - Decriptar" << std::endl;
  std::cout << "> ";
  std::cin >> opOpt;

  try {
    auto arq = files.at(fileOpt - 1);
    auto operation = operations.at(opOpt - 1);

    operation(arq);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
