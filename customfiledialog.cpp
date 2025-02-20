#include "customfiledialog.h"
#include "ui_customfiledialog.h"
#include<QTranslator>

CustomFileDialog::CustomFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomFileDialog)
{
    qDebug() << "CustomFileDialog::3:: Constructor Called .";
    qDebug() << "CustomFileDialog::1:: CustomFileDialog window invoked .";

    QFile File("/usr/os-bin/qss/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    File.close();
    setStyleSheet(StyleSheet);

    ui->setupUi(this);

    QTranslator translator;
    translator.load(QString(TRANSLATIONLINK) + "/LCore.qm");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);

    setWindowTitle(tr("Open"));

    QDesktopWidget *dw = qApp->desktop();
    QRect rect = dw->screenGeometry(dw->screenNumber(QCursor::pos()));
    setGeometry(rect.x()+((rect.width()-width())/2), rect.y()+((rect.height()-height())/2), width(), height());

    ui->PB_navigateBackward->setToolTip(tr("Back"));
    ui->PB_navigateForward->setToolTip(tr("Forward"));
    ui->PB_parentDirectory->setToolTip(tr("Parent Directory"));
    ui->PB_IconView->setToolTip(tr("Icon View"));
    ui->PB_ListView->setToolTip(tr("Detail View"));

}

CustomFileDialog::~CustomFileDialog()
{
    qDebug() << "CustomFileDialog::3:: Destructor Called .";
    delete Iconfilesysmodel;
    Iconfilesysmodel = NULL;

    delete filesyswatcher;
    filesyswatcher = NULL;

    qDebug() << "CustomFileDialog::1:: CustomFileDialog window invoked .";
    delete ui;
}

void CustomFileDialog::initDialog(const QStringList& FilesFilter, signed int fileFolder, QString fileName)
{
    qDebug() << "CustomFileDialog:initDialog::3:: Start .";

    QTranslator translator;
    translator.load(QString(TRANSLATIONLINK) + "/LCore.qm");
    qApp->installTranslator(&translator);
    Iconfilesysmodel = NULL;
    filesyswatcher = NULL;

    FolderSelectionMode = fileFolder;
    FileNameFilters = FilesFilter;

    if(FolderSelectionMode == 1)
    {
        ui->LB_FolderFile->setText(tr("Folder Name:"));
        ui->LB_FileTypes->hide();
        ui->CB_FilesTypes->hide();

        setMaximumSize(width(), height()-25);
        setMinimumSize(width(), height());
    }
    else if(FolderSelectionMode == 0)
    {
        ui->LB_FolderFile->setText(tr("File Name:"));
        ui->LB_FileTypes->show();
        ui->LB_FileTypes->setText(tr("File of Types:"));
        ui->CB_FilesTypes->show();

        setMaximumSize(width(), height());
        setMinimumSize(width(), height());
    }
    else if(FolderSelectionMode == -1)
    {
        QString tmpStr;
        if(FileNameFilters.count())
        {
            tmpStr = FileNameFilters.at(0).section("(", 1, 1);
            tmpStr.chop(1);
            tmpStr = tmpStr.split(" ").at(0);
            qDebug() << "Extension: " << tmpStr;
            ui->LE_selectedFilesFolders->setText(fileName);
        }

        ui->PB_Open->setText(tr("Save"));
        ui->LB_FolderFile->setText(tr("File Name:"));
        ui->LB_FileTypes->show();
        ui->CB_FilesTypes->show();
        ui->LB_FileTypes->setText(tr("File of Types:"));

        setMaximumSize(width(), height());
        setMinimumSize(width(), height());
    }

    ui->PB_IconView->setChecked(false);
    ui->LV_BrowseArea->hide();
    ui->PB_ListView->setChecked(true);
    ui->TV_BrowseArea->show();

    ui->PB_navigateForward->setEnabled(false);
    ui->PB_navigateBackward->setEnabled(false);
    ui->PB_parentDirectory->setEnabled(false);

    if(FolderSelectionMode == -1)
        ui->PB_Open->setEnabled(true);
    else
        ui->PB_Open->setEnabled(false);

    qDebug() << "CustomFileDialog:initDialog::3:: End .";
}

QString CustomFileDialog::getOpenFileName(const QStringList &Filters)
{
    qDebug() << "CustomFileDialog:getOpenFileName::3:: Start .";

    CustomFileDialog cfd;

    cfd.initDialog(Filters, 0, ""); // 0 - Files

    QStringList strlistFilters;

    if(Filters.count())
    {
        QString tmpstr = Filters.at(0).section("(", 1, 1);
        tmpstr.chop(1);
        strlistFilters = tmpstr.split(" ");
    }

    qDebug() << "Filter " << strlistFilters;

    cfd.LoadFileDialog(0, 0, strlistFilters);

    if(cfd.exec() == QDialog::Accepted)
    {
        if(cfd.filesSelected.count())
            return cfd.filesSelected.at(0);
    }

    qDebug() << "CustomFileDialog:getOpenFileName::3:: End .";
    return "";
}

QStringList CustomFileDialog::getOpenFileNames(const QStringList& Filters)
{
    qDebug() << "CustomFileDialog:getOpenFileNames::3:: Start .";

    CustomFileDialog cfd;

    cfd.initDialog(Filters, 0, ""); // 0 - Files

    QStringList strlistFilters;

    if(Filters.count())
    {
        QString tmpstr = Filters.at(0).section("(", 1, 1);
        tmpstr.chop(1);
        strlistFilters = tmpstr.split(" ");
    }

    qDebug() << "Filter " << strlistFilters;

    cfd.LoadFileDialog(1, 0, strlistFilters);

    if(cfd.exec() == QDialog::Accepted)
    {
        if(cfd.filesSelected.count())
            return cfd.filesSelected;
    }

    qDebug() << "CustomFileDialog:getOpenFileNames::3:: End .";
    return QStringList("");
}


QString CustomFileDialog::getOpenDirectory()
{
    qDebug() << "CustomFileDialog:getOpenDirectory::3:: Start .";
    CustomFileDialog cfd;

    cfd.initDialog(QStringList(""), 1, "");
    cfd.LoadFileDialog(0, 1, QStringList(""));

    if(cfd.exec() == QDialog::Accepted)
    {
        if(cfd.filesSelected.count())
            return cfd.filesSelected.at(0);
    }

    qDebug() << "CustomFileDialog:getOpenDirectory::3:: End .";
    return "";
}


QString CustomFileDialog::getSaveFileName(const QStringList &Filters, const QString &FilePath)
{
    qDebug() << "CustomFileDialog:getSaveFileName::3:: Start .";

    CustomFileDialog cfd;

    cfd.initDialog(Filters, -1, FilePath.section("/", -1, -1));

    QStringList strlistFilters;

    if(Filters.count())
    {
        QString tmpstr = Filters.at(0).section("(", 1, 1);
        tmpstr.chop(1);
        strlistFilters = tmpstr.split(" ");
    }

    cfd.LoadFileDialog(0, 0, strlistFilters);

    qDebug() << "CustomFileDialog:getSaveFileName::3:: File Path: " << FilePath;

    cfd.SaveFile = FilePath;

    if(cfd.exec() == QDialog::Accepted)
    {
        if(cfd.filesSelected.count())
            return cfd.filesSelected.at(0);
    }

    qDebug() << "CustomFileDialog:getSaveFileName::3:: End .";
    return "";
}


void CustomFileDialog::LoadFileDialog(int SelectionMode, int FolderSelection, QStringList FilesFilter)
{
    qDebug() << "CustomFileDialog:LoadFileDialog::3:: Start .";
    if(!SelectionMode)
    {
        ui->LV_BrowseArea->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->TV_BrowseArea->setSelectionMode(QAbstractItemView::SingleSelection);
    }
    else
    {
        ui->LV_BrowseArea->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ui->TV_BrowseArea->setSelectionMode(QAbstractItemView::ExtendedSelection);
    }


    QDir checkdir;
    QListWidgetItem *lwitm;

    addresshistoryList.clear();

    filesyswatcher = new QFileSystemWatcher(this);
    connect(filesyswatcher, SIGNAL(directoryChanged(QString)), this, SLOT(directoryModified(QString)));

    if(checkdir.exists("/home/"))
    {
        addresshistoryList << "/home";

        lwitm = new QListWidgetItem(ui->LW_SideBar);
        lwitm->setText(tr("Home"));
        lwitm->setIcon(QIcon("/usr/os-bin/images/folder.png"));
        ui->LW_SideBar->addItem(lwitm);
    }

    if(checkdir.exists(DRIVES_PATH))
    {
        addresshistoryList << "/media";

        lwitm = new QListWidgetItem(ui->LW_SideBar);
        lwitm->setText(tr("Media"));
        lwitm->setIcon(QIcon("/usr/os-bin/images/folder.png"));
        ui->LW_SideBar->addItem(lwitm);
    }

    if(checkdir.exists(SMB_PATH))
    {
        lwitm = new QListWidgetItem(ui->LW_SideBar);
        lwitm->setText(tr("SMB"));
        lwitm->setIcon(QIcon("/usr/os-bin/images/folder.png"));
        ui->LW_SideBar->addItem(lwitm);
    }

    if(checkdir.exists(NFS_PATH))
    {
        lwitm = new QListWidgetItem(ui->LW_SideBar);
        lwitm->setText(tr("NFS"));
        lwitm->setIcon(QIcon("/usr/os-bin/images/folder.png"));
        ui->LW_SideBar->addItem(lwitm);
    }

    if(checkdir.exists(USB_PATH))
    {
        lwitm = new QListWidgetItem(ui->LW_SideBar);
        lwitm->setText(tr("USB"));
        lwitm->setIcon(QIcon("/usr/os-bin/images/folder.png"));
        ui->LW_SideBar->addItem(lwitm);
    }

    if(checkdir.exists(CDROM_PATH))
    {
        lwitm = new QListWidgetItem(ui->LW_SideBar);
        lwitm->setText(tr("CDROM"));
        lwitm->setIcon(QIcon("/usr/os-bin/images/folder.png"));
        ui->LW_SideBar->addItem(lwitm);
    }

    if(checkdir.exists("/home/") || checkdir.exists(DRIVES_PATH))
    {
        Iconfilesysmodel = new QFileSystemModel;

        if(FolderSelection)
            Iconfilesysmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
        else
            Iconfilesysmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);

        Iconfilesysmodel->setNameFilters(FilesFilter);
        Iconfilesysmodel->setNameFilterDisables(false);
        ui->CB_FilesTypes->addItems(FileNameFilters);
        ui->LV_BrowseArea->setModel(Iconfilesysmodel);
        ui->TV_BrowseArea->setModel(Iconfilesysmodel);

        Iconfilesysmodel->setRootPath("/");

        refreshAddressBar(addresshistoryList);

        if(checkdir.exists(DRIVES_PATH))
            loadAbstractView(Iconfilesysmodel->index(DRIVES_PATH, 0));
        else if(checkdir.exists("/root/"))
            loadAbstractView(Iconfilesysmodel->index("/root", 0));
    }
    qDebug() << "CustomFileDialog:LoadFileDialog::3:: End .";
}

void CustomFileDialog::refreshAddressBar(QStringList addressList)
{
    qDebug() << "CustomFileDialog:refreshAddressBar::3:: Start .";
    ui->CB_pathHistory->clear();
    ui->CB_pathHistory->addItems(addressList);
    ui->CB_pathHistory->setCurrentIndex(addressList.count()-1);
    qDebug() << "CustomFileDialog:refreshAddressBar::3:: End .";
}

void CustomFileDialog::loadAbstractView(QModelIndex index)
{
    qDebug() << "CustomFileDialog:loadAbstractView::3:: Start .";

    QTranslator translator;
    translator.load(QString(TRANSLATIONLINK) + "/LCore.qm");
    qApp->installTranslator(&translator);

    if(ui->PB_Open->text() == tr("Open"))
        ui->LE_selectedFilesFolders->clear();

    if(Iconfilesysmodel->fileInfo(index).isDir())
    {
        if(filesyswatcher->directories().count())
            filesyswatcher->removePaths(filesyswatcher->directories());

        QString CurrentDir = Iconfilesysmodel->fileInfo(index).absoluteFilePath();

        filesyswatcher->addPath(CurrentDir);

        if(!ui->PB_navigateBackward->isEnabled())
            ui->PB_navigateBackward->setEnabled(true);

        if(CurrentDir.count("/") > 1)
        {
            ui->PB_parentDirectory->setEnabled(true);
        }
        else
        {
            ui->PB_parentDirectory->setEnabled(false);
        }

        int searchHistory = addresshistoryList.indexOf(CurrentDir, 0);

        if(searchHistory == -1)
        {
            addresshistoryList << CurrentDir;
            refreshAddressBar(addresshistoryList);
        }
        else
        {
            if(searchHistory == addresshistoryList.count()-1)
                ui->PB_navigateForward->setEnabled(false);

            if(searchHistory == 0)
                ui->PB_navigateBackward->setEnabled(false);

            ui->CB_pathHistory->setCurrentIndex(searchHistory);
        }

        if(CurrentDir.startsWith(QString(SMB_PATH).remove(QString(SMB_PATH).count()-1, 1)))
        {
            if(ui->LW_SideBar->findItems(tr("SMB"), Qt::MatchExactly).count())
                ui->LW_SideBar->findItems(tr("SMB"), Qt::MatchExactly).at(0)->setSelected(true);
        }
        else if(CurrentDir.startsWith(QString(NFS_PATH).remove(QString(NFS_PATH).count()-1, 1)))
        {
            if(ui->LW_SideBar->findItems(tr("NFS"), Qt::MatchExactly).count())
                ui->LW_SideBar->findItems(tr("NFS"), Qt::MatchExactly).at(0)->setSelected(true);
        }
        else if(CurrentDir.startsWith(QString(USB_PATH).remove(QString(USB_PATH).count()-1, 1)))
        {
            if(ui->LW_SideBar->findItems(tr("USB"), Qt::MatchExactly).count())
                ui->LW_SideBar->findItems(tr("USB"), Qt::MatchExactly).at(0)->setSelected(true);
        }
        else if(CurrentDir.startsWith(QString(CDROM_PATH).remove(QString(CDROM_PATH).count()-1, 1)))
        {
            if(ui->LW_SideBar->findItems(tr("CDROM"), Qt::MatchExactly).count())
                ui->LW_SideBar->findItems(tr("CDROM"), Qt::MatchExactly).at(0)->setSelected(true);
        }
        else if(CurrentDir.startsWith(QString(DRIVES_PATH).remove(QString(DRIVES_PATH).count()-1, 1)))
        {
            if(ui->LW_SideBar->findItems(tr("Media"), Qt::MatchExactly).count())
                ui->LW_SideBar->findItems(tr("Media"), Qt::MatchExactly).at(0)->setSelected(true);
        }

        ui->LV_BrowseArea->setRootIndex(index);
        ui->TV_BrowseArea->setRootIndex(index);
    }
    else
        returnSelectedFiles();

    qDebug() << "CustomFileDialog:loadAbstractView::3:: End .";
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_LV_BrowseArea_doubleClicked(const QModelIndex &index)
{
    loadAbstractView(index);
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_TV_BrowseArea_doubleClicked(const QModelIndex &index)
{
    loadAbstractView(index);
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_PB_navigateForward_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_navigateForward_clicked::3:: Forword Button Clicked .";
    int searchHistory = addresshistoryList.indexOf(ui->CB_pathHistory->currentText(), 0);

    if(searchHistory != -1 && searchHistory != addresshistoryList.count()-1)
    {
        if(!ui->PB_navigateBackward->isEnabled())
            ui->PB_navigateBackward->setEnabled(true);

        loadAbstractView(Iconfilesysmodel->index(addresshistoryList.at(searchHistory+1), 0));

        if(searchHistory+1 == addresshistoryList.count()-1)
            ui->PB_navigateForward->setEnabled(false);

    }
    qDebug() << "CustomFileDialog:on_PB_navigateForward_clicked::3:: Forward Button End .";
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_PB_navigateBackward_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_navigateBackward_clicked::3:: Backward Button Clicked .";
    int searchHistory = addresshistoryList.indexOf(ui->CB_pathHistory->currentText(), 0);

    if(searchHistory > 0)
    {
        if(!ui->PB_navigateForward->isEnabled())
            ui->PB_navigateForward->setEnabled(true);

        loadAbstractView(Iconfilesysmodel->index(addresshistoryList.at(searchHistory-1), 0));

        if(searchHistory-1 == 0)
            ui->PB_navigateBackward->setEnabled(false);
    }
    qDebug() << "CustomFileDialog:on_PB_navigateBackward_clicked::3:: Backward Button End .";
}

void CustomFileDialog::on_PB_parentDirectory_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_parentDirectory_clicked::3:: Parent directory Button Clicked .";
    QString currentDir = ui->CB_pathHistory->currentText();

    if(currentDir.count("/") > 1)
    {
        QString parentDir = currentDir.remove("/"+currentDir.section("/", -1, -1));
        qDebug() << "CustomFileDialog:on_PB_parentDirectory_clicked::3:: Parent Dir: " << parentDir;
        loadAbstractView(Iconfilesysmodel->index(parentDir, 0));
    }
    qDebug() << "CustomFileDialog:on_PB_parentDirectory_clicked::3:: Parent directory Button End .";
}

void CustomFileDialog::returnSelectedFiles()
{ 
    qDebug() << "CustomFileDialog:returnSelectedFiles::3:: Start.";
    QTranslator translator;
    translator.load(QString(TRANSLATIONLINK) + "/LCore.qm");
    qApp->installTranslator(&translator);

    if(ui->PB_Open->text() == tr("Open"))
    {
        bool returnCondition = false;
        QModelIndexList indexlist;

        if(ui->LV_BrowseArea->isVisible())
            indexlist = ui->LV_BrowseArea->selectionModel()->selectedIndexes();
        else
            indexlist = ui->TV_BrowseArea->selectionModel()->selectedRows(0);

        if(!FolderSelectionMode)
        {
            if(indexlist.count())
            {
                if(Iconfilesysmodel->fileInfo(indexlist.at(0)).isDir())
                    loadAbstractView(indexlist.at(0));
                else if(Iconfilesysmodel->fileInfo(indexlist.at(0)).isFile())
                    returnCondition = true;
            }
        }
        else
        {
            returnCondition = true;
        }

        filesSelected.clear();

        if(returnCondition)
        {
            if(!FolderSelectionMode)
            {
                for(int i=0; i<indexlist.count(); i++)
                {
                    if(!Iconfilesysmodel->fileInfo(indexlist.at(i)).isFile())
                    {
                        QMessageBox::information(this, tr("Invalid Selection"), tr("Please select files only."));
                        return;
                    }

                }
            }

            for(int i=0; i<indexlist.count(); i++)
            {
                filesSelected.append(Iconfilesysmodel->fileInfo(indexlist.at(i)).absoluteFilePath());
            }

            accept();
        }
    }
    else if(ui->PB_Open->text() == tr("Save"))
    {
        filesSelected.clear();

        if(ui->LE_selectedFilesFolders->text().isEmpty())
        {
            QMessageBox::information(this, tr("Save File"), tr("Please  provide a valid file name."));
            return;
        }

        QString tmpStr = ui->CB_pathHistory->currentText()+"/"+ui->LE_selectedFilesFolders->text();
        qDebug() << "CustomFileDialog:returnSelectedFiles::3:: save file" << SaveFile << tmpStr;

        if(QProcess::execute("cp -f \""+SaveFile+"\" \""+tmpStr+"\"") == 0)
            tmpStr = "true";
        else
            tmpStr = "false";
        sync();

        if(tmpStr == "true")
        {
            filesSelected << ui->CB_pathHistory->currentText()+"/"+ui->LE_selectedFilesFolders->text();
            accept();
        }
        else
        {
            QMessageBox::information(this, tr("Save File"), tr("Unable to save file, Please try again."));
            return;
        }
    }

    qDebug() << "CustomFileDialog:returnSelectedFiles::3:: End.";
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_PB_IconView_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_IconView_clicked::3:: Icon View Button clicked.";
    ui->PB_IconView->setChecked(true);
    if(ui->PB_ListView->isChecked())
    {
        ui->PB_ListView->setChecked(false);
        ui->TV_BrowseArea->hide();
    }

    ui->LV_BrowseArea->show();

    qDebug() << "CustomFileDialog:on_PB_IconView_clicked::3:: Icon View Button End.";
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_PB_ListView_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_ListView_clicked::3:: List View Button clicked.";
    ui->PB_ListView->setChecked(true);

    if(ui->PB_IconView->isChecked())
    {
        ui->PB_IconView->setChecked(false);
        ui->LV_BrowseArea->hide();
    }

    ui->TV_BrowseArea->show();

    qDebug() << "CustomFileDialog:on_PB_ListView_clicked::3:: List View Button End.";
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_PB_Open_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_Open_clicked::3:: Open Button clicked.";
    returnSelectedFiles();
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_PB_Cancel_clicked()
{
    qDebug() << "CustomFileDialog:on_PB_Cancel_clicked::3:: Cancel Button clicked.";
    reject();
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_CB_FilesTypes_activated(const QString &arg1)
{
    qDebug() << "CustomFileDialog:on_CB_FilesTypes_activated::3:: clicked.";
    QString tmpstr="";

    tmpstr = arg1.section("(", 1, 1);
    tmpstr.chop(1);
    QStringList FilesFilter = tmpstr.split(" ");

    Iconfilesysmodel->setNameFilters(FilesFilter);
    loadAbstractView(Iconfilesysmodel->index(ui->CB_pathHistory->currentText(), 0));

    qDebug() << "CustomFileDialog:on_CB_FilesTypes_activated::3:: End.";
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_CB_pathHistory_activated(const QString &arg1)
{
    loadAbstractView(Iconfilesysmodel->index(arg1, 0));
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_LW_SideBar_itemClicked(QListWidgetItem *item)
{
    QString HomeDir="";

    if(item->text() == tr("Home"))
        HomeDir = "/home/";
    else if(item->text() == tr("Media"))
        HomeDir = DRIVES_PATH;
    else if(item->text() == tr("SMB"))
        HomeDir = SMB_PATH;
    else if(item->text() == tr("NFS"))
        HomeDir = NFS_PATH;
    else if(item->text() == tr("USB"))
        HomeDir = USB_PATH;
    else if(item->text() == tr("CDROM"))
        HomeDir = CDROM_PATH;

    loadAbstractView(Iconfilesysmodel->index(HomeDir, 0));
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_LV_BrowseArea_clicked(const QModelIndex &index)
{
    QTranslator translator;
    translator.load(QString(TRANSLATIONLINK) + "/LCore.qm");
    qApp->installTranslator(&translator);

    if(index.isValid() && ui->PB_Open->text() == tr("Open"))
    {
        ui->PB_Open->setEnabled(true);

        if(FolderSelectionMode && Iconfilesysmodel->fileInfo(index).isDir())
            ui->LE_selectedFilesFolders->setText(Iconfilesysmodel->filePath(index));
        else if(Iconfilesysmodel->fileInfo(index).isFile())
            ui->LE_selectedFilesFolders->setText(Iconfilesysmodel->filePath(index));
        else
            ui->LE_selectedFilesFolders->clear();
    }
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::on_TV_BrowseArea_clicked(const QModelIndex &index)
{
    QTranslator translator;
    translator.load(QString(TRANSLATIONLINK) + "/LCore.qm");
    qApp->installTranslator(&translator);
    qDebug()<<"index.isValid()2"<<index.isValid()<<"\n"<<ui->PB_Open->text()<<"\n"<<tr("Open");
    if(index.isValid() && ui->PB_Open->text() == tr("Open"))
    {
        ui->PB_Open->setEnabled(true);

        if(FolderSelectionMode && Iconfilesysmodel->fileInfo(index).isDir())
            ui->LE_selectedFilesFolders->setText(Iconfilesysmodel->filePath(index));
        else if(!FolderSelectionMode && Iconfilesysmodel->fileInfo(index).isFile())
            ui->LE_selectedFilesFolders->setText(Iconfilesysmodel->filePath(index));
        else
            ui->LE_selectedFilesFolders->clear();
    }
}

// cppcheck-suppress unusedFunction
void CustomFileDialog::directoryModified(QString dirPath)
{
    QDir chkdir;
    if(!chkdir.exists(dirPath))
    {
        filesyswatcher->removePath(dirPath);
        on_PB_parentDirectory_clicked();
    }
}
