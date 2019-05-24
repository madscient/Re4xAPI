#pragma once

#include "Re4xDefine.h"

#define BUFSIZE	65536

class Re4xManager;

class Re4xInterface : public SoundInterface {
protected:
	Re4xManager * parentManager;
	RE4X_INTERFACE_INFO* pInterfaceInfo;
	int rptr;
	int wptr;
	BYTE cmdbuf[BUFSIZE];
	virtual void __stdcall BufferPush(BYTE data);
	virtual void __stdcallBufferPush(BYTE* buf, UINT32 length);
	virtual FT_STATUS __stdcall BufferFlush();
	//to be implemented on derived class
	virtual FT_STATUS __stdcall InitInstance() { return FT_NOT_SUPPORTED; };
	virtual void __stdcall InitialClear() = 0;
	virtual FT_STATUS __stdcall BufferedRead(UINT8* buffer, UINT32 sizeToTransfer, UINT32 cs);
	virtual FT_STATUS __stdcall BufferedWrite(UINT8* buffer, UINT32 sizeToTransfer, UINT32 cs) = 0;
	virtual FT_STATUS __stdcall FT_WriteGPIO(UINT8 dir, UINT8 value) = 0;
public:
	Re4xInterface();
	Re4xInterface(Re4xManager* parent, RE4X_INTERFACE_INFO* pinfo);
	~Re4xInterface();
	RE4X_INTERFACE_INFO* __stdcall getInterfaceInfo();
	Re4xInterface* __stdcall getInterface();
	BOOL __stdcall releaseInterface();
	virtual int __stdcall getSlotCount() = 0;
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