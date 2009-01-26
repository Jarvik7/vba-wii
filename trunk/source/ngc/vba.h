/****************************************************************************
 * Visual Boy Advance GX
 *
 * Tantric September 2008
 *
 * vba.h
 *
 * This file controls overall program flow. Most things start and end here!
 ***************************************************************************/
#ifndef _VBAGX_H_
#define _VBAGX_H_

#define APPNAME 		"Visual Boy Advance GX"
#define APPVERSION 		"1.0.6"
#define PREF_FILE_NAME 	"settings.xml"

#define NOTSILENT 0
#define SILENT 1

enum {
	METHOD_AUTO,
	METHOD_SD,
	METHOD_USB,
	METHOD_DVD,
	METHOD_SMB,
	METHOD_MC_SLOTA,
	METHOD_MC_SLOTB,
	METHOD_SD_SLOTA,
	METHOD_SD_SLOTB
};

enum {
	FILE_ROM,
	FILE_SRAM,
	FILE_SNAPSHOT,
	FILE_CHEAT,
	FILE_PREF
};

struct SGCSettings{
    int		AutoLoad;
    int		AutoSave;
    int		LoadMethod; // For ROMS: Auto, SD, DVD, USB, Network (SMB)
	int		SaveMethod; // For SRAM, Freeze, Prefs: Auto, SD, Memory Card Slot A, Memory Card Slot B, USB, SMB
	char	LoadFolder[200]; // Path to game files
	char	SaveFolder[200]; // Path to save files
	char	CheatFolder[200]; // Path to cheat files

	char	smbip[16];
	char	smbuser[20];
	char	smbpwd[20];
	char	smbshare[20];

    int		Zoom; // 0 - off, 1 - on
    float	ZoomLevel; // zoom amount
    int		widescreen;
	int		render;		// 0 - original, 1 - filtered, 2 - unfiltered
	int		VerifySaves;
	int		xshift;		// video output shift
	int		yshift;
};

void ExitToLoader();
void Reboot();
void ShutdownWii();
extern struct SGCSettings GCSettings;
extern int ConfigRequested;
extern int ShutdownRequested;
extern char appPath[];

#endif
