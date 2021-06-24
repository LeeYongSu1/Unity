#include "Default.h"

class Girl;
class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len)
	{}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy_s(phNum, sizeof(phNum), num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl&frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}
void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height is: " << frn.height << endl;
}

int main3(void)
{
	Boy boy(170);
	Girl girl("010-123-1234");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}