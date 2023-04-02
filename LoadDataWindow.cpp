#include "LoadDataWindow.h"
#include "qmessagebox.h"
#include "ui_LoadWindow.h"
#include "MainApp.h"
LoadDataWindow::LoadDataWindow(QWidget *parent, FileHandling* fileProgram) :
    QDialog(parent),FileHandlingProgram(fileProgram),
    ui(new Ui::LoadWindow)
{
    fileProgram->setGUI(this);
    ui->setupUi(this);
    connect(fileProgram,SIGNAL(studentsLoaded(QString)),this,SLOT(on_loadedStudents_OK(QString)));
    connect(fileProgram,SIGNAL(questionsLoaded(QString)),this,SLOT(on_loadedQuestions_OK(QString)));
}

LoadDataWindow::~LoadDataWindow()
{
    delete ui;
}

void LoadDataWindow::on_loadStudents_clicked()
{
    FileHandlingProgram->chooseStudentsFilepath();
    try {
        FileHandlingProgram->loadStudents();
    }
    catch(std::runtime_error e) {
        QMessageBox msg(this);
        msg.setText(e.what());
        msg.show();
        msg.exec();
    }

}
void LoadDataWindow::on_loadQuestions_clicked()
{
    FileHandlingProgram->chooseQuestionsFilepath();
    try {
        FileHandlingProgram->loadQuestions();
    }
    catch(std::runtime_error e) {
        QMessageBox msg(this);
        msg.setText(e.what());
        msg.show();
        msg.exec();
    }

}
void LoadDataWindow::on_loadedStudents_OK(QString studentsFilepath)
{
    ui->studentsFilepath->setText(studentsFilepath);
}

void LoadDataWindow::on_loadedQuestions_OK(QString questionsFilepath)
{
    ui->questionFilepath->setText(questionsFilepath);
}

