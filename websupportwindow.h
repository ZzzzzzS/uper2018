#ifndef WEBSUPPORTWINDOW_H
#define WEBSUPPORTWINDOW_H

#include <QDialog>
#include <QUrl>

namespace Ui {
class WebSupportWindow;
}

class WebSupportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WebSupportWindow(QWidget *parent = 0,QUrl URL=QUrl(QString("https://zzzzzzs.github.io/")));
    ~WebSupportWindow();


private slots:
    void BackSlot();
    void SetTitleSlot(QString title);
    void LinkChangeSlot(QUrl link);
private:
    int linknumber;
    Ui::WebSupportWindow *ui;
};

#endif // WEBSUPPORTWINDOW_H
