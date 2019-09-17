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

#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

#include "src/core/toxid.h"
#include <QString>

class FriendRequest : public QObject
{
    Q_OBJECT
public:
    FriendRequest(const ToxPk& friendPk, const QString& message, bool read)

    const ToxPk& getFriendPk() const;
    const QString& getMessage() const;

    bool isRead() const;
    void markAsRead();

    void accept();
    void reject();

signal:
    void read();
    void accepted();
    void rejected();

private:
    ToxPk friendPk;
    QString message;
    bool read;
};

#endif // FRIEND_REQUEST_H