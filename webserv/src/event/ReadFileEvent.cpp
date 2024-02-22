#include "ReadFileEvent.hpp"
#include "HttpStatusInfos.hpp"
#include "Kqueue.hpp"
#include "WriteEvent.hpp"
#include <sys/event.h>
#include <unistd.h>

ReadFileEvent::ReadFileEvent(const Server &server, const Response &response, int clientSocket, int fileFd, int fileSize)
    : AEvent(server, response, clientSocket), mFileFd(fileFd), mFileSize(fileSize), mReadSize(0), mBody("")
{
}
ReadFileEvent::~ReadFileEvent()
{
}

void ReadFileEvent::handle()
{
    int n = read(mFileFd, mBuffer, BUFFER_SIZE);

    if (n < 0)
    {
        Kqueue::deleteEvent(mFileFd, EVFILT_TIMER);
        close(mFileFd);
        delete this;
        return;
    }
    mReadSize += n;
    mBody.append(mBuffer, n);
    if (mReadSize == mFileSize)
    {
        Kqueue::deleteEvent(mFileFd, EVFILT_TIMER);
        close(mFileFd);
        mResponse.setBody(mBody);

        struct kevent newEvent;
        EV_SET(&newEvent, mClientSocket, EVFILT_WRITE, EV_ADD, 0, 0, new WriteEvent(mServer, mResponse, mClientSocket));
        Kqueue::addEvent(newEvent);
        delete this;
    }
}

void ReadFileEvent::timer()
{
    const std::string &errorPage = HttpStatusInfos::getHttpErrorPage(408);
    mResponse.setStartLine(408);
    mResponse.addHead("Content-type", "text/html");
    mResponse.addHead("Content-Length", errorPage.size());
    mResponse.setBody(errorPage);
    struct kevent newEvent;
    EV_SET(&newEvent, mClientSocket, EVFILT_WRITE, EV_ADD, 0, 0, new WriteEvent(mServer, mResponse, mClientSocket));
    Kqueue::addEvent(newEvent);

    Kqueue::deleteEvent(mFileFd, EVFILT_TIMER);
    close(mFileFd);
    delete this;
}