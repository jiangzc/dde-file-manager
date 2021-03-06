#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "dfmevent.h"
#include <QComboBox>

#define private public
#include <views/dstatusbar.h>


TEST(DstatusbarTest,init){
    DStatusBar w;

    EXPECT_NE(nullptr, w.m_scaleSlider);
    EXPECT_TRUE(nullptr == w.m_rejectButton);
    EXPECT_TRUE(nullptr == w.m_lineEdit);
    EXPECT_TRUE(nullptr == w.m_comboBox);
//    EXPECT_TRUE(nullptr == w.m_lineEditLabel);
//    EXPECT_TRUE(nullptr == w.m_comboBoxLabel);
}

TEST(DstatusbarTest, mode){
    DStatusBar w;
    w.m_mode = DStatusBar::Mode::Normal;
    auto temp1 = w.mode() == DStatusBar::Mode::Normal;
    EXPECT_TRUE(temp1);

    w.m_mode = DStatusBar::Mode::DialogOpen;
    auto temp2 = w.mode() == DStatusBar::Mode::DialogOpen;
    EXPECT_TRUE(temp2);

    w.m_mode = DStatusBar::Mode::DialogSave;
    auto temp3 = w.mode() == DStatusBar::Mode::DialogSave;
    EXPECT_TRUE(temp3);
}

TEST(DstatusbarTest, setMode){
    DStatusBar w;
    auto temp1 = w.mode() == DStatusBar::Mode::Normal;
    EXPECT_TRUE(temp1);
}

TEST(DstatusbarTest, setComBoxItems){
    DStatusBar w;

    w.setMode(DStatusBar::Mode::Normal);
    EXPECT_TRUE(nullptr == w.m_comboBox);

    w.setMode(DStatusBar::Mode::DialogSave);
    QStringList temp1{"aa" , "bb" , "cc" , "dd"};
    w.setComBoxItems(temp1);
    auto temp = temp1.size() == w.m_comboBox->count();
    EXPECT_TRUE(temp);

}

TEST(DstatusbarTest, scalingSlider){
    DStatusBar w;
    EXPECT_TRUE(w.scalingSlider() == w.m_scaleSlider);
}

TEST(DstatusbarTest, acceptButton){
    DStatusBar w;
    EXPECT_TRUE(w.acceptButton() == w.m_acceptButton);
    w.m_mode = DStatusBar::Mode::DialogSave;
    EXPECT_TRUE(w.acceptButton() == w.m_acceptButton);
}

TEST(DstatusbarTest, rejectButton){
    DStatusBar w;
    EXPECT_TRUE(w.rejectButton() == w.m_rejectButton);
    w.m_mode = DStatusBar::Mode::DialogSave;
    EXPECT_TRUE(w.rejectButton() == w.m_rejectButton);
}

TEST(DstatusbarTest, lineEdit){
    DStatusBar w;
    EXPECT_TRUE(w.lineEdit() == w.m_lineEdit);
    w.m_mode = DStatusBar::Mode::DialogSave;
    EXPECT_TRUE(w.lineEdit() == w.m_lineEdit);
}

TEST(DstatusbarTest, comboBox){
    DStatusBar w;
    EXPECT_TRUE(w.comboBox() == w.m_comboBox);
    w.m_mode = DStatusBar::Mode::DialogSave;
    EXPECT_TRUE(w.comboBox() == w.m_comboBox);
}

TEST(DstatusbarTest, sizeHint){

    QWidget wgt;
    DStatusBar w;
    auto layot_size = w.layout()->sizeHint();
    auto actualValue = w.sizeHint().height();
    auto expectedValue = qMax(25, layot_size.height());
    EXPECT_TRUE(actualValue == expectedValue);
}

TEST(DFMElidLabelTest, setText){
    DFMElidLabel ww;
    ww.setText("aa");
    EXPECT_TRUE(ww.m_text == "aa");
}

TEST(DstatusbarTest, computerSize){
    int pid = getpid();
    const QString path = QString("file:///proc/%0/exe").arg(pid);
    DStatusBar w;
    DUrlList list = {DUrl(path)};
    EXPECT_NE(0,w.computerSize(list));
}

TEST(DstatusbarTest, computerFolderContains){
    int pid = getpid();
    const QString path = QString("file:///proc/%0").arg(pid);
    DStatusBar w;
    w.initJobConnection();
    DUrlList list = {DUrl(path)};
    EXPECT_NE(0,w.computerFolderContains(list));
}

TEST(DstatusbarTest, setLoadingIncatorVisible){
    DStatusBar w;
    w.setLoadingIncatorVisible(false,"ok");
    EXPECT_TRUE(w.m_label->text().isEmpty());

    w.setLoadingIncatorVisible(true,"ok");
    EXPECT_EQ(QString("ok"),w.m_label->text());
}

TEST(DstatusbarTest, updateStatusMessage){
    DStatusBar w;
    w.updateStatusMessage();
    EXPECT_TRUE(w.m_label->text().isEmpty());

    w.m_folderCount = 1;
    w.m_folderContains = 1;
    w.updateStatusMessage();
    EXPECT_FALSE(w.m_label->text().isEmpty());

    w.m_fileCount = 1;
    w.updateStatusMessage();
    EXPECT_FALSE(w.m_label->text().isEmpty());
}

TEST(DstatusbarTest, itemSelected_with_empty){
    DStatusBar w;
    DFMEvent event(&w);
    event.setWindowId(0);
    event.setData({});
    w.itemSelected(event, 1);

    EXPECT_NE(nullptr,w.m_fileStatisticsJob);
}





























