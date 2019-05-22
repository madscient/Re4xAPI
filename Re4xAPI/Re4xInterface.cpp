#include "stdafx.h"
#include "Re4xInterface.h"

Re4xInterface::Re4xInterface(RE4X_INTERFACE_INFO* pinfo) : pInterfaceInfo(pinfo)
{
	InitInstance();
}

void Re4xInterface::BufferPush(BYTE data)
{
	cmdbuf[wptr++] = data;
	if (wptr == (BUFSIZE - 1)) { BufferFlush(); }
}

void Re4xInterface::BufferPush(BYTE * buf, UINT32 length)
{
	if ((wptr + length) >= (BUFSIZE - 1)) { BufferFlush(); }
	memcpy(&cmdbuf[wptr], buf, length);
	wptr += length;
}

FT_STATUS Re4xInterface::BufferFlush()
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

FT_STATUS Re4xInterface::BufferedRead(UINT8 * buffer, UINT32 sizeToTransfer, UINT32 cs)
{
	return FT_OK;
}





Re4xSPIInterface::Re4xInterface(RE4X_INTERFACE_INFO* pinfo) : Re4xInterface(pinfo)
{
}

Re4xHBEInterface::Re4xInterface(RE4X_INTERFACE_INFO* pinfo) : Re4xInterface(pinfo)
{
}

