#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <locale>
#include "timeutil.h"

using namespace std;

#ifdef _WIN32
# include <tchar.h>
#else
# define TCHAR      char
# define _tprintf   printf
# define _tmain     main
#endif /* _WIN32 */


// Shell's sort
// Shell's sort is an enhanced sort of insertion sort
template <typename _Key>
void shell_sort(_Key arr[], int len) {
	int i = 0, j = 0, gap = 0;
	_Key temp;
	// init step from len/2 to 1
	for (gap = len >> 1; gap > 0; gap >>= 1) {
		// insertion sort
		for (i = gap; i < len; ++i) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && temp < arr[j]; j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}


int _tmain(int argc, TCHAR *argv[])
{
    CTimeUtil tu_obj;
#ifdef _WIN32
	_tprintf(_T("In _WIN32 environment:\n"));
#else
	_tprintf(_T("In non-_WIN32 environment:\n"));
#endif /* _WIN32 */
	_tprintf(_T("\nDay: %d\n"), tu_obj.Day());
	_tprintf(_T("Time: %s\n"), tu_obj.Now().c_str());

	srand((unsigned int)time(NULL));
	int data[80000];
	int len = 80000;
	for (int i = 0; i < len; ++i) {
		data[i] = rand();
	}
	
	// use shell's sort to test Start() and End() function
	tu_obj.Start();
	shell_sort(data, len);
	double timeuse = tu_obj.End();
	_tprintf(_T("shell's sort %6d data used: %f sec\n"), len, timeuse);
	
    return 0;
}
