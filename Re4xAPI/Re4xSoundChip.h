#pragma once

#include "Re4xDefine.h"

class Re4xManager;
class Re4xInterface;

class	Re4xSoundChip : public SoundChip {
protected:
	RE4X_SOUND_CHIP_INFO * pSoundChipInfo;
	RE4X_CHIP_TYPE	chipID;
	Re4xManager* parentManager;
	Re4xInterface* parentInterface;
public:
	Re4xSoundChip(Re4xInterface* parent, RE4X_SOUND_CHIP_INFO* pinfo);
	///
	/// Implementation for SoundChip
	// get sound chip information
	virtual SCCI_SOUND_CHIP_INFO* __stdcall getSoundChipInfo();
	// get sound chip type
	virtual int __stdcall getSoundChipType();
	// set Register data
	virtual BOOL __stdcall setRegister(DWORD dAddr, DWORD dData);
	// get Register data(It may not be supported)
	virtual DWORD __stdcall getRegister(DWORD dAddr) = 0;
	// initialize sound chip(clear registers)
	virtual BOOL __stdcall init();
	// get sound chip clock
	virtual DWORD __stdcall getSoundChipClock();
	// get writed register data
	virtual DWORD __stdcall getWrittenRegisterData(DWORD addr);
	// buffer check
	virtual BOOL __stdcall isBufferEmpty();
};
