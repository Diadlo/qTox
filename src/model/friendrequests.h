/*
    Copyright © 2019 by The qTox Project Contributors

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FRIEND_REQUESTS_H
#define FRIEND_REQUESTS_H

#include <QObject>
#include "friendrequest.h"

class FirendRequests : public QObject
{
    Q_OBJECT
public:
    void addFriendRequest(const FriendRequest& request);

    const QList<FriendRequest>& getRequests() const;
    void accept(const FriendRequest& request);
    void reject(const FriendRequest& request);

    void markAllAsRead();

signals:
    void requestAdded(const FriendRequest& request);
    void requestAccepted(const FriendRequest& request);
    void requestRejected(const FriendRequest& request);
    void requestChanged(const FriendRequest& request);

private:
    QList<FriendRequest> requests;
};

#endif // FRIEND_REQUESTS_H
