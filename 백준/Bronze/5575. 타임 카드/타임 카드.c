#include <stdio.h>

int main(void)
{
	int ah, am, as, bh, bm, bs, ch, cm, cs, ah2, am2, as2, bh2, bm2, bs2, ch2, cm2, cs2, at, bt, ct;
	
	scanf("%d %d %d %d %d %d", &ah, &am, &as, &ah2, &am2, &as2);
	scanf("%d %d %d %d %d %d", &bh, &bm, &bs, &bh2, &bm2, &bs2);
	scanf("%d %d %d %d %d %d", &ch, &cm, &cs, &ch2, &cm2, &cs2);
	
	as = (ah * 60 + am) * 60 + as;
	as2 = (ah2 * 60 + am2) * 60 + as2;
	bs = (bh * 60 + bm) * 60 + bs;
	bs2 = (bh2 * 60 + bm2) * 60 + bs2;
	cs = (ch * 60 + cm) * 60 + cs;	
	cs2 = (ch2 * 60 + cm2) * 60 + cs2;
	
	at = as2 - as;
	bt = bs2 - bs;
	ct = cs2 - cs;
	
	ah = at / 3600;
	am = at % 3600 / 60;
	as = at % 3600 % 60;
	bh = bt / 3600;
	bm = bt % 3600 / 60;
	bs = bt % 3600 % 60;
	ch = ct / 3600;
	cm = ct % 3600 / 60;
	cs = ct % 3600 % 60;
	
	printf("%d %d %d\n", ah, am, as);
	printf("%d %d %d\n", bh, bm, bs);
	printf("%d %d %d\n", ch, cm, cs);
	
	return 0;
}