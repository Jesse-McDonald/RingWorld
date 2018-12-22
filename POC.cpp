// proof of concept basic application
//

//#include "stdafx.h"
//#include "winuser.h"
#include "windows.h"
#include <iostream>

int main()
{
	using namespace std;
	POINT pPos= POINT();
	pPos.x = 0;
	pPos.y = 0;
	POINT pos = POINT();
	int dX=0, dY=0;
	
	while (true) {
		
		//cout <<(unsigned short) GetKeyState(VK_LBUTTON) << endl;
		GetCursorPos(&pos);
		//if (pos.x - pPos.x != 0 && pos.y - pPos.y != 0) {
		//std::cout << "(" << pos.x - pPos.x << "," << pos.y - pPos.y << ")" << std::endl;
		//std::cout << "(" << pos.x << "," << pos.y<< ")" << std::endl;
		//}
		dX = (dX / 2) + abs(pos.x - pPos.x);
		dY = (dY / 2) + abs(pos.y - pPos.y);
//std::cout << "(" << dX << "," << dY<< ")" << std::endl;
		//}
		if (abs(pos.x - pPos.x) > 0&& abs(pos.x - pPos.x)<1000) {


			if (!(//these conditions will mandate edge cling
				(GetKeyState(VK_LBUTTON) < 00)//mouse button is pressed, like if we are draging a window
				||(dY!=0 && dX/(float)dY<1)//mouse moving at more that a 45* angle (probiably moving to a corner not edge)
				)
				&& dX>1) {//only "blink" if we have momentiom //change to using mouse raw
				if (pos.x <= -1280) {
					SetCursorPos(3199, pos.y);
				}
				else if (pos.x >= 3199) {
					SetCursorPos(-1280, pos.y);

				}
			}
		}
		pPos = pos;
	}

	//SetCursorPos(0, 0);
    return 0;
}

