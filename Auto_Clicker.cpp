#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	cout << "1. Start auto clicker" << endl
		 << "2. Start auto clicker after 5 sec" << endl
		 << "3. Start auto clicker at point" << endl
		 << "4. Get Mouse Pos" << endl;

	int UserInput;
	cin >> UserInput;

	system("cls");
	cout << UserInput << endl;
	if (UserInput == 1 || UserInput == 2)
	{
		if (UserInput == 1)
		{
			cout << "1. Start auto clicker" << endl;
		}
		else
		{
			cout << "2. Start auto clicker after 5 sec" << endl;
			Sleep(5000);
		}

		cout << "press Q to stop" << endl;

		while (!GetAsyncKeyState(0x51))//0x51 = Q
		{
			POINT p;
			GetCursorPos(&p);
			mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
		}

	}
	else if(UserInput == 3)
	{
		POINT p;
		cout << "X: " << endl;
		cin >> p.x;
		system("cls");
		
		cout << "Y: " << endl;
		cin >> p.y;
		system("cls");

		while (!GetAsyncKeyState(0x51))//0x51 = Q
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
		}
	}
	else if(UserInput == 4)
	{
		cout << "press Q to stop" << endl;
		POINT p;

		while (!GetAsyncKeyState(0x51))//0x51 = Q
		{
			GetCursorPos(&p);
			cout << "X: " << p.x << " Y: " << p.y << endl;
			Sleep(1000);
		}
	}
	else
	{
		cout << "Wrong input";

	}
	return 0;
}