#include "models/avfsfileinfo.h"
#include <gtest/gtest.h>

namespace {
class TestAVFSFileInfo : public testing::Test
{
public:
    void SetUp() override
    {
        std::cout << "start TestAVFSFileInfo";
        info = new AVFSFileInfo(DUrl("avfs:///test.file"));
    }

    void TearDown() override
    {
        std::cout << "end TestAVFSFileInfo";
    }

public:
    AVFSFileInfo *info;
};
} // namespace

TEST_F(TestAVFSFileInfo, canRename)
{
    EXPECT_FALSE(info->canRename());
}

TEST_F(TestAVFSFileInfo, isWritable)
{
    EXPECT_FALSE(info->isWritable());
}

TEST_F(TestAVFSFileInfo, canShare)
{
    EXPECT_FALSE(info->canShare());
}

TEST_F(TestAVFSFileInfo, canIteratorDir)
{
    EXPECT_TRUE(info->canIteratorDir());
}

TEST_F(TestAVFSFileInfo, isDir)
{
    EXPECT_FALSE(info->isDir());
}

TEST_F(TestAVFSFileInfo, canManageAuto)
{
    EXPECT_FALSE(info->canManageAuth());
}

TEST_F(TestAVFSFileInfo, toLocalFile)
{
    EXPECT_STREQ("/test.file", info->toLocalFile().toStdString().c_str());
}

TEST_F(TestAVFSFileInfo, parentUrl)
{
    EXPECT_STREQ("/", info->parentUrl().path().toStdString().c_str());
}
