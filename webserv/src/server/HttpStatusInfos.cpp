#include "HttpStatusInfos.hpp"
#include <dirent.h>
#include <iostream>

std::map<int, std::string> HttpStatusInfos::mHttpStatusReasons;
std::map<int, std::string> HttpStatusInfos::mHttpErrorPages;
std::map<std::string, std::string> HttpStatusInfos::mMimeType;
std::string HttpStatusInfos::mWebservRoot;
std::vector<std::string> HttpStatusInfos::mCgiEnv;

HttpStatusInfos::HttpStatusInfos()
{
}

void HttpStatusInfos::initHttpStatusInfos(char **envp)
{
    initHttpStatusReasons();
    initHttpErrorPages();
    initMimeType();
    setWebservRoot(envp);
}

void HttpStatusInfos::initMimeType()
{
    // Text types
    mMimeType[".html"] = "text/html; charset=UTF-8";
    mMimeType[".png"] = "image/png";
    mMimeType[".ico"] = "image/x-icon";

    mMimeType[".txt"] = "text/plain; charset=UTF-8";
    mMimeType[".htm"] = "text/html; charset=UTF-8";
    mMimeType[".shtml"] = "text/html; charset=UTF-8";
    mMimeType[".json"] = "application/json; charset=UTF-8";
    mMimeType[".css"] = "text/css; charset=UTF-8";

    mMimeType[".xml"] = "text/xml; charset=UTF-8";
    mMimeType[".mml"] = "text/mathml";
    mMimeType[".jad"] = "text/vnd.sun.j2me.app-descriptor";
    mMimeType[".wml"] = "text/vnd.wap.wml";
    mMimeType[".htc"] = "text/x-component";

    // Image types
    mMimeType[".gif"] = "image/gif";
    mMimeType[".jpeg"] = "image/jpeg";
    mMimeType[".jpg"] = "image/jpeg";
    mMimeType[".avif"] = "image/avif";
    mMimeType[".svg"] = "image/svg+xml";
    mMimeType[".svgz"] = "image/svg+xml";
    mMimeType[".tif"] = "image/tiff";
    mMimeType[".tiff"] = "image/tiff";
    mMimeType[".wbmp"] = "image/vnd.wap.wbmp";
    mMimeType[".webp"] = "image/webp";
    mMimeType[".jng"] = "image/x-jng";
    mMimeType[".bmp"] = "image/x-ms-bmp";

    // Font types
    mMimeType[".woff"] = "font/woff";
    mMimeType[".woff2"] = "font/woff2";

    // Application types
    mMimeType[".js"] = "application/javascript; charset=UTF-8";
}

void HttpStatusInfos::initHttpStatusReasons()
{
    mHttpStatusReasons[200] = "OK";
    mHttpStatusReasons[201] = "Created";
    mHttpStatusReasons[301] = "Moved Permanently";
    mHttpStatusReasons[307] = "Temporary Redirect";
    mHttpStatusReasons[400] = "Bad Request";
    mHttpStatusReasons[403] = "Forbidden";
    mHttpStatusReasons[404] = "Not Found";
    mHttpStatusReasons[405] = "Method Not Allowed";
    mHttpStatusReasons[408] = "Request Timeout";
    mHttpStatusReasons[413] = "Content Too Large";
    mHttpStatusReasons[500] = "Internal Server Error";
    mHttpStatusReasons[501] = "Not Implemented";
    mHttpStatusReasons[503] = "Service Unavailable";
}

void HttpStatusInfos::initHttpErrorPages()
{
    mHttpErrorPages[301] = "<html>" CRLF "<head><title>301 Moved Permanently</title></head>" CRLF "<body>" CRLF
                           "<center><h1>301 Moved Permanently</h1></center>" CRLF;
    mHttpErrorPages[307] = "<html>" CRLF "<head><title>307 Temporary Redirect</title></head>" CRLF "<body>" CRLF
                           "<center><h1>307 Temporary Redirect</h1></center>" CRLF;
    mHttpErrorPages[400] = "<html>" CRLF "<head><title>400 Bad Request</title></head>" CRLF "<body>" CRLF
                           "<center><h1>400 Bad Request</h1></center>" CRLF;
    mHttpErrorPages[403] = "<html>" CRLF "<head><title>403 Forbbiden</title></head>" CRLF "<body>" CRLF
                           "<center><h1>403 Forbidden</h1></center>" CRLF;
    mHttpErrorPages[404] = "<html>" CRLF "<head><title>404 Not Found</title></head>" CRLF "<body>" CRLF
                           "<center><h1>404 Not Found</h1></center>" CRLF;
    mHttpErrorPages[405] = "<html>" CRLF "<head><title>405 Not Allowed</title></head>" CRLF "<body>" CRLF
                           "<center><h1>405 Not Allowed</h1></center>" CRLF;
    mHttpErrorPages[408] = "<html>" CRLF "<head><title>408 Request Time-out</title></head>" CRLF "<body>" CRLF
                           "<center><h1>408 Request Time-out</h1></center>" CRLF;
    mHttpErrorPages[413] = "<html>" CRLF "<head><title>413 Content Too Large</title></head>" CRLF "<body>" CRLF
                           "<center><h1>413 Content Too Large</h1></center>" CRLF;
    mHttpErrorPages[500] = "<html> " CRLF "<head><title>500 Internal Server Error</title></head>" CRLF "<body>" CRLF
                           "<center><h1>500 Internal Server Error</h1></center>" CRLF;
    mHttpErrorPages[501] = "<html>" CRLF "<head><title>501 Not Implemented</title></head>" CRLF "<body>" CRLF
                           "<center><h1>501 Not Implemented</h1></center>" CRLF;
    mHttpErrorPages[503] = "<html>" CRLF "<head><title>503 Service Temporarily Unavailable</title></head>" CRLF
                           "<body>" CRLF "<center><h1>503 Service Temporarily Unavailable</h1></center>" CRLF;
}

void HttpStatusInfos::setWebservRoot(char **envp)
{
    int i;
    const std::string findStr = "WEBSERV_ROOT=";

    for (i = 0; envp[i] != NULL; ++i)
    {
        std::string envStr = envp[i];
        if (envStr.find(findStr) == 0)
        {
            mWebservRoot = envStr.substr(findStr.size());
            break;
        }
    }
    if (envp[i] == NULL)
    {
        throw std::runtime_error("webserv는 환경변수 WEBSERV_ROOT가 필요합니다.");
    }
}

const std::string HttpStatusInfos::makeAutoIndexPage(const std::string &path)
{
    DIR *dir;
    struct dirent *ent;
    std::string html =
        "<html><head><title>Index of " + path + "</title></head><body><h1>Index of " + path + "</h1><ul>";

    if ((dir = opendir(path.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            html += "<li><a href=\"" + std::string(ent->d_name) + "\">" + std::string(ent->d_name) + "</a></li>";
        }
        closedir(dir);
    }
    else
    {
        html += "<p>Cannot open directory.</p>";
    }

    html += "</ul></body></html>";
    return html;
}

void HttpStatusInfos::addCgiEnv(const std::string &env)
{
    mCgiEnv.push_back(env);
}

char **HttpStatusInfos::allocateNewEnvp()
{
    size_t i;
    char **envpArray = new char *[mCgiEnv.size() + 1];

    for (i = 0; i < mCgiEnv.size(); ++i)
    {
        envpArray[i] = new char[mCgiEnv[i].size() + 1];
        strcpy(envpArray[i], mCgiEnv[i].c_str());
        envpArray[i][mCgiEnv[i].size()] = '\0';
    }
    envpArray[mCgiEnv.size()] = NULL;
    return envpArray;
}

const std::string &HttpStatusInfos::getHttpReason(const int statusCode)
{
    std::map<int, std::string>::const_iterator it;

    it = mHttpStatusReasons.find(statusCode);
    if (it == mHttpStatusReasons.end())
    {
        return mHttpStatusReasons.find(403)->second;
    }
    return it->second;
}

const std::string &HttpStatusInfos::getHttpErrorPage(const int statusCode)
{
    std::map<int, std::string>::const_iterator it;

    it = mHttpErrorPages.find(statusCode);
    if (it == mHttpErrorPages.end())
    {
        return mHttpErrorPages.find(403)->second;
    }
    return it->second;
}

const std::string &HttpStatusInfos::getMimeType(const std::string &type)
{
    std::map<std::string, std::string>::const_iterator it;

    it = mMimeType.find(type);

    if (it == mMimeType.end())
    {
        return mMimeType[".txt"];
    }
    return it->second;
}

const std::string &HttpStatusInfos::getWebservRoot()
{
    return mWebservRoot;
}