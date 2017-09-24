#pragma once
#ifndef EXT_STRING_H
	#define EXT_STRING_H

	#ifndef __STDC_WANT_LIB_EXT1__
		#define __STDC_WANT_LIB_EXT1__ 1
	#elif 1 != __STDC_WANT_LIB_EXT1__
		#undef __STDC_WANT_LIB_EXT1__
		#define __STDC_WANT_LIB_EXT1__ 1
	#endif

	#ifndef __STDC_WANT_LIB_EXT2__
		#define __STDC_WANT_LIB_EXT2__ 1
	#elif 1 != __STDC_WANT_LIB_EXT2__
		#undef __STDC_WANT_LIB_EXT2__
		#define __STDC_WANT_LIB_EXT2__ 1
	#endif

	#include <string.h>

	#ifndef __STDC_LIB_EXT1__
		#warning "Bounds-checked String library is not guaranteed to be available."
	#else
		#pragma message("Bounds-checked String library is available.")
	#endif
	
	#ifndef __STDC_ALLOC_LIB__
		#warning "Dynamic Memory TS library is not guaranteed to be available."
	#else
		#pragma message("Dynamic Memory TS library is available.")
	#endif

#endif
