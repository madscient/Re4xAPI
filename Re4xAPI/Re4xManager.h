#pragma once

#include "Re4xDefine.h"
#include "Re4xAPI.h"

class Re4xManager : public SoundInterfaceManager
{
protected:
	std::vector<Re4xInterface*> re4xInterfaces;
	DWORD allowance;
public:
	Re4xManager();
	~Re4xManager();
	// ---------- LOW LEVEL APIs ----------
	// get interface count
	virtual int __stdcall getInterfaceCount();
	// get interface information 
	virtual SCCI_INTERFACE_INFO* __stdcall getInterfaceInfo(int iInterfaceNo);
	// get interface instance
	virtual SoundInterface* __stdcall getInterface(int iInterfaceNo);
	// release interface instance
	virtual BOOL __stdcall releaseInterface(SoundInterface* pSoundInterface);
	// release all interface instance
	virtual BOOL __stdcall releaseAllInterface();
	// ---------- HI LEVEL APIs ----------
	// get sound chip instance
	virtual SoundChip* __stdcall getSoundChip(int iSoundChipType, DWORD dClock);
	// release sound chip instance
	virtual BOOL __stdcall releaseSoundChip(SoundChip* pSoundChip);
	// release all sound chip instance
	virtual BOOL __stdcall releaseAllSoundChip();
	// set delay time
	virtual BOOL __stdcall setDelay(DWORD dMSec);
	// get delay time
	virtual DWORD __stdcall getDelay();
	// reset interfaces(A sound chips initialize after interface reset)
	virtual BOOL __stdcall reset();
	// initialize sound chips
	virtual BOOL __stdcall init();
	// Sound Interface instance initialize
	virtual	BOOL __stdcall initializeInstance();
	// Sound Interface instance release
	virtual BOOL __stdcall releaseInstance();
	// config scci
	// !!!this function is scciconfig exclusive use!!!
	virtual BOOL __stdcall config();
	// get version info
	virtual DWORD __stdcall getVersion(DWORD *pMVersion = NULL);
	// get Level mater disp valid
	virtual BOOL __stdcall isValidLevelDisp();
	// get Level mater disp visible
	virtual BOOL __stdcall isLevelDisp();
	// set Level mater disp visible
	virtual void __stdcall setLevelDisp(BOOL bDisp);
	// set mode
	virtual void __stdcall setMode(int iMode);
	// send datas
	virtual void __stdcall sendData();
	// clear buffer
	virtual void __stdcall clearBuff();
	// set Acquisition Mode(Sound Chip)
	virtual void __stdcall setAcquisitionMode(int iMode);
	// set Acquisition Mode clock renge
	virtual void __stdcall setAcquisitionModeClockRenge(DWORD dClock);
	// set command buffer size
	virtual BOOL __stdcall setCommandBuffetSize(DWORD dBuffSize);
	// buffer check
	virtual BOOL __stdcall isBufferEmpty();
};
