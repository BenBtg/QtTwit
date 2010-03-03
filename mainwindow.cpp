#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{

    postButton = new QPushButton("Post!",this);
    label = new QLabel("Twitter",this);
    text = new QTextEdit(this);
    this->setWindowTitle("QTwitter Client");

    vLay = new QVBoxLayout();

    vLay->addWidget(text);
    vLay->addWidget(postButton);
    vLay->addWidget(label);

    QObject::connect(postButton, SIGNAL(clicked()), this, SLOT(postClicked()));

    this->setLayout(vLay);
}

MainWindow::~MainWindow()
{

}

void MainWindow::postClicked()
{
    // Send tweet
    const QString statusUpdateUrl = "http://api.twitter.com/1/statuses/update.json";

    QNetworkAccessManager networkAccess;
    QNetworkRequest request;
    request.setUrl( QUrl(statusUpdateUrl) );

    QByteArray auth = QString("username").toUtf8() + ":" + QString("password").toUtf8();
    
    QByteArray auth2 = auth.toBase64().prepend( "Basic " );

    request.setRawHeader("Authorization", auth2);
    QByteArray content;
    content = prepareRequest(text->toPlainText());
    networkAccess.post(request, content);

    /*QDialog dlg;
    QVBoxLayout vBox;
    QLabel label("Post sent!");
    vBox.addWidget(label);

    dlg.setLayout(vBox);
    dlg.show();*/
}

QByteArray MainWindow::prepareRequest( const QString &data)
{
    QByteArray request( "status=" );
    request.append( data.toUtf8().toPercentEncoding() );    
    request.append( "&source=qtwitter" );
    return request;
}
