#pragma once

#include "Re4xDefine.h"

#define BUFSIZE	65536

struct RE4X_INTERFACE_INFO;

class Re4xInterface : public SoundInterface {
protected:

	RE4X_INTERFACE_INFO* pInterfaceInfo;
	int rptr;
	int wptr;
	BYTE cmdbuf[BUFSIZE];
	virtual void BufferPush(BYTE data);
	virtual void BufferPush(BYTE* buf, UINT32 length);
	virtual FT_STATUS BufferFlush();
	//to be implemented on derived class
	virtual FT_STATUS InitInstance() { return FT_NOT_SUPPORTED; };
	virtual void InitialClear() = 0;
	virtual FT_STATUS BufferedRead(UINT8* buffer, UINT32 sizeToTransfer, UINT32 cs);
	virtual FT_STATUS BufferedWrite(UINT8* buffer, UINT32 sizeToTransfer, UINT32 cs) = 0;
	virtual FT_STATUS FT_WriteGPIO(UINT8 dir, UINT8 value) = 0;

public:
	Re4xInterface(RE4X_INTERFACE_INFO* pinfo);
	~Re4xInterface();
	RE4X_INTERFACE_INFO* getInterfaceInfo();
	Re4xInterface* getInterface();
	BOOL releaseInterface();
	///
	///implementation for SoundInterface
	///
	// support low level API check
	virtual BOOL __stdcall isSupportLowLevelApi();
	// send data to interface
	virtual BOOL __stdcall setData(BYTE *pData, DWORD dSendDataLen);
	// get data from interface
	virtual DWORD __stdcall getData(BYTE *pData, DWORD dGetDataLen);
	// set delay time
	virtual	BOOL __stdcall setDelay(DWORD dDelay);
	// get delay time
	virtual DWORD __stdcall getDelay();
	// reset interface
	virtual BOOL __stdcall reset();
	// initialize sound chips
	virtual BOOL __stdcall init();
	// サウンドチップ数取得
	virtual DWORD	__stdcall getSoundChipCount();
	// サウンドチップ取得
	virtual	SoundChip* __stdcall getSoundChip(DWORD dNum);
};

class Re4xSPIInterface : public Re4xInterface
{
protected:
	virtual FT_STATUS InitInstance();
public:
	Re4xSPIInterface(RE4X_INTERFACE_INFO* pinfo);
};

class Re4xHBEInterface : public Re4xInterface
{
protected:
	virtual FT_STATUS InitInstance();
public:
	Re4xHBEInterface(RE4X_INTERFACE_INFO* pinfo);
};