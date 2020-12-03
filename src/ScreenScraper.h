#ifndef RESCRAPE_SCREENSCRAPER_H
#define RESCRAPE_SCREENSCRAPER_H
#include <sstream>
#include <string>
#include <tinyxml2.h>
#include "Hash.h"
#include "Fs.h"

class ScreenScraper {
public:
    void setUsername(const std::string &scraperUsername);
    void setPassword(const std::string &scraperPassword);
    void setDestinationFolder(const std::string &destinationFolder);
    int scrape();

    bool isValid() const;
    std::string dumpXML();
    void downloadAll();
    void setRomFilename(const std::string &filename);
    void setRomHash(const std::string &md5Hash);

    const std::string &getXmlPath() const;

protected:
    bool valid = false;
    std::ostringstream xmlContent;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *data;
    tinyxml2::XMLElement *game;
    tinyxml2::XMLElement *medias;
    tinyxml2::XMLElement *system;
    std::string romFilename;
    std::string romHash;
    std::string xmlPath;
    Hash hash;
    std::string getUrl();
    std::string username;
    std::string password;
    std::string destFolder;
    int gameId;
    int systemId;
    void parseGame();
    void removeUserData();
    void removeServerData();
    void removeMediaContent();
    static void downloadFile(const std::string &url, const std::string &filename);
    void downloadVideo(const std::string &video);
};


#endif //RESCRAPE_SCREENSCRAPER_H

