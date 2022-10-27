# include <iostream>
# include "tv.h"

int main1()
{
	using namespace std;
	Tv s42;//off,2
	cout << "Initial setting for 42 \" TV:\n";
	s42.settings();//display
	s42.onoff();//on
	s42.chanup();//3
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.chanup();//4
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();//on,5,4,cable,TV
	
	Remote grey;

	grey.set_chan(s42, 10);//10
	grey.volup(s42);//6
	grey.volup(s42);//7
	cout << "\n42\"settings after using remotr: \n";
	s42.settings();//on,10,7,cable,TV

	Tv s58(Tv::On);//枚举引用加域限定符
	s58.set_mode();//变换模式
	grey.set_chan(s58, 28);
	cout << "\n58\"setings:\n";
	s58.settings();
	system("pause");
	return 0;

}