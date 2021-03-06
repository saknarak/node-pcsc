#ifndef __PCSCWRAP_H__
#define __PCSCWRAP_H__
#include <stdio.h>

#ifdef __APPLE__
#include <PCSC/pcsclite.h>
#include <PCSC/winscard.h>
#include <PCSC/wintypes.h>
#else
#include <winscard.h>
#endif
#include "pcsc_type.h"


#define SCARD_PROTOCOL SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1

LONG pcsc_init();
DWORD pcsc_get_readers_name_length();
LONG pcsc_get_readers_name(char* readers_name, DWORD readers_name_length);
void pcsc_set_reader_name(const char *reader_name);
char* pcsc_get_reader_list();
LONG pcsc_connect(byte* atr, LPDWORD atrLen);
LONG pcsc_transmit(byte* input, DWORD inputLen, byte* output, LPDWORD outputLen);

LONG pcsc_disconnect();
LONG pcsc_release();


#endif /* #ifndef __PCSCWRAP_H__ */
