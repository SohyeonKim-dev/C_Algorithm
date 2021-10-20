#include <stdio.h>
#include <string.h>
#include <limits.h>

int boyerMoore(const char txt[], const char pat[]) {
	int txt_cur;
	int pat_cur;
	int txt_len = strlen(txt);					
	int pat_len = strlen(pat);					
	int skip[UCHAR_MAX + 1];

	for (txt_cur = 0; txt_cur <= UCHAR_MAX; txt_cur++) {
		skip[txt_cur] = pat_len;
	}
		
	for (txt_cur = 0; txt_cur < pat_len - 1; txt_cur++) {
		skip[pat[txt_cur]] = pat_len - txt_cur - 1;
	}	

	while (txt_cur < txt_len) {
		pat_cur = pat_len - 1; 			// rear

		while (txt[txt_cur] == pat[pat_cur]) {
			if (pat_cur == 0) {
				return txt_cur;		// success :)
			}
			pat_cur--;		// <--
			txt_cur--;
		}

		if (skip[txt[txt_cur]] > pat_len - pat_cur) {
			txt_cur = txt_cur + skip[txt[txt_cur]];
		}
		else {
			txt_cur = txt_cur + pat_len - pat_cur;
		}
	}
	return -1; // failed
}