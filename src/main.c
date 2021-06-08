// FILE NAME  : main.c
// AUTHOR     : Rafael Garibotti
// DEVELOPERS : Rafael Garibotti
// E-mail     : rafael.garibotti@pucrs.br
//-----------------------------------------------------------------------------
// RELEASE HISTORY
// VERSION   DATE         DESCRIPTION
// 1.0       2021-06-08   Initial version.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include "crypt.h"

//-----------------------------------------------------------------------------
// Main Function
//-----------------------------------------------------------------------------
int
main(void) {
  int i, error, type, enc_dec;
  unsigned int key[8], plan[4], cipher[4];

  printf("-- Crypt. Algorithms (START) --\n"); 

  for (i = 0; i < 14; i++){
    error = 0;

    // Testcase name
    switch (i) {
      case 0  : printf("\n-- XTEA (ENC) --\n"); break; //XTEA - ENC
      case 1  : printf("\n-- XTEA (DEC) --\n"); break; //XTEA - DEC
      case 2  : printf("\n-- AES-128 (ENC) --\n"); break; //AES-128 - ENC
      case 3  : printf("\n-- AES-128 (DEC) --\n"); break; //AES-128 - DEC
      case 4  : printf("\n-- AES-192 (ENC) --\n"); break; //AES-192 - ENC
      case 5  : printf("\n-- AES-192 (DEC) --\n"); break; //AES-192 - DEC
      case 6  : printf("\n-- AES-256 (ENC) --\n"); break; //AES-256 - ENC
      case 7  : printf("\n-- AES-256 (DEC) --\n"); break; //AES-256 - DEC
      case 8  : printf("\n-- BLOWFISH-128 (ENC) --\n"); break; //BLOWFISH-128 - ENC
      case 9  : printf("\n-- BLOWFISH-128 (DEC) --\n"); break; //BLOWFISH-128 - DEC
      case 10 : printf("\n-- BLOWFISH-192 (ENC) --\n"); break; //BLOWFISH-192 - ENC
      case 11 : printf("\n-- BLOWFISH-192 (DEC) --\n"); break; //BLOWFISH-192 - DEC
      case 12 : printf("\n-- BLOWFISH-256 (ENC) --\n"); break; //BLOWFISH-256 - ENC
      case 13 : printf("\n-- BLOWFISH-256 (DEC) --\n"); break; //BLOWFISH-256 - DEC
    }

    // Write key
    key[0] = 0xDEADBEEF;
    key[1] = 0x01234567;
    key[2] = 0x89ABCDEF;
    key[3] = 0xDEADBEEF;
    key[4] = 0xDEADBEEF;
    key[5] = 0x01234567;
    key[6] = 0x89ABCDEF;
    key[7] = 0xDEADBEEF;

    // Write plantext
    switch (i) {
      case 0  : plan[0] = 0xA5A5A5A5; break; //XTEA - ENC
      case 1  : plan[0] = 0x089975E9; break; //XTEA - DEC
      case 2  : plan[0] = 0xA5A5A5A5; break; //AES-128 - ENC
      case 3  : plan[0] = 0x237549D4; break; //AES-128 - DEC
      case 4  : plan[0] = 0xA5A5A5A5; break; //AES-192 - ENC
      case 5  : plan[0] = 0xEBB4CD9E; break; //AES-192 - DEC
      case 6  : plan[0] = 0xA5A5A5A5; break; //AES-256 - ENC
      case 7  : plan[0] = 0x206BF119; break; //AES-256 - DEC
      case 8  : plan[0] = 0xA5A5A5A5; break; //BLOWFISH-128 - ENC
      case 9  : plan[0] = 0x24B9C5E1; break; //BLOWFISH-128 - DEC
      case 10 : plan[0] = 0xA5A5A5A5; break; //BLOWFISH-192 - ENC
      case 11 : plan[0] = 0xA5E31925; break; //BLOWFISH-192 - DEC
      case 12 : plan[0] = 0xA5A5A5A5; break; //BLOWFISH-256 - ENC
      case 13 : plan[0] = 0x24B9C5E1; break; //BLOWFISH-256 - DEC
    }
    switch (i) {
      case 0  : plan[1] = 0x01234567; break; //XTEA - ENC
      case 1  : plan[1] = 0x2555F334; break; //XTEA - DEC
      case 2  : plan[1] = 0x01234567; break; //AES-128 - ENC
      case 3  : plan[1] = 0xCDCEA7BE; break; //AES-128 - DEC
      case 4  : plan[1] = 0x01234567; break; //AES-192 - ENC
      case 5  : plan[1] = 0xDA7CBDE0; break; //AES-192 - DEC
      case 6  : plan[1] = 0x01234567; break; //AES-256 - ENC
      case 7  : plan[1] = 0x7A085AC8; break; //AES-256 - DEC
      case 8  : plan[1] = 0x01234567; break; //BLOWFISH-128 - ENC
      case 9  : plan[1] = 0xB06FBF71; break; //BLOWFISH-128 - DEC
      case 10 : plan[1] = 0x01234567; break; //BLOWFISH-192 - ENC
      case 11 : plan[1] = 0x25FE7048; break; //BLOWFISH-192 - DEC
      case 12 : plan[1] = 0x01234567; break; //BLOWFISH-256 - ENC
      case 13 : plan[1] = 0xB06FBF71; break; //BLOWFISH-256 - DEC
    }
    switch (i) {
      case 0  : plan[2] = 0xFEDCBA98; break; //XTEA - ENC
      case 1  : plan[2] = 0xCE76E4F2; break; //XTEA - DEC
      case 2  : plan[2] = 0xFEDCBA98; break; //AES-128 - ENC
      case 3  : plan[2] = 0x0FE7D162; break; //AES-128 - DEC
      case 4  : plan[2] = 0xFEDCBA98; break; //AES-192 - ENC
      case 5  : plan[2] = 0x9E520F4C; break; //AES-192 - DEC
      case 6  : plan[2] = 0xFEDCBA98; break; //AES-256 - ENC
      case 7  : plan[2] = 0xB31B2AD0; break; //AES-256 - DEC
      case 8  : plan[2] = 0xFEDCBA98; break; //BLOWFISH-128 - ENC
      case 9  : plan[2] = 0x5527E5FA; break; //BLOWFISH-128 - DEC
      case 10 : plan[2] = 0xFEDCBA98; break; //BLOWFISH-192 - ENC
      case 11 : plan[2] = 0x4254F298; break; //BLOWFISH-192 - DEC
      case 12 : plan[2] = 0xFEDCBA98; break; //BLOWFISH-256 - ENC
      case 13 : plan[2] = 0x5527E5FA; break; //BLOWFISH-256 - DEC
    }
    switch (i) {
      case 0  : plan[3] = 0x5A5A5A5A; break; //XTEA - ENC
      case 1  : plan[3] = 0x4D932AB3; break; //XTEA - DEC
      case 2  : plan[3] = 0x5A5A5A5A; break; //AES-128 - ENC
      case 3  : plan[3] = 0xCC9161D3; break; //AES-128 - DEC
      case 4  : plan[3] = 0x5A5A5A5A; break; //AES-192 - ENC
      case 5  : plan[3] = 0x54BE5A98; break; //AES-192 - DEC
      case 6  : plan[3] = 0x5A5A5A5A; break; //AES-256 - ENC
      case 7  : plan[3] = 0x4843FFC1; break; //AES-256 - DEC
      case 8  : plan[3] = 0x5A5A5A5A; break; //BLOWFISH-128 - ENC
      case 9  : plan[3] = 0x3502EE1A; break; //BLOWFISH-128 - DEC
      case 10 : plan[3] = 0x5A5A5A5A; break; //BLOWFISH-192 - ENC
      case 11 : plan[3] = 0x4B71D955; break; //BLOWFISH-192 - DEC
      case 12 : plan[3] = 0x5A5A5A5A; break; //BLOWFISH-256 - ENC
      case 13 : plan[3] = 0x3502EE1A; break; //BLOWFISH-256 - DEC
    }
	printf("%08X %08X %08X %08X (Plan)\n", plan[0], plan[1], plan[2], plan[3]);

    // Write enc_dec
    enc_dec = (i+1) % 2;
	
	// Write type
	type = (i / 2);

    // Call Crypt. Function
	crypt(key, plan, type, enc_dec, cipher);
	/*
    // XTEA
    if (i < 2) {
      xtea(key, plan, enc_dec, cipher);
    // AES
    } else if (i < 8) {
      aes(key, plan, type, enc_dec, cipher);
    // BLOWFISH
    } else {
      crypt(key, plan, type, enc_dec, cipher);
    }*/

    // Read ciphertext
    switch (i) {
      case 0  : if (cipher[0] != 0x089975E9) error = 1; break; //XTEA - ENC
      case 1  : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //XTEA - DEC
      case 2  : if (cipher[0] != 0x237549D4) error = 1; break; //AES-128 - ENC
      case 3  : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //AES-128 - DEC
      case 4  : if (cipher[0] != 0xEBB4CD9E) error = 1; break; //AES-192 - ENC
      case 5  : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //AES-192 - DEC
      case 6  : if (cipher[0] != 0x206BF119) error = 1; break; //AES-256 - ENC
      case 7  : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //AES-256 - DEC
      case 8  : if (cipher[0] != 0x24B9C5E1) error = 1; break; //BLOWFISH-128 - ENC
      case 9  : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //BLOWFISH-128 - DEC
      case 10 : if (cipher[0] != 0xA5E31925) error = 1; break; //BLOWFISH-192 - ENC
      case 11 : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //BLOWFISH-192 - DEC
      case 12 : if (cipher[0] != 0x24B9C5E1) error = 1; break; //BLOWFISH-256 - ENC
      case 13 : if (cipher[0] != 0xA5A5A5A5) error = 1; break; //BLOWFISH-256 - DEC
    }
    switch (i) {
      case 0  : if (cipher[1] != 0x2555F334) error = 1; break; //XTEA - ENC
      case 1  : if (cipher[1] != 0x01234567) error = 1; break; //XTEA - DEC
      case 2  : if (cipher[1] != 0xCDCEA7BE) error = 1; break; //AES-128 - ENC
      case 3  : if (cipher[1] != 0x01234567) error = 1; break; //AES-128 - DEC
      case 4  : if (cipher[1] != 0xDA7CBDE0) error = 1; break; //AES-192 - ENC
      case 5  : if (cipher[1] != 0x01234567) error = 1; break; //AES-192 - DEC
      case 6  : if (cipher[1] != 0x7A085AC8) error = 1; break; //AES-256 - ENC
      case 7  : if (cipher[1] != 0x01234567) error = 1; break; //AES-256 - DEC
      case 8  : if (cipher[1] != 0xB06FBF71) error = 1; break; //BLOWFISH-128 - ENC
      case 9  : if (cipher[1] != 0x01234567) error = 1; break; //BLOWFISH-128 - DEC
      case 10 : if (cipher[1] != 0x25FE7048) error = 1; break; //BLOWFISH-192 - ENC
      case 11 : if (cipher[1] != 0x01234567) error = 1; break; //BLOWFISH-192 - DEC
      case 12 : if (cipher[1] != 0xB06FBF71) error = 1; break; //BLOWFISH-256 - ENC
      case 13 : if (cipher[1] != 0x01234567) error = 1; break; //BLOWFISH-256 - DEC
    }
    switch (i) {
      case 0  : if (cipher[2] != 0xCE76E4F2) error = 1; break; //XTEA - ENC
      case 1  : if (cipher[2] != 0xFEDCBA98) error = 1; break; //XTEA - DEC
      case 2  : if (cipher[2] != 0x0FE7D162) error = 1; break; //AES-128 - ENC
      case 3  : if (cipher[2] != 0xFEDCBA98) error = 1; break; //AES-128 - DEC
      case 4  : if (cipher[2] != 0x9E520F4C) error = 1; break; //AES-192 - ENC
      case 5  : if (cipher[2] != 0xFEDCBA98) error = 1; break; //AES-192 - DEC
      case 6  : if (cipher[2] != 0xB31B2AD0) error = 1; break; //AES-256 - ENC
      case 7  : if (cipher[2] != 0xFEDCBA98) error = 1; break; //AES-256 - DEC
      case 8  : if (cipher[2] != 0x5527E5FA) error = 1; break; //BLOWFISH-128 - ENC
      case 9  : if (cipher[2] != 0xFEDCBA98) error = 1; break; //BLOWFISH-128 - DEC
      case 10 : if (cipher[2] != 0x4254F298) error = 1; break; //BLOWFISH-192 - ENC
      case 11 : if (cipher[2] != 0xFEDCBA98) error = 1; break; //BLOWFISH-192 - DEC
      case 12 : if (cipher[2] != 0x5527E5FA) error = 1; break; //BLOWFISH-256 - ENC
      case 13 : if (cipher[2] != 0xFEDCBA98) error = 1; break; //BLOWFISH-256 - DEC
    }
    switch (i) {
      case 0  : if (cipher[3] != 0x4D932AB3) error = 1; break; //XTEA - ENC
      case 1  : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //XTEA - DEC
      case 2  : if (cipher[3] != 0xCC9161D3) error = 1; break; //AES-128 - ENC
      case 3  : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //AES-128 - DEC
      case 4  : if (cipher[3] != 0x54BE5A98) error = 1; break; //AES-192 - ENC
      case 5  : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //AES-192 - DEC
      case 6  : if (cipher[3] != 0x4843FFC1) error = 1; break; //AES-256 - ENC
      case 7  : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //AES-256 - DEC
      case 8  : if (cipher[3] != 0x3502EE1A) error = 1; break; //BLOWFISH-128 - ENC
      case 9  : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //BLOWFISH-128 - DEC
      case 10 : if (cipher[3] != 0x4B71D955) error = 1; break; //BLOWFISH-192 - ENC
      case 11 : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //BLOWFISH-192 - DEC
      case 12 : if (cipher[3] != 0x3502EE1A) error = 1; break; //BLOWFISH-256 - ENC
      case 13 : if (cipher[3] != 0x5A5A5A5A) error = 1; break; //BLOWFISH-256 - DEC
    }
	printf("%08X %08X %08X %08X (Cipher)\n", cipher[0], cipher[1], cipher[2], cipher[3]);

    if (error == 1) {
      printf("CRYPT: ERROR!!!\n"); 
    }
    else {
      switch (i) {
        case 0  : printf("XTEA (ENC): OK\n"); break; //XTEA - ENC
        case 1  : printf("XTEA (DEC): OK\n"); break; //XTEA - DEC
        case 2  : printf("AES-128 (ENC): OK\n"); break; //AES-128 - ENC
        case 3  : printf("AES-128 (DEC): OK\n"); break; //AES-128 - DEC
        case 4  : printf("AES-192 (ENC): OK\n"); break; //AES-192 - ENC
        case 5  : printf("AES-192 (DEC): OK\n"); break; //AES-192 - DEC
        case 6  : printf("AES-256 (ENC): OK\n"); break; //AES-256 - ENC
        case 7  : printf("AES-256 (DEC): OK\n"); break; //AES-256 - DEC
        case 8  : printf("BLOWFISH-128 (ENC): OK\n"); break; //BLOWFISH-128 - ENC
        case 9  : printf("BLOWFISH-128 (DEC): OK\n"); break; //BLOWFISH-128 - DEC
        case 10 : printf("BLOWFISH-192 (ENC): OK\n"); break; //BLOWFISH-192 - ENC
        case 11 : printf("BLOWFISH-192 (DEC): OK\n"); break; //BLOWFISH-192 - DEC
        case 12 : printf("BLOWFISH-256 (ENC): OK\n"); break; //BLOWFISH-256 - ENC
        case 13 : printf("BLOWFISH-256 (DEC): OK\n"); break; //BLOWFISH-256 - DEC
      }
    }
  }

  printf("\n-- Crypt. Algorithms (END) --\n"); 
  return 0;
}
