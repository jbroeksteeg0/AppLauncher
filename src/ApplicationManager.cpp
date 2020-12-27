#include <filesystem>
#include <iostream>
#include <fstream>
#include "ApplicationManager.h"
#include "Item.h"
#include "Util.h"

// get paths of all files in /usr/share/applications
std::vector<std::string> ApplicationManager::getFiles() {
	std::vector<std::string> res;
	for (auto& curr: std::filesystem::directory_iterator("/usr/share/applications")) {
		res.push_back(curr.path());
	}
	return res;
}

std::pair<std::string,std::string> ApplicationManager::getEntry(std::string inp) {
	std::string before = "", after="";
	bool flag=false;
	for (int i = 0; i < inp.size(); i++) {
		if (inp[i]=='=') {
			flag=true;
		} else {
			(flag ? after : before) += inp[i];
		}
	}
	return std::make_pair(before,after);
}

std::vector<std::string> ApplicationManager::getLines(std::string path) {
	std::ifstream file(path);
	std::string temp;
	std::vector<std::string> res;
	while (std::getline(file, temp)) {
		res.push_back(temp);
	}
	return res;
}

// add items to the window
std::vector<Item*> ApplicationManager::loadItems(std::string query) {
	std::vector<Item*> res;
	for (std::string current: getFiles()) {
		std::string name="",path="",icon="";
		for (std::string option: getLines(current)) {
			if (option[0]=='[' && option != "[Desktop Entry]") break;
			std::pair<std::string,std::string> curr = getEntry(option);
			if (curr.first=="Name") name=curr.second;
			if (curr.first=="Exec") path=curr.second;
			if (curr.first=="Icon") icon=curr.second;
			if (curr.first=="Type"&&curr.second!="Application") break;
		}
		if (name!=""&&path!="") {
			if (endsWith(path, "%u") || endsWith(path,"%U")) {
				path = path.substr(0, path.length()-3);
			}
			std::string execPath = "(" + path + " &)";
			res.push_back(new Item(name,execPath,icon,true,levenschtein(query, name)));
		}
	}
	return res;
}
