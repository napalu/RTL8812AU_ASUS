/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *                                        
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef	__RTW_RF_H_ 
#define __RTW_RF_H_


#define OFDM_PHY		1
#define MIXED_PHY		2
#define CCK_PHY		3

#define NumRates	(13)

// slot time for 11g
#define SHORT_SLOT_TIME					9
#define NON_SHORT_SLOT_TIME				20

#define RTL8711_RF_MAX_SENS 6
#define RTL8711_RF_DEF_SENS 4

//
// We now define the following channels as the max channels in each channel plan.
// 2G, total 14 chnls
// {1,2,3,4,5,6,7,8,9,10,11,12,13,14}
// 5G, total 24 chnls
// {36,40,44,48,52,56,60,64,100,104,108,112,116,120,124,128,132,136,140,149,153,157,161,165}
#define	MAX_CHANNEL_NUM_2G				14
#define	MAX_CHANNEL_NUM_5G				24
#define	MAX_CHANNEL_NUM					38//14+24

//#define NUM_REGULATORYS	21
#define NUM_REGULATORYS	1

//Country codes
#define USA							0x555320
#define EUROPE						0x1 //temp, should be provided later	
#define JAPAN						0x2 //temp, should be provided later	

struct	regulatory_class {
	u32	starting_freq;					//MHz, 
	u8	channel_set[MAX_CHANNEL_NUM];
	u8	channel_cck_power[MAX_CHANNEL_NUM];//dbm
	u8	channel_ofdm_power[MAX_CHANNEL_NUM];//dbm
	u8	txpower_limit;  				//dbm
	u8	channel_spacing;				//MHz
	u8	modem;
};

typedef enum _CAPABILITY{
	cESS			= 0x0001,
	cIBSS			= 0x0002,
	cPollable		= 0x0004,
	cPollReq			= 0x0008,
	cPrivacy		= 0x0010,
	cShortPreamble	= 0x0020,
	cPBCC			= 0x0040,
	cChannelAgility	= 0x0080,
	cSpectrumMgnt	= 0x0100,
	cQos			= 0x0200,	// For HCCA, use with CF-Pollable and CF-PollReq
	cShortSlotTime	= 0x0400,
	cAPSD			= 0x0800,
	cRM				= 0x1000,	// RRM (Radio Request Measurement)
	cDSSS_OFDM	= 0x2000,
	cDelayedBA		= 0x4000,
	cImmediateBA	= 0x8000,
}CAPABILITY, *PCAPABILITY;

enum	_REG_PREAMBLE_MODE{
	PREAMBLE_LONG	= 1,
	PREAMBLE_AUTO	= 2,
	PREAMBLE_SHORT	= 3,
};


enum _RTL8712_RF_MIMO_CONFIG_{
 RTL8712_RFCONFIG_1T=0x10,
 RTL8712_RFCONFIG_2T=0x20,
 RTL8712_RFCONFIG_1R=0x01,
 RTL8712_RFCONFIG_2R=0x02,
 RTL8712_RFCONFIG_1T1R=0x11,
 RTL8712_RFCONFIG_1T2R=0x12,
 RTL8712_RFCONFIG_TURBO=0x92,
 RTL8712_RFCONFIG_2T2R=0x22
};


typedef enum _RF90_RADIO_PATH{
	RF90_PATH_A = 0,			//Radio Path A
	RF90_PATH_B = 1,			//Radio Path B
	RF90_PATH_C = 2,			//Radio Path C
	RF90_PATH_D = 3 		//Radio Path D
	//RF90_PATH_MAX 			//Max RF number 90 support
}RF90_RADIO_PATH_E, *PRF90_RADIO_PATH_E;

// Bandwidth Offset
#define HAL_PRIME_CHNL_OFFSET_DONT_CARE	0
#define HAL_PRIME_CHNL_OFFSET_LOWER	1
#define HAL_PRIME_CHNL_OFFSET_UPPER	2

// Represent Channel Width in HT Capabilities
//
typedef enum _CHANNEL_WIDTH{
	CHANNEL_WIDTH_20 = 0,
	CHANNEL_WIDTH_40 = 1,
	CHANNEL_WIDTH_80 = 2,
	CHANNEL_WIDTH_160 = 3,
	CHANNEL_WIDTH_80_80 = 4,
	CHANNEL_WIDTH_MAX = 5,
}CHANNEL_WIDTH, *PCHANNEL_WIDTH;

//
// Represent Extention Channel Offset in HT Capabilities
// This is available only in 40Mhz mode.
//
typedef enum _EXTCHNL_OFFSET{
	EXTCHNL_OFFSET_NO_EXT = 0,
	EXTCHNL_OFFSET_UPPER = 1,
	EXTCHNL_OFFSET_NO_DEF = 2,
	EXTCHNL_OFFSET_LOWER = 3,
}EXTCHNL_OFFSET, *PEXTCHNL_OFFSET;

typedef enum _VHT_DATA_SC{
	VHT_DATA_SC_DONOT_CARE = 0,
	VHT_DATA_SC_20_UPPER_OF_80MHZ = 1,
	VHT_DATA_SC_20_LOWER_OF_80MHZ = 2,
	VHT_DATA_SC_20_UPPERST_OF_80MHZ = 3,
	VHT_DATA_SC_20_LOWEST_OF_80MHZ = 4,
	VHT_DATA_SC_20_RECV1 = 5,
	VHT_DATA_SC_20_RECV2 = 6,
	VHT_DATA_SC_20_RECV3 = 7,
	VHT_DATA_SC_20_RECV4 = 8,
	VHT_DATA_SC_40_UPPER_OF_80MHZ = 9,
	VHT_DATA_SC_40_LOWER_OF_80MHZ = 10,
}VHT_DATA_SC, *PVHT_DATA_SC_E;

typedef enum _PROTECTION_MODE{
	PROTECTION_MODE_AUTO = 0,
	PROTECTION_MODE_FORCE_ENABLE = 1,
	PROTECTION_MODE_FORCE_DISABLE = 2,
}PROTECTION_MODE, *PPROTECTION_MODE;

/* 2007/11/15 MH Define different RF type. */
typedef	enum _RT_RF_TYPE_DEFINITION
{
	RF_1T2R = 0,
	RF_2T4R = 1,
	RF_2T2R = 2,
	RF_1T1R = 3,
	RF_2T2R_GREEN = 4,
	RF_3T3R = 5,
	RF_4T4R = 6,
	RF_MAX_TYPE = 0xF, /* u1Byte */
}RT_RF_TYPE_DEF_E;



/*RF_2T3R = 5,
		RF_3T3R = 6,
		RF_3T4R = 7,
		RF_4T4R = 8,
		RF_MAX_TYPE = 0xF,*/
u32 rtw_ch2freq(u32 ch);
u32 rtw_freq2ch(u32 freq);


#endif //_RTL8711_RF_H_

