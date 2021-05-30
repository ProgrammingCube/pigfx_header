/* PIGFX

   Header for special routines supplied by
   PIGFX.
   Specifically formatted for Aztec C
   
   4/25/21
   Patrick Jackson
*/

#ifndef PIGFX_H
#define PIGFX_H

#ifndef ESC
#define ESC     27
#endif

#define NOFILL  0
#define FILL    1

#define _8X8    0
#define _8X16   1
#define _8X24   2

#define XTERM   0
#define VGA     1
#define CUSTOM  2
#define C64     3

#define HEX     16
#define DEC     10



/* Cursor routines */

pgCInvs()
{
    printf("%c[?25l",ESC);
}

pgCBlnk()
{
    printf("%c[?25b",ESC);
}

pgCVis()
{
    printf("%c[?25h",ESC);
}

pgCZero()
{
    printf("%c[H",ESC);
}
pgCSave()
{
    printf("%c[s",ESC);
}

pgCRstr()
{
    printf("%c[u",ESC);
}

pgCMove(x,y)
int x,y;
{
    printf("%c[%d;%dH",ESC,y,x);
}

pgCUp(x)
int x;
{
    printf("%c[%dA",ESC,x);
}

pgCDown(x)
int x;
{
    printf("%c[%dB",ESC,x);
}

pgCFwrd(x)
int x;
{
    printf("%c[%dC",ESC,x);
}

pgCBack(x)
int x;
{
    printf("%c[%dD",ESC,x);
}



/* Clearing routines */

pgClEnd()
{
    printf("%c[K",ESC);
}

pgClBeg()
{
    printf("%c[1K",ESC);
}

pgClLin()
{
    printf("%c[2K",ESC);
}

pgClCur(i)
int i;
{
    switch (i)
    {
        case 0:
            printf("%c[J",ESC);
            break;
        case 1:
            printf("%c[1J",ESC);
            break;
    }
}

pgClScr()
{
    printf("%c[2J",ESC);
}

/* insert/delete */

pgInsCh()
{
    printf("%c[1@",ESC);
}


pgDelCh()
{
    printf("%c[1P",ESC);
}

pgInsLn()
{
    printf("%c[1L",ESC);
}

pgDelLn()
{
    printf("%c[1M",ESC);
}

/* Graphics routines */

pgLine(x1, y1, x2, y2)
unsigned int x1, y1, x2, y2;
{
    printf("%c[#%d;%d;%d;%dl",ESC,x1,y1,x2,y2);
}

pgRect(x, y, w, h, f)
unsigned int x, y, h, w;
char f;
{
    switch(f)
    {
        case NOFILL:
            printf("%c[#%d;%d;%d;%dR",ESC,x,y,w,h);
            break;
        case FILL:
            printf("%c[#%d;%d;%d;%dr",ESC,x,y,w,h);
            break;
    }
}

pgCirc(x, y, r, f)
unsigned int x, y, r;
char f;
{
    switch(f)
    {
        case NOFILL:
            printf("%c[#%d;%d;%dC",ESC,x,y,r);
            break;
        case FILL:
            printf("%c[#%d;%d;%dc",ESC,x,y,r);
            break;
    }
}

pgTri(x1, y1, x2, y2, x3, y3)
unsigned int x1, y1, x2, y2, x3, y3;
{
    printf("%c[#%d;%d;%d;%d;%d;%dT",ESC,x1,y1,x2,y2,x3,y3);
}



/* bitmaps */

ldAscBmp(idx, x, y, b)
unsigned char idx, b;
int x, y;
{
    printf("%c[#%d;%d;%d;%da",ESC,idx,x,y,b);
}

ldRAscBmp(idx, x, y, b)
unsigned char idx, b;
int x, y;
{
    printf("%c[#%d;%d;%d;%dA",ESC,idx,x,y,b);
}

ldRawBmp(idx, x, y)
unsigned char idx;
int x, y;
{
    printf("%c[#%d;%d;%db",ESC,idx,x,y);
}

ldRleBmp(idx, x, y)
{
    printf("%c[#%d;%d;%dB",ESC,idx,x,y);
}

drawBmp(idx, x, y)
unsigned char idx;
int x, y;
{
    printf("%c[#%d;%d;%dd",ESC,idx,x,y);
}

drawSprt(idx, ref, x, y)
unsigned char idx;
int ref, x, y;
{
    printf("%c[#%d;%d;%d;%ds",ESC,idx,ref,x,y);
}

remvSprt(idx)
unsigned char idx;
{
    printf("%c[#%dx",ESC,idx);
}

moveSprt(idx, x, y)
{
    printf("%c[#%d;%d;%dm",ESC,idx,x,y);
}



/* scrolling */

pgScUp(x)
int x;
{
    printf("%c[#%d",ESC,x);
}

pgScDwn(x)
int x;
{
    printf("%c[#%d_",ESC,x);
}

pgScLft(x)
int x;
{
    printf("%c[#%d<",ESC,x);
}

pgScRgt(x)
int x;
{
    printf("%c[#%d>",ESC,x);
}



/* settings
   Some of these are taken care
   of by CONIO.H, so I skip
   those.
*/

pgRsClr()
{
    printf("%c[m",ESC);
}

pgFgClr(x)
unsigned char x;
{
    printf("%c[38;5;%dm",ESC,x);
}

pgFgClrD(x)
unsigned char x;
{
    printf("%c[38;6;%dm",ESC,x);
}

pgBgClr(x)
unsigned char x;
{
    printf("%c[48;5;%dm",ESC,x);
}

pgBgClrD(x)
unsigned char x;
{
    printf("%c[48;6;%dm",ESC,x);
}

pgTrClr(x)
unsigned char x;
{
    printf("%c[58;5;%dm",ESC,x);
}

pgRstDrw()
{
    printf("%c[=0m",ESC);
}

pgXor()
{
    printf("%c[=1m",ESC);
}

pgTrDrw()
{
    printf("%c[=2m",ESC);
}

pgStFnt(x)
char x;
{
    printf("%c[=%df",ESC,x);
}

pgStTab(x)
char x;
{
    printf("%c[=%dt",ESC,x);
}

pgDspMd(x)
char x;
{
    printf("%c[=%dh",ESC,x);
}

pgLdPal(x)
char x;
{
    printf("%c[=%dp",ESC);
}

pgStPal(x,y)
unsigned char x, y;
{
    printf("%c[=%d;%dp",ESC,x,y);
}

/* Collision detected from PiGFX */
/* ESC[#<idx1>;<idx2>c */

#endif
