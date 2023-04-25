#pragma once
#ifdef WINVER
#undef WINVER
#endif // WINVER
#define WINVER 0x500

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。
// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。
#include <SDKDDKVer.h>

#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <tchar.h>

#define IMC_GETOPENSTATUS 0x0005

#pragma comment(lib, "imm32.lib") 
#pragma comment(lib, "User32.lib") 

int getInputMethod() {
    HWND hIME = ImmGetDefaultIMEWnd(GetForegroundWindow());
    LRESULT status = SendMessage(hIME, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0);

    return !!status;
}

void CONTROL_SPACE() {
	INPUT inputs[4] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = VK_CONTROL;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = VK_SPACE;

	inputs[2].type = INPUT_KEYBOARD;
	inputs[2].ki.wVk = VK_SPACE;
	inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

	inputs[3].type = INPUT_KEYBOARD;
	inputs[3].ki.wVk = VK_CONTROL;
	inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void switchInputMethod(int locale) {
	HWND hwnd = GetForegroundWindow();
	LPARAM currentLayout = ((LPARAM)locale);
	PostMessage(hwnd, WM_INPUTLANGCHANGEREQUEST, 0, currentLayout);
}

int main(int argc, char** argv)
{
	if (argc == 1) {
		int imID = getInputMethod();
		printf("%d\n", imID);
	} else {
        if (!!atoi(argv[1]) != getInputMethod()) {
            CONTROL_SPACE();
        }
	}

	return 0;
}
