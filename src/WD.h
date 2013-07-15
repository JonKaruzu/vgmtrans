#pragma once
#include "VGMInstrSet.h"
#include "VGMSampColl.h"
#include "VGMRgn.h"

class WDInstr;

static const int finetune_table[256] = { 0x10000, 0x1000E, 0x1001D, 0x1002C, 0x1003B, 0x10049, 0x10058, 0x10067, 0x10076, 0x10085, 0x10094,
							0x100A2, 0x100B1, 0x100C0, 0x100CF, 0x100DE, 0x100ED, 0x100FB, 0x1010A, 0x10119, 0x10128, 0x10137,
							0x10146, 0x10154, 0x10163, 0x10172, 0x10181, 0x10190, 0x1019F, 0x101AE, 0x101BD, 0x101CC, 0x101DA,
							0x101E9, 0x101F8, 0x10207, 0x10216, 0x10225, 0x10234, 0x10243, 0x10252, 0x10261, 0x10270, 0x1027E,
							0x1028D, 0x1029C, 0x102AB, 0x102BA, 0x102C9, 0x102D8, 0x102E7, 0x102F6, 0x10305, 0x10314, 0x10323,
							0x10332, 0x10341, 0x10350, 0x1035F, 0x1036E, 0x1037D, 0x1038C, 0x1039B, 0x103AA, 0x103B9, 0x103C8,
							0x103D7, 0x103E6, 0x103F5, 0x10404, 0x10413, 0x10422, 0x10431, 0x10440, 0x1044F, 0x1045E, 0x1046D,
							0x1047C, 0x1048B, 0x1049A, 0x104A9, 0x104B8, 0x104C7, 0x104D6, 0x104E5, 0x104F5, 0x10504, 0x10513,
							0x10522, 0x10531, 0x10540, 0x1054F, 0x1055E, 0x1056D, 0x1057C, 0x1058B, 0x1059B, 0x105AA, 0x105B9,
							0x105C8, 0x105D7, 0x105E6, 0x105F5, 0x10604, 0x10614, 0x10623, 0x10632, 0x10641, 0x10650, 0x1065F,
							0x1066E, 0x1067E, 0x1068D, 0x1069C, 0x106AB, 0x106BA, 0x106C9, 0x106D9, 0x106E8, 0x106F7, 0x10706,
							0x10715, 0x10725, 0x10734, 0x10743, 0x10752, 0x10761, 0x10771, 0x10780, 0x1078F, 0x1079E, 0x107AE,
							0x107BD, 0x107CC, 0x107DB, 0x107EA, 0x107FA, 0x10809, 0x10818, 0x10827, 0x10837, 0x10846, 0x10855,
							0x10865, 0x10874, 0x10883, 0x10892, 0x108A2, 0x108B1, 0x108C0, 0x108D0, 0x108DF, 0x108EE, 0x108FD,
							0x1090D, 0x1091C, 0x1092B, 0x1093B, 0x1094A, 0x10959, 0x10969, 0x10978, 0x10987, 0x10997, 0x109A6,
							0x109B5, 0x109C5, 0x109D4, 0x109E3, 0x109F3, 0x10A02, 0x10A12, 0x10A21, 0x10A30, 0x10A40, 0x10A4F,
							0x10A5E, 0x10A6E, 0x10A7D, 0x10A8D, 0x10A9C, 0x10AAB, 0x10ABB, 0x10ACA, 0x10ADA, 0x10AE9, 0x10AF8,
							0x10B08, 0x10B17, 0x10B27, 0x10B36, 0x10B46, 0x10B55, 0x10B64, 0x10B74, 0x10B83, 0x10B93, 0x10BA2,
							0x10BB2, 0x10BC1, 0x10BD1, 0x10BE0, 0x10BF0, 0x10BFF, 0x10C0F, 0x10C1E, 0x10C2E, 0x10C3D, 0x10C4D,
							0x10C5C, 0x10C6C, 0x10C7B, 0x10C8B, 0x10C9A, 0x10CAA, 0x10CB9, 0x10CC9, 0x10CD8, 0x10CE8, 0x10CF7,
							0x10D07, 0x10D16, 0x10D26, 0x10D35, 0x10D45, 0x10D55, 0x10D64, 0x10D74, 0x10D83, 0x10D93, 0x10DA2,
							0x10DB2, 0x10DC1, 0x10DD1, 0x10DE1, 0x10DF0, 0x10E00, 0x10E0F, 0x10E1F, 0x10E2F, 0x10E3E, 0x10E4E,
							0x10E5D, 0x10E6D, 0x10E7D, 0x10E8C, 0x10E9C, 0x10EAC, 0x10EBB, 0x10ECB, 0x10EDB, 0x10EEA, 0x10EFA,
							0x10F09, 0x10F19, 0x10F29 };

// **********
// WDInstrSet
// **********

class WDInstrSet
	: public VGMInstrSet
{
public:
	WDInstrSet(RawFile* file, ULONG offset);
	virtual ~WDInstrSet(void);

	virtual int GetHeaderInfo();
	virtual int GetInstrPointers();

public:
	DWORD dwSampSectOffset;
	DWORD dwSampSectSize;
	DWORD dwNumInstrs;
	DWORD dwTotalRegions;
};


// *******
// WDInstr
// *******

class WDInstr
	: public VGMInstr
{
public:
	WDInstr(VGMInstrSet* instrSet, ULONG offset, ULONG length, ULONG theBank, ULONG theInstrNum, wstring name);
	virtual ~WDInstr(void);
	virtual int LoadInstr();

protected:
	int info_ptr;		//pointer to start of instrument set block
	int nNumRegions;	
};


// *****
// WDRgn
// *****

class WDRgn
	: public VGMRgn
{
public:
	WDRgn(WDInstr* instr, ULONG offset);

public:
	unsigned short ADSR1;				//raw ps2 ADSR1 value (articulation data)
	unsigned short ADSR2;				//raw ps2 ADSR2 value (articulation data)
	unsigned char bStereoRegion;
	unsigned char StereoPairOrder;
	unsigned char bFirstRegion;
	unsigned char bLastRegion;
	unsigned char bUnknownFlag2;
};
