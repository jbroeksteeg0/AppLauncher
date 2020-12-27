#include "Util.h"
#include <vector>
#include <algorithm>

bool startsWith(std::string a, std::string b) {
	if (a.length()<b.length()) return false;
	for (int i = 0; i < b.size(); i++) {
		if (a[i]!=b[i]) return false;
	}
	return true;
}

bool endsWith(std::string a, std::string b) {
	if (a.length()<b.length()) return false;
	for (int i = 0; i < b.size(); i++) {
		if (a[a.length() - b.length() + i]!=b[i]) return false;
	}
	return true;
}

std::string removeSpaces(std::string s) {
	std::string ret="";
	for (char ch: s) {
		if (ch!=' ') {
			ret+=ch;
		}
	}
	return ret;
}
int levenschtein(std::string a, std::string b) {
	a=" "+removeSpaces(a);
	b=" "+removeSpaces(b);

	for (char& ch: a) {
		if (ch>='A'&&ch<='Z') {
			ch+='a'-'A';
		}
	}
	for (char& ch: b) {
		if (ch>='A'&&ch<='Z') {
			ch+='a'-'A';
		}
	}
	std::vector<std::vector<int>> dp(a.size(),std::vector<int>(b.size(),1e9));
	for (int i = 0; i < a.size(); i++) dp[i][0]=i;
	for (int i = 0; i < b.size(); i++) dp[0][i]=i;

	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			dp[i][j] = std::min<int>({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
			if (a[i]==b[j]) {
				dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]);
			}
		}
	}
	if (startsWith(b,a)) {
		float percent = (float)a.length()/b.length();
		percent*=0.5f;
		dp[a.size()-1][b.size()-1]*=percent;
	}
	return dp[a.size()-1][b.size()-1];
}

