#include "friendrequest.h"

const ToxPk& FriendRequest::getFriendPk()
{
    return friendPk;
}

const QString& FriendRequest::getMessage()
{
    return message;
}

bool FriendRequest::isRead()
{
    return read;
}

void FriendRequest::markAsRead()
{
    read = true;
    emit read();
}

void FriendRequest::accept()
{
    emit accepted();
}

void FriendRequest::reject()
{
    emit rejected();
}

