//
// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#include "opencv/opencv.hpp"

#include "gtest/gtest.h"

const char* kFilename = "testdata/lena.jpg";

TEST(OpencvTest, Opencv) {
  IplImage* img = cvLoadImage(kFilename, CV_LOAD_IMAGE_COLOR);
  EXPECT_TRUE(img != NULL);
  cvReleaseImage(&img);
}
