#include <time.h>
#include "SystemManager.h"
#include "Util.h"

std::string SystemManager::getDateString() {
	time_t unixTime = time(NULL);
	struct tm *currTime = localtime(&unixTime);

	std::string res = days[currTime->tm_wday];
	res += ", ";
	res += std::to_string(currTime->tm_mday) + "/";
	res += std::to_string(currTime->tm_mon+1) + "/";
	res += std::to_string(currTime->tm_year+1900);

	return res;
}

std::vector<Item*> SystemManager::loadItems(std::string query) {
	std::vector<Item*> res;

	// shell command
	if (startsWith(query, "x ") && query != "x ") {
		std::string command = query.substr(2,query.length()-2);
		res.push_back(new Item("Run '" + command + "'", command, "",true,-1));
	}

	// other options
	res.push_back(new Item("Shutdown","shutdown -h now", "system-shutdown", true, levenschtein(query, "shutdown")));
	res.push_back(new Item("Reboot","reboot", "system-reboot", true, levenschtein(query, "reboot")));
	res.push_back(new Item("Lock Screen", "loginctl lock-session", "system-lock-screen", true, levenschtein(query, "Lock screen")));
	
	res.push_back(new Item("Date: "+ getDateString(), "","clock",false, levenschtein(query,"Date")));
	return res;
}
