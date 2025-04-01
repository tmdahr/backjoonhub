#include <stdio.h>

int main(void)
{
	int tkd, wnd, gk, zhf, tk, qj, dma;
	scanf("%d", &tkd);
	scanf("%d", &wnd);
	scanf("%d", &gk);
	scanf("%d", &zhf);
	scanf("%d", &tk);
	
	dma = (zhf < tk) ? zhf : tk;
	qj = (tkd < wnd) ? tkd : wnd;
	qj = (qj < gk) ? qj : gk;
	
	printf("%d", qj + dma - 50);
	
	return 0;
}