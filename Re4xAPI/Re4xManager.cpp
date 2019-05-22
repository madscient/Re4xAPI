#include "stdafx.h"
#include "Re4xManager.h"
#include "Re4xInterface.h"

Re4xManager::Re4xManager()
{
	allowance = 0;
}

int __stdcall Re4xManager::getInterfaceCount()
{
	return re4xInterfaces.size();
}

SCCI_INTERFACE_INFO* __stdcall Re4xManager::getInterfaceInfo(int iInterfaceNo)
{
	if (iInterfaceNo < re4xInterfaces.size() && re4xInterfaces[iInterfaceNo] != nullptr) {
		return &(re4xInterfaces[iInterfaceNo]->getInterfaceInfo()->scciInterfaceInfo);
	}
	return nullptr;
}

SoundInterface * Re4xManager::getInterface(int iInterfaceNo)
{
	if (iInterfaceNo < re4xInterfaces.size() && re4xInterfaces[iInterfaceNo] != nullptr) {
		return re4xInterfaces[iInterfaceNo]->getInterface();
	}
	return nullptr;
}

BOOL Re4xManager::releaseInterface(SoundInterface * pSoundInterface)
{
	if (pSoundInterface != nullptr) {
		for (Re4xInterface* var : re4xInterfaces)
		{
			if (var == pSoundInterface) {
				return var->releaseInterface();
			}
		}
	}
	return 0;
}

BOOL Re4xManager::releaseAllInterface()
{
	for (Re4xInterface* var : re4xInterfaces)
	{
		var->releaseInterface();
	}
	return true;
}

SoundChip * Re4xManager::getSoundChip(int iSoundChipType, DWORD dClock)
{
	return nullptr;
}

BOOL Re4xManager::releaseSoundChip(SoundChip * pSoundChip)
{
	return 0;
}

BOOL Re4xManager::releaseAllSoundChip()
{
	return 0;
}

BOOL Re4xManager::setDelay(DWORD dMSec)
{
	return 0;
}

DWORD Re4xManager::getDelay()
{
	return 0;
}

BOOL Re4xManager::reset()
{
	return 0;
}

BOOL Re4xManager::init()
{
	return true;
}

BOOL Re4xManager::initializeInstance()
{
	FT_STATUS status = FT_OK;
	DWORD numDevices = 0;
	status = FT_ListDevices(&numDevices, 0, FT_LIST_NUMBER_ONLY);
	//printf("Number of available SPI channels = %d\n", (int)channels);
	status = FT_CreateDeviceInfoList(&numDevices);
	FT_DEVICE_LIST_INFO_NODE* devList = new FT_DEVICE_LIST_INFO_NODE[numDevices];
	status = FT_GetDeviceInfoList(devList, &numDevices);

	for (DWORD i = 0; i < numDevices; i++) {
		RE4X_INTERFACE_INFO* pifinfo = new RE4X_INTERFACE_INFO();
		sprintf_s(pifinfo->ftDescription, _countof(pifinfo->ftDescription), "%s(%s)", devList[i].Description, devList[i].SerialNumber);
		pifinfo->inUse = false;
		pifinfo->ftIndex = i;
		switch (devList[i].Type)
		{
		case FT_DEVICE_232H:
			re4xInterfaces.push_back(new Re4xSPIInterface(pifinfo));
			break;
		case FT_DEVICE_2232C:
			re4xInterfaces.push_back(new Re4xHBEInterface(pifinfo));
			break;
		default:
			delete pifinfo;
			break;
		}
	}
	delete[] devList;
	return true;
}

BOOL Re4xManager::releaseInstance()
{
	return 0;
}

BOOL Re4xManager::config()
{
	return 0;
}

DWORD Re4xManager::getVersion(DWORD * pMVersion)
{
	return 0;
}

BOOL Re4xManager::isValidLevelDisp()
{
	return 0;
}

BOOL Re4xManager::isLevelDisp()
{
	return 0;
}

void Re4xManager::setLevelDisp(BOOL bDisp)
{
}

void Re4xManager::setMode(int iMode)
{
}

void Re4xManager::sendData()
{
}

void Re4xManager::clearBuff()
{
}

void Re4xManager::setAcquisitionMode(int iMode)
{
}

void Re4xManager::setAcquisitionModeClockRenge(DWORD dClock)
{
	allowance = dClock;
}

BOOL Re4xManager::setCommandBuffetSize(DWORD dBuffSize)
{
	return 0;
}

BOOL Re4xManager::isBufferEmpty()
{
	return 0;
}

