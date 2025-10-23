#include <stdio.h>

int main() {
	char board[9][9];
	int cnt = 0;

	for(int i=0; i<8; i++) scanf("%s", board[i]);

	for(int i=0; i<8; i++) 
		for(int j=0; j<8; j++) 
			if((i+j) % 2 == 0 && board[i][j] == 'F') cnt++;

	printf("%d", cnt);

	return 0;
}