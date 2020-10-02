#pragma once

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

// DEBUG SUPPORT FUNCTIONS //////////////
#define _W(x)  __W(x)
#define __W(x)  L##x

void DebugOut(wchar_t* fmt, ...);
void DebugOutTitle(wchar_t* fmt, ...); 
void SetDebugWindow(HWND hWnd); 


