//============================================================================
// Name        : CrackKey.cpp
// Author      : KansasMyers
// Version     : 6.6.6
// Copyright   : FREEWARE
//============================================================================
#include <windows.h>

int main() {
	HWND hWnd = FindWindow(0, "Validar Key");

	if (hWnd == 0) {
		MessageBox(0, "A janela a ser crackeada não foi encontrada.", "Erro",
		MB_OK | MB_ICONERROR);
	} else {
		DWORD proccess_ID;
		GetWindowThreadProcessId(hWnd, &proccess_ID);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
		if (!hProcess) {
			MessageBox(0, "Não foi possível abrir o processo do software.", "Erro",
			MB_OK | MB_ICONERROR);
		} else {
			BYTE crackTheBytes[2] = { 0x75, 0x0C };
			if (WriteProcessMemory(hProcess, (LPVOID) 0x00453805, &crackTheBytes, 2,
			NULL)) {
				MessageBox(NULL, "Crackeado com sucesso :D", "Wassup my boyz",
				MB_OK + MB_ICONINFORMATION);
			} else {
				MessageBox(NULL, "Não foi possível crackear o software :/", ";---;",
				MB_OK + MB_ICONERROR);
			}
			CloseHandle(hProcess);
		}
	}
	return 0;
}
