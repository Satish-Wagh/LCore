#ifndef CUSTOMFILEDIALOG_H
#define CUSTOMFILEDIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QDir>
#include <QFileSystemModel>
#include <QFileSystemWatcher>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QProcess>
#include <QDesktopWidget>
#include "defineslcore.h"
#include <unistd.h>

namespace Ui {
class CustomFileDialog;
}

class CustomFileDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CustomFileDialog(QWidget *parent = 0);
    ~CustomFileDialog();
    static QString getOpenFileName(const QStringList& Filters);
    static QStringList getOpenFileNames(const QStringList& Filters);
    static QString getOpenDirectory();
    static QString getSaveFileName(const QStringList& Filters, const QString& FilePath);
    void returnSelectedFiles();
    
private slots:
    void on_LV_BrowseArea_doubleClicked(const QModelIndex &index);
    void on_PB_Cancel_clicked();
    void on_PB_navigateForward_clicked();
    void on_PB_navigateBackward_clicked();
    void on_PB_parentDirectory_clicked();
    void on_PB_Open_clicked();
    void on_PB_IconView_clicked();
    void on_PB_ListView_clicked();
    void on_TV_BrowseArea_doubleClicked(const QModelIndex &index);
    void on_CB_FilesTypes_activated(const QString &arg1);
    void on_CB_pathHistory_activated(const QString &arg1);
    void on_LW_SideBar_itemClicked(QListWidgetItem *item);
    void on_LV_BrowseArea_clicked(const QModelIndex &index);
    void on_TV_BrowseArea_clicked(const QModelIndex &index);
    void directoryModified(QString dirPath);

private:
    Ui::CustomFileDialog *ui = nullptr;
    QFileSystemModel *Iconfilesysmodel = nullptr;
    QFileSystemWatcher *filesyswatcher = nullptr;
    QStringList filesSelected = QStringList();
    QStringList addresshistoryList = QStringList();
    signed int FolderSelectionMode = 0;
    QStringList FileNameFilters  = QStringList();
    QString SaveFile = "";
    void initDialog(const QStringList &FilesFilter, signed int fileFolder, QString fileName);
    void LoadFileDialog(int SelectionMode, int FolderSelection, QStringList FilesFilter);
    void loadAbstractView(QModelIndex index);
    void refreshAddressBar(QStringList addressList);
};

#endif // CUSTOMFILEDIALOG_H
