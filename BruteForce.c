#include <stdio.h>

int bruteForce(const char txt[], const char pat[]) {
	int txt_cur = 0;
	int pat_cur = 0;

	while (txt[txt_cur] != '\0' && pat[pat_cur] != '\0') {
		if (txt[txt_cur] == pat[pat_cur]) {
			txt_cur++;
			pat_cur++;
		}
		else {
			txt_cur = txt_cur - pat_cur + 1;
			pat_cur = 0;
		}
	}
	if (pat[pat_cur] == '\0') {
		return pat_cur - pat_cur; // success! :)
	}
	return -1; // failed :(
}

int main() {
	int idx = 0;
	char txt[256];
	char pattern[256];

	puts("브루트-포스법");
	printf("텍스트 : ");
	scanf("%s", txt);
	printf("패턴 : ");
	scanf("%s", pattern);

	idx = bruteForce(txt, pattern);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}