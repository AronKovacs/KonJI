#include <windows.h> /* for HANDLE type, and console functions */
#include <conio.h>
#include <stdlib.h> /* included for rand */
#include <time.h>

#include <errno.h>
#include <string.h>

#include "window.h"
#include "entity.h"
#include "sprite.h"
<<<<<<< HEAD
#include "lists.h"

//int main()
//{
	//srand(time(0));
=======
#include "utilities.h"
>>>>>>> origin/master

	//struct KonJIWindow* window = createKonJIWindow("KonJI", 80, 30);

<<<<<<< HEAD
	//clearConsoleBuffer(window);
=======
	struct Entity* entities;
};


int main()
{
	//srand(time(0));

	struct KonJIWindow* window = createKonJIWindow("KonJI", 80, 30);

	clearConsoleBuffer(window);
>>>>>>> origin/master
	
	/*struct Sprite sprite;
	sprite.w = 3;
	sprite.h = 2;
	sprite.bitmap = malloc(6*sizeof(CHAR_INFO));

	sprite.bitmap[0].Char.AsciiChar = 'A';
	sprite.bitmap[0].Attributes = 100;

	sprite.bitmap[1].Char.AsciiChar = 'B';
	sprite.bitmap[1].Attributes = 71;

	sprite.bitmap[2].Char.AsciiChar = 'C';
	sprite.bitmap[2].Attributes = 58;

	sprite.bitmap[3].Char.AsciiChar = 'D';
	sprite.bitmap[3].Attributes = 200;

	sprite.bitmap[4].Char.AsciiChar = 'E';
	sprite.bitmap[4].Attributes = 143;

	sprite.bitmap[5].Char.AsciiChar = 'F';
	sprite.bitmap[5].Attributes = 43;
	
	writeSprite(&sprite, "data/test01.txt");
	*/
	//struct Sprite* sprite = loadSprite("data/churchill.txt");
	//sprite->x = 15;
	//sprite->y = 3;
	//drawSprite(window, sprite, 15, 3);
	//setPixel2c(window, 3, 5, 'A', 100);
<<<<<<< HEAD
	//while (1) {
	//	drawKonJIWindow(window);
	//}

	//getchar();
	/*struct Entity* e1 = malloc(sizeof(struct Entity));
	e1->x = 1;

	struct Entity* e2 = malloc(sizeof(struct Entity));
	e2->x = 2;

	struct Entity* e3 = malloc(sizeof(struct Entity));
	e3->x = 3;


	struct ListNode* l1 = create_ListNode_Entity(e1);

	struct ListNode* l2 = create_ListNode_Entity(e2);

	struct ListNode* l3 = create_ListNode_Entity(e3);

	l1 = push_ListNode_Entity(l1, e3);
	printf("%d %d\n", l1->entity->x, l1->next->entity->x);

	l1 = swap_ListNode_Entity(l1, 0, 1);
	printf("%d %d\n", l1->entity->x, l1->next->entity->x);

//	l1 = insert_ListNode_Entity(l1, e2, 1);
//	printf("%d %d %d\n", l1->entity->x, l1->next->entity->x, l1->next->next->entity->x);
	*/
//	scanf("");
//}
#include "palette.h"

/******************************************************************************
  main

  Creates a palette with the default colors and changes font size.
******************************************************************************/
int main(void)
{
    /* Setting the color palette to the default colors
    /* Browse MSDN for COLORREF to learn more about these RGB values */
  COLORREF palette[16] = 
  {
	  0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	  0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	  0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff,
	  0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000
  };
    /* Search MSDN for the RGB macro to easily generate COLORREF values */

  SetConsolePalette(palette, 8, 8, L"");
  srand(time(0));

  struct KonJIWindow* window = createKonJIWindow("KonJI", 80, 50);

  clearConsoleBuffer(window);

  /*struct Sprite sprite;
  sprite.w = 3;
  sprite.h = 2;
  sprite.bitmap = malloc(6*sizeof(CHAR_INFO));

  sprite.bitmap[0].Char.AsciiChar = 'A';
  sprite.bitmap[0].Attributes = 100;

  sprite.bitmap[1].Char.AsciiChar = 'B';
  sprite.bitmap[1].Attributes = 71;

  sprite.bitmap[2].Char.AsciiChar = 'C';
  sprite.bitmap[2].Attributes = 58;

  sprite.bitmap[3].Char.AsciiChar = 'D';
  sprite.bitmap[3].Attributes = 200;

  sprite.bitmap[4].Char.AsciiChar = 'E';
  sprite.bitmap[4].Attributes = 143;

  sprite.bitmap[5].Char.AsciiChar = 'F';
  sprite.bitmap[5].Attributes = 43;

  writeSprite(&sprite, "data/test01.txt");
  */
  struct Sprite* sprite = loadSprite("data/hitler_white.kgf");
//  sprite->x = 15;
  //sprite->y = 3;
  drawSprite(window, sprite, 15, 15);
 // setPixel2c(window, 3, 15, 'A', 100);
  while (1) {
  	drawKonJIWindow(window);
  }

  //getchar();
  /*struct Entity* e1 = malloc(sizeof(struct Entity));
  e1->x = 1;

  struct Entity* e2 = malloc(sizeof(struct Entity));
  e2->x = 2;

  struct Entity* e3 = malloc(sizeof(struct Entity));
  e3->x = 3;


  struct ListNode* l1 = create_ListNode_Entity(e1);

  struct ListNode* l2 = create_ListNode_Entity(e2);

  struct ListNode* l3 = create_ListNode_Entity(e3);

  l1 = push_ListNode_Entity(l1, e3);
  printf("%d %d\n", l1->entity->x, l1->next->entity->x);

  l1 = swap_ListNode_Entity(l1, 0, 1);
  printf("%d %d\n", l1->entity->x, l1->next->entity->x);

  //	l1 = insert_ListNode_Entity(l1, e2, 1);
  //	printf("%d %d %d\n", l1->entity->x, l1->next->entity->x, l1->next->next->entity->x);
  */
  	scanf("");
 /* printf("Small default font.\n");
  Sleep(2000);
  
  SetConsolePalette(palette, 1, 2, L"Lucida Console");
  printf("Too tiny to read Lucida!\n");
  Sleep(2000);
  
  if (windowsVersionTest())
  {
    SetConsolePalette(palette, 8, 12, L"Consolas");
    printf("More of a normal Consolas size.\n");
  }
  else
  {
    SetConsolePalette(palette, 8, 12, L"Lucidas");
    printf("More of a normal Lucidas size.\n");
  }
  Sleep(2000);
  
  SetConsolePalette(palette, 43, 72, L"Lucida Console");
  printf("Huge Lucida!\n");
  
  getchar();*/

  return 0;
}


/******************************************************************************
windowsVersionTest

Checks to see if have Vista/7 or earlier by attempting to retrieve function
from kernel32.dll that is only available in Vista+ version of Windows.
******************************************************************************/
int windowsVersionTest(void)
{
	/* Retrieving pointers for Windows Vista/7 Functions */
	PGetCurrentConsoleFontEx pGetCurrentConsoleFontEx = (PGetCurrentConsoleFontEx)
		GetProcAddress(GetModuleHandle("kernel32.dll"), "GetCurrentConsoleFontEx");

	/* If exists then we have Vita/7 */
	if (pGetCurrentConsoleFontEx)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/******************************************************************************
SetConsolePalette

Sets the console palette and font size.
******************************************************************************/
VOID WINAPI SetConsolePalette(COLORREF palette[], int fontX, int fontY, wchar_t *fontName)
{
	int i;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	/* Retrieving pointers for Windows Vista/7 Functions */
	PGetCurrentConsoleFontEx pGetCurrentConsoleFontEx = (PGetCurrentConsoleFontEx)
		GetProcAddress(GetModuleHandle("kernel32.dll"), "GetCurrentConsoleFontEx");
	PSetCurrentConsoleFontEx pSetCurrentConsoleFontEx = (PSetCurrentConsoleFontEx)
		GetProcAddress(GetModuleHandle("kernel32.dll"), "SetCurrentConsoleFontEx");
	PGetConsoleScreenBufferInfoEx pGetConsoleScreenBufferInfoEx = (PGetConsoleScreenBufferInfoEx)
		GetProcAddress(GetModuleHandle("kernel32.dll"), "GetConsoleScreenBufferInfoEx");
	PSetConsoleScreenBufferInfoEx pSetConsoleScreenBufferInfoEx = (PSetConsoleScreenBufferInfoEx)
		GetProcAddress(GetModuleHandle("kernel32.dll"), "SetConsoleScreenBufferInfoEx");

	/* Check for pointers: if they exist, we have Vista/7 and we can use them */
	if (pGetCurrentConsoleFontEx && pSetCurrentConsoleFontEx &&
		pGetConsoleScreenBufferInfoEx && pSetConsoleScreenBufferInfoEx)
	{
		CONSOLE_SCREEN_BUFFER_INFOEX cbi;
		CONSOLE_FONT_INFOEX cfi = { sizeof(CONSOLE_FONT_INFOEX) };

		/* Tell the font info how big it is, to avoid memory corruption */
		cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		pGetCurrentConsoleFontEx(hOutput, TRUE, &cfi);

		/* Set the font type to name indicated by wide string literal */
		/* Set to 0 to keep current settings */
		lstrcpyW(cfi.FaceName, fontName);
		cfi.dwFontSize.X = fontX;
		cfi.dwFontSize.Y = fontY;
		cfi.FontFamily = 0; /* Set to 0x30 for Terminal font */
		cfi.FontWeight = 0;

		/* Set the console font info */
		pSetCurrentConsoleFontEx(hOutput, TRUE, &cfi);

		/* Get the size of the structure before filling the struct */
		cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		pGetConsoleScreenBufferInfoEx(hOutput, &cbi);

		/* Loop through the given palette, copying the data into the color table */
		for (i = 0; i < 16; ++i)
		{
			cbi.ColorTable[i] = palette[i];
		}

		/* Set the console screen buffer info */
		pSetConsoleScreenBufferInfoEx(hOutput, &cbi);
	}
	else  /* We don't have access to the vista functions */
	{
		int i;
		CONSOLE_INFO ci = { sizeof(ci) };
		HWND hwndConsole = GetConsoleWindow();

		GetConsoleSizeInfo(&ci, hOutput);

		/* Set to 0 to keep current settings */
		ci.FontSize.X = fontX;
		ci.FontSize.Y = fontY;
		ci.FontFamily = 0; /* Set to 0x30 for Terminal font */
		ci.FontWeight = 0;

		lstrcpyW(ci.FaceName, fontName);
		ci.CursorSize = 100;
		ci.FullScreen = FALSE;
		ci.QuickEdit = FALSE;
		ci.AutoPosition = 0x10000;
		ci.InsertMode = TRUE;
		ci.ScreenColors = MAKEWORD(0x7, 0x0);
		ci.PopupColors = MAKEWORD(0x5, 0xf);
		ci.HistoryNoDup = TRUE;
		ci.HistoryBufferSize = 50;
		ci.NumberOfHistoryBuffers = 4;

		for (i = 0; i < 16; i++)
		{
			ci.ColorTable[i] = palette[i];
		}

		ci.CodePage = 0;
		ci.Hwnd = hwndConsole;
		lstrcpyW(ci.ConsoleTitle, L"");

		SetConsoleInfo(hwndConsole, &ci);
	}
=======

	double previous = getCurrentTime();
	double lag = 0.0;
	while (1)
	{
		double current = getCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		// process input
		if (_kbhit()) {
			char c = _getch();

			if (c == 'x') {
				break;
			}
		}

		while (lag >= 16.666666666666668)
		{
			//update();
			lag -= 16.666666666666668;
		}

		drawKonJIWindow(window);
	}
>>>>>>> origin/master
}

/******************************************************************************
GetConsoleSizeInfo (XP only)

Fills up some info about the console font in the CONSOLE_INFO struct.
******************************************************************************/
static void GetConsoleSizeInfo(CONSOLE_INFO *pci, HANDLE hOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hOutput, &csbi);
	pci->ScreenBufferSize = csbi.dwSize;
	pci->WindowSize.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	pci->WindowSize.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	pci->WindowPosX = csbi.srWindow.Left;
	pci->WindowPosY = csbi.srWindow.Top;
}

/******************************************************************************
SetConsoleInfo (XP only)

Ends up sending a message to windows to reset the console info.
******************************************************************************/
BOOL SetConsoleInfo(HWND hwndConsole, CONSOLE_INFO *pci)
{
	DWORD dwConsoleOwnerPid;
	HANDLE hProcess;
	HANDLE hSection, hDupSection;
	PVOID ptrView = 0;
	HANDLE hThread;

	/* Open the process which "owns" the console */
	GetWindowThreadProcessId(hwndConsole, &dwConsoleOwnerPid);
	hProcess = OpenProcess(MAXIMUM_ALLOWED, FALSE, dwConsoleOwnerPid);


	/* Create a SECTION object backed by page-file, then map a view of  */
	/* this section into the owner process so we can write the contents  */
	/* of the CONSOLE_INFO buffer into it  */
	hSection = CreateFileMapping(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, pci->Length, 0);


	/* Copy our console structure into the section-object */
	ptrView = MapViewOfFile(hSection, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, pci->Length);
	memcpy(ptrView, pci, pci->Length);
	UnmapViewOfFile(ptrView);


	/* Map the memory into owner process  */
	DuplicateHandle(GetCurrentProcess(), hSection, hProcess, &hDupSection, 0, FALSE, DUPLICATE_SAME_ACCESS);

	/* Send console window the "update" message WM_SETCONSOLEINFO */
	SendMessage(hwndConsole, WM_SETCONSOLEINFO, (WPARAM)hDupSection, 0);

	/*clean up */
	hThread = CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)CloseHandle, hDupSection, 0, 0);
	CloseHandle(hThread);
	CloseHandle(hSection);
	CloseHandle(hProcess);
	return TRUE;
}

