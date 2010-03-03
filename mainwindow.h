#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

class QLabel;
class QPushButton;
class QTextEdit;
class QVBoxLayout;
class QByteArray;
class QString;

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void postClicked();
private:
    QLabel *label;
    QPushButton *postButton;
    QTextEdit *text;
    QVBoxLayout *vLay;

    QByteArray prepareRequest( const QString &data);
};

#endif // MAINWINDOW_H
