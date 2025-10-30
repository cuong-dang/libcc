#include "cc/std/ctype.h"
#include <stdio.h>
#if EOF != -1
#error EOF != -1
#endif

/* masks */
/*
 * The order of the masks is roughly based on their order in the ASCII
 * table.
 */
#define NT 0x00 /* not anything */
#define BB 0x01 /* BEL & BS */
#define CS 0x02 /* control space */
#define SP 0x04 /* space */
#define PU 0x08 /* punctuation */
#define DI 0x10 /* digit */
#define UP 0x20 /* uppercase */
#define LO 0x40 /* lowercase */
#define XA 0x80 /* hexadecimal alpha */
#define UX (UP | XA)
#define LX (LO | XA)

static const short is_tbl_[257] = {
    NT, /* EOF */
    NT, /* 000 NUL */
    NT, /* 001 SOH */
    NT, /* 002 STX */
    NT, /* 003 ETX */
    NT, /* 004 EOT */
    NT, /* 005 ENQ */
    NT, /* 006 ACK */
    BB, /* 007 BEL */
    BB, /* 008 BS */
    CS, /* 009 HT */
    CS, /* 010 LF */
    CS, /* 011 VT */
    CS, /* 012 FF */
    CS, /* 013 CR */
    NT, /* 014 SO */
    NT, /* 015 SI */
    NT, /* 016 DLE */
    NT, /* 017 DC1 */
    NT, /* 018 DC2 */
    NT, /* 019 DC3 */
    NT, /* 020 DC4 */
    NT, /* 021 NAK */
    NT, /* 022 SYN */
    NT, /* 023 ETB */
    NT, /* 024 CAN */
    NT, /* 025 EM */
    NT, /* 026 SUB */
    NT, /* 027 ESC */
    NT, /* 028 FS */
    NT, /* 029 GS */
    NT, /* 030 RS */
    NT, /* 031 US */
    SP, /* 032 SP */
    PU, /* 033 ! */
    PU, /* 034 " */
    PU, /* 035 # */
    PU, /* 036 $ */
    PU, /* 037 % */
    PU, /* 038 & */
    PU, /* 039 ' */
    PU, /* 040 ( */
    PU, /* 041 ) */
    PU, /* 042 * */
    PU, /* 043 + */
    PU, /* 044 , */
    PU, /* 045 - */
    PU, /* 046 . */
    PU, /* 047 / */
    DI, /* 048 0 */
    DI, /* 049 1 */
    DI, /* 050 2 */
    DI, /* 051 3 */
    DI, /* 052 4 */
    DI, /* 053 5 */
    DI, /* 054 6 */
    DI, /* 055 7 */
    DI, /* 056 8 */
    DI, /* 057 9 */
    PU, /* 058 : */
    PU, /* 059 ; */
    PU, /* 060 < */
    PU, /* 061 = */
    PU, /* 062 > */
    PU, /* 063 ? */
    PU, /* 064 @ */
    UX, /* 065 A */
    UX, /* 066 B */
    UX, /* 067 C */
    UX, /* 068 D */
    UX, /* 069 E */
    UX, /* 070 F */
    UP, /* 071 G */
    UP, /* 072 H */
    UP, /* 073 I */
    UP, /* 074 J */
    UP, /* 075 K */
    UP, /* 076 L */
    UP, /* 077 M */
    UP, /* 078 N */
    UP, /* 079 O */
    UP, /* 080 P */
    UP, /* 081 Q */
    UP, /* 082 R */
    UP, /* 083 S */
    UP, /* 084 T */
    UP, /* 085 U */
    UP, /* 086 V */
    UP, /* 087 W */
    UP, /* 088 X */
    UP, /* 089 Y */
    UP, /* 090 Z */
    PU, /* 091 [ */
    PU, /* 092 \ */
    PU, /* 093 ] */
    PU, /* 094 ^ */
    PU, /* 095 _ */
    PU, /* 096 ` */
    LX, /* 097 a */
    LX, /* 098 b */
    LX, /* 099 c */
    LX, /* 100 d */
    LX, /* 101 e */
    LX, /* 102 f */
    LO, /* 103 g */
    LO, /* 104 h */
    LO, /* 105 i */
    LO, /* 106 j */
    LO, /* 107 k */
    LO, /* 108 l */
    LO, /* 109 m */
    LO, /* 110 n */
    LO, /* 111 o */
    LO, /* 112 p */
    LO, /* 113 q */
    LO, /* 114 r */
    LO, /* 115 s */
    LO, /* 116 t */
    LO, /* 117 u */
    LO, /* 118 v */
    LO, /* 119 w */
    LO, /* 120 x */
    LO, /* 121 y */
    LO, /* 122 z */
    PU, /* 123 { */
    PU, /* 124 | */
    PU, /* 125 } */
    PU, /* 126 ~ */
    NT, /* 127 DEL */
};

static const short *is_tbl = &is_tbl_[1];

int isupper(int c) { return is_tbl[c] & UP; }
int islower(int c) { return is_tbl[c] & LO; }
int isalpha(int c) { return isupper(c) || islower(c); }
int isdigit(int c) { return is_tbl[c] & DI; }
int isxdigit(int c) { return is_tbl[c] & (isdigit(c) | XA); }
int isalnum(int c) { return isdigit(c) || isalpha(c); }
int ispunct(int c) { return is_tbl[c] & PU; }
int isgraph(int c) { return isalnum(c) || ispunct(c); }
int isprint(int c) { return isgraph(c) || (is_tbl[c] & SP); }
int isspace(int c) { return is_tbl[c] & (SP | CS); }
int iscntrl(int c) { return is_tbl[c] & (CS | BB); }
