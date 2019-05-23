//----------------------------------------------------------------------
//	Re:inforce 4x Sound Interfaces defines
//----------------------------------------------------------------------
#pragma once

#include <Windows.h>
#include "../FTDI/ftd2xx.h"
#include "../scci/scci.h"
#include "../scci/SCCIDefines.h"

// Sound chip list
enum RE4X_CHIP_TYPE {
	RE4X_TYPE_NONE = 0,
	RE4X_TYPE_GENERIC = 0x1,		//A0=0でアドレス、A0=1でデータを書き込むタイプ
	RE4X_TYPE_OPPOSITE = 0x2,		//A0=1でアドレス、A0=0でデータを書き込むタイプ
	RE4X_TYPE_RAW = 0x3,			//A0-A7にアドレスをそのまま出すタイプ

	RE4X_TYPE_YM2608 = 0x2608,
	RE4X_TYPE_YM2151 = 0x2151,
	RE4X_TYPE_YM2610 = 0x2610,
	RE4X_TYPE_YM2203 = 0x2203,
	RE4X_TYPE_YM2612 = 0x2612,
	RE4X_TYPE_AY8910 = 0x8910,
	RE4X_TYPE_SN76489 = 0x76489,
	RE4X_TYPE_YM3812 = 0x3812,
	RE4X_TYPE_YMF262 = 0xf262,
	RE4X_TYPE_YM2413 = 0x2413,
	RE4X_TYPE_YM3526 = 0x3526,
	RE4X_TYPE_YMF288 = 0xf288,
	RE4X_TYPE_SCC = 0x2212,
	RE4X_TYPE_SCCS = 0x2312,
	RE4X_TYPE_Y8950 = 0x3801,
	RE4X_TYPE_YM2164 = 0x2164,		// OPP:OPMとはハードウェアLFOの制御が違う
	RE4X_TYPE_YM2414 = 0x2414,		// OPZ:OPMとピンコンパチ
	RE4X_TYPE_AY8930 = 0x8930,		// APSG:拡張PSG
	RE4X_TYPE_YM2149 = 0x2149,		// SSG:PSGとはDACが違う(YM3439とは同一とみていいと思う)
	RE4X_TYPE_YMZ294 = 0x294,		// SSGL:SSGとはDACが違う(YMZ284とは同一とみていいと思う)
	RE4X_TYPE_SN76496 = 0x76496,	// DCSG:76489とはノイズジェネレータの生成式が違う
	RE4X_TYPE_YM2420 = 0x2420,		// OPLL2:OPLLとはFnumの設定方法が違う。音は同じ。
	RE4X_TYPE_YMF281 = 0xf281,		// OPLLP:OPLLとは内蔵ROM音色が違う。制御は同じ。
	RE4X_TYPE_YMF276 = 0xf276,		// OPN2L:OPN2/OPN2CとはDACが違う
	RE4X_TYPE_YM2602 = 0x2602,		// 315-5124: 76489/76496とはノイズジェネレータの生成式が違う。POWON時に発振しない。
	RE4X_TYPE_UM3567 = 0x3567,		// OPLLのコピー品（だけどDIP24なのでそのままリプレースできない）
	RE4X_TYPE_YMF274 = 0xf274,		// OPL4:試作未定
	RE4X_TYPE_YM3806 = 0x3806,		// OPQ:試作予定
	RE4X_TYPE_YM2163 = 0x2163,		// DSG:試作中
	RE4X_TYPE_YM7129 = 0x7129,		// OPK2:試作中
	RE4X_TYPE_YMZ280 = 0x280,		// PCM8:ADPCM8ch:試作予定
	RE4X_TYPE_YMZ705 = 0x705,		// SSGS:SSG*2set+ADPCM8ch:試作中
	RE4X_TYPE_YMZ735 = 0x735,		// FMS:FM8ch+ADPCM8ch:試作中
	RE4X_TYPE_YM2423 = 0x2423,		// YM2413の音色違い
	RE4X_TYPE_SPC700 = 0xc700,		// SPC700
	RE4X_TYPE_8253 = 0x8253,		// i8253（及び互換チップ用）
	RE4X_TYPE_YMF825 = 0xf825,		// YMF825
	RE4X_TYPE_SAA1099 = 0x1099,	// SAA1099
	RE4X_TYPE_YMF278 = 0xf278,		// OPL4
	RE4X_TYPE_MAX = 0xffffffff,
};

struct RE4X_INTERFACE_INFO
{
	SCCI_INTERFACE_INFO scciInterfaceInfo;
	FT_HANDLE ftHandle;
	FT_DEVICE ftDeviceType;
	BOOL inUse;
	int ftIndex;
	char ftDescription[128];
	char ftSerial_no[128];
};

struct RE4X_SOUND_CHIP_INFO
{
	SCCI_SOUND_CHIP_INFO scciSoundChipInfo;
	RE4X_CHIP_TYPE chipType;
	DWORD chipClock;
	BOOL inUse;
};
