// Re4xAPI.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include "Re4xAPI.h"
#include "Re4xManager.h"

extern Re4xManager* theManager = NULL;

SoundInterfaceManager* getSoundInterfaceManager()
{
	return theManager;
}
