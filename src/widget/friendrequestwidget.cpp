#include "friendrequestwidget.h"

FriendRequestWidget::FriendRequestWidget(FriendRequest& request, QObject* parent)
    : QWidget(parent)
    , request(request)
{
    const QString& friendAddress = request.address.toString();
    const QString& message = request.message;

    QHBoxLayout* layout = new QHBoxLayout(this);
    QVBoxLayout* horLayout = new QVBoxLayout();
    horLayout->setMargin(0);
    layout->addLayout(horLayout);

    CroppingLabel* friendLabel = new CroppingLabel(this);
    friendLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    friendLabel->setText("<b>" + friendAddress + "</b>");
    horLayout->addWidget(friendLabel);

    QLabel* messageLabel = new QLabel(message);
    // allow to select text, but treat links as plaintext to prevent phishing
    messageLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    messageLabel->setTextFormat(Qt::PlainText);
    messageLabel->setWordWrap(true);
    horLayout->addWidget(messageLabel, 1);

    acceptButton = new QPushButton(this);
    connect(acceptButton, &QPushButton::clicked, this, &FriendRequestWidget::onFriendRequestAccepted);
    layout->addWidget(acceptButton);

    rejectButton = new QPushButton(this);
    connect(rejectButton, &QPushButton::clicked, this, &FriendRequestWidget::onFriendRequestRejected);
    layout->addWidget(rejectButton);

    retranslateUi();
}

void FriendRequestWidget::retranslateUi()
{
    acceptButton->setText(tr("Accept"));
    rejectButton->setText(tr("Reject"));
}

void FriendRequestWidget::onFriendRequestAccepted()
{
    // 'this' will be destroyed after this call
    request.accept();
}

void FriendRequestWidget::onFriendRequestRejected()
{
    // 'this' will be destroyed after this call
    request.reject();
}
