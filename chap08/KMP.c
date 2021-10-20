#include <stdio.h>

int kMP(const char txt[], const char pat[]) {
	int txt_cur = 1;
	int pat_cur = 0;
	int skip[1024];

	skip[txt_cur] = 0;
	while (pat[txt_cur] != '\0') {
		if (txt[txt_cur] == pat[pat_cur]) { // txt -> pat ?
			skip[++txt_cur] = ++pat_cur;
		}
		else if (pat_cur == 0) {
			skip[++txt_cur] = 0;
		}
		else {
			pat_cur = skip[pat_cur];
		}
	}

	txt_cur = 0;
	pat_cur = 0;

	while (txt[txt_cur] != '\0' && pat[pat_cur] != '\0') {
		if (txt[txt_cur] == pat[pat_cur]) {
			txt_cur++; 
			pat_cur++;
		}
		else if (pat_cur == 0)
			txt_cur++;
		else
			pat_cur = skip[pat_cur];
	}

	if (pat[pat_cur] == '\0') {
		return txt_cur - pat_cur; // success
	}
	return -1; // failed
}