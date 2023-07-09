#ifndef USER_HPP
#define USER_HPP

#include "Defines.hpp"
#include "Channel.hpp"

class Server;

class User {
   public:
	User();
	User(int inputFd, std::string name);
	~User();
	void setUserName(std::string uName);
	void setNickName(std::string nName);
	void connectUser(bool isConnected);
	bool isConnected();
	std::string getUserName();
	std::string getNickName();
	int getUserFd();

	// CHANNELS
	std::map<std::string, bool> channels;

	//COMMAND TO EXECUTE
	void message();
	void joinChannel();
	void leaveChannel();
	void kick();
	void invite();
	void quitServer();
	void setNick(std::map<int, User>::iterator it, std::string newNickname);
	void listChannels();
	void modeUser();
	void modeOper();
	void topicUser();
	void topicOper();
	void emptyFunction();

   private:
	std::string userName;
	std::string nickName;
	bool connected;
	int userFd;
};

#endif