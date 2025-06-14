#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char clothName[21];
	int caseNum, clothNum, i, j, arrNum = 0, k, flag = 0, sum = 1;
	int numArr[30] = { 0, };
	char* clothType;
	char* clothArr[30];
	scanf("%d", &caseNum);
	for (i = 0; i < caseNum; i++) {
		arrNum = 0;
		sum = 1;
		flag = 0;
		scanf("%d", &clothNum);
		for (j = 0; j < clothNum; j++) {
			scanf("%s", clothName);
			clothType = (char*)malloc(sizeof(char) * 21);
			scanf("%s", clothType);
			for (k = 0; k < arrNum; k++) {
				if (!strcmp(clothArr[k], clothType)) {
					numArr[k]++;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				numArr[arrNum] = 1;
				clothArr[arrNum] = clothType;
				arrNum++;
			}
			flag = 0;
		}
		for (j = 0; j < arrNum; j++) {
			sum *= (numArr[j] + 1);
		}
		sum--;
		printf("%d\n", sum);
	}
	return 0;
}