#ifndef PANDORY_MODEDXSTICK_H
#define PANDORY_MODEDXSTICK_H
#include "Fs.h"
#include "Hash.h"
#include "definitions/DXPatches.h"

class ModeDXStick {
protected:
    Fs fs;
    Hash hash;
    DXPatches dxPatches;
    bool downloadPatchFile(const std::string &patchName, const std::string &target);
    void downloadFile(const std::string &url, const std::string &filename);
    bool backup(const std::string &srcFolder, const std::string &srcFile, const std::string &backupFolder);
    bool replaceZip(std::string &path);
public:
    int startDXPatch(std::string &target);
};

#endif //PANDORY_MODEDXSTICK_H
