#include "firendrequests.h"

void FriendRequests::addFriendRequest(const FriendRequest& request)
{
    m_requests.append(request);
    emit requestAdded(request);
}

const QList<FriendRequest>& FriendRequests::getRequests() const
{
    return m_requests;
}

void FriendRequests::accept(const FriendRequest& request)
{
    assert(m_requests.contains(request));
    m_requests.removeOne(request);
    emit requestAccepted(request);
}

void FriendRequests::reject(const FriendRequest& request)
{
    assert(m_requests.contains(request));
    m_requests.removeOne(request);
    emit requestRejected(request);
}

void FriendRequests::markAllAsRead()
{
    for (auto& request : m_requests) {
        request.markAsRead();
    }
}
