#include "FileHandler.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

FileHandler::FileHandler(const std::string &filename, const std::string &s1, const std::string &s2) : _filename(filename), _s1(s1), _s2(s2) {
}


bool FileHandler::replaceAndSave(){

	// abrir o arquivo
	std::ifstream inputFile(_filename.c_str());
	if(!inputFile.is_open()){
		std::cerr << "Error opening file " << _filename << std::endl;
		return false;
	}

	// ler o conteúdo do arquivo

	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string content = buffer.str();
	inputFile.close();

	// substituir as ocorrências de s1 por s2
	std::string newContent = _replaceOccurences(content);

	//criar arquivo de saída
	std::ofstream outputFile((_filename + ".replace").c_str());
	if(!outputFile.is_open()){
		std::cerr << "Error creating file " << _filename << ".replace" << std::endl;
		return false;
	}

	//escrever o novo conteúdo no arquivo de saída
	outputFile << newContent;
	outputFile.close();
	return true;
}

FileHandler::~FileHandler() {}

std::string FileHandler::_replaceOccurences(const std::string &content) const {
	std::string newContent = content;
	size_t pos = 0;
	while((pos = newContent.find(_s1, pos)) != std::string::npos){
		newContent.erase(pos, _s1.length());
		newContent.insert(pos, _s2);
		pos += _s2.length();
	}
	return newContent;
}
