#include "stdafx.h"
#include "Re4xInterface.h"
#include "Re4xManager.h"

Re4xInterface::Re4xInterface() : pInterfaceInfo(nullptr), parentManager(nullptr)
{

}

Re4xInterface::Re4xInterface(Re4xManager* parent, RE4X_INTERFACE_INFO* pinfo) :
	pInterfaceInfo(pinfo), parentManager(parent)
{
	InitInstance();
}

Re4xInterface::~Re4xInterface()
{
}

RE4X_INTERFACE_INFO * __stdcall Re4xInterface::getInterfaceInfo()
{
	return pInterfaceInfo;
}

Re4xInterface * __stdcall Re4xInterface::getInterface()
{
	if (pInterfaceInfo != nullptr) {
		pInterfaceInfo->inUse = true;
	}
	return this;
}

BOOL __stdcall Re4xInterface::releaseInterface()
{
	if (pInterfaceInfo != nullptr) {
		pInterfaceInfo->inUse = false;
	}
	return 0;
}

BOOL __stdcall Re4xInterface::isSupportLowLevelApi()
{
	return true;
}

BOOL __stdcall Re4xInterface::setData(BYTE * pData, DWORD dSendDataLen)
{
	return 0;
}

DWORD __stdcall Re4xInterface::getData(BYTE * pData, DWORD dGetDataLen)
{
	return 0;
}

BOOL __stdcall Re4xInterface::setDelay(DWORD dDelay)
{
	return 0;
}

DWORD __stdcall Re4xInterface::getDelay()
{
	return 0;
}

BOOL __stdcall Re4xInterface::reset()
{
	return 0;
}

BOOL __stdcall Re4xInterface::init()
{
	return 0;
}

DWORD Re4xInterface::getSoundChipCount()
{
	return 0;
}

SoundChip * __stdcall Re4xInterface::getSoundChip(DWORD dNum)
{
	return nullptr;
}

void __stdcall Re4xInterface::BufferPush(BYTE data)
{
	cmdbuf[wptr++] = data;
	if (wptr == (BUFSIZE - 1)) { BufferFlush(); }
}

void __stdcall Re4xInterface::BufferPush(BYTE * buf, UINT32 length)
{
	if ((wptr + length) >= (BUFSIZE - 1)) { BufferFlush(); }
	memcpy(&cmdbuf[wptr], buf, length);
	wptr += length;
}

FT_STATUS __stdcall Re4xInterface::BufferFlush()
{
	FT_STATUS ret = FT_OTHER_ERROR;
	DWORD written = 0;
	if (wptr) {
		//SPIChannel[index].cmdbuf[SPIChannel[index].wptr++] = 0x87;	//force flush
		ret = FT_Write(pInterfaceInfo->ftHandle, cmdbuf, wptr, &written);
		wptr = 0;
		//BYTE forceflush = 0x87;
		//ret = FT_Write(SPIChannel[index].ftHandle, &forceflush, 1, &written);
	}
	else {
		ret = FT_OK;
	}
	return ret;
}

FT_STATUS __stdcall Re4xInterface::BufferedRead(UINT8 * buffer, UINT32 sizeToTransfer, UINT32 cs)
{
	return FT_OK;
}





