// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#include "thirdparty/opencv2/opencv.hpp"

#include <stdio.h>

#include <string>
#include <vector>

#include "gtest/gtest.h"

namespace cv {

template<>
inline void Ptr<FILE>::delete_obj() {
  fclose(obj);
  printf("file closed\n");
}

}  // namespace cv

const std::string kFilename = "testdata/lena.jpg";
const std::string kCascadeClassifierFilename =
    "share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";

TEST(OpencvTest, Core) {
  cv::Ptr<FILE> f(fopen("myfile.txt", "w"));
  EXPECT_FALSE(f.empty());
  fprintf(f, "HAHA\n");
}

TEST(OpencvTest, Highgui) {
  cv::Mat img = cv::imread(kFilename, CV_LOAD_IMAGE_COLOR);
  EXPECT_FALSE(img.empty());
  EXPECT_TRUE(cv::imwrite("tmp.png", img));
}

TEST(OpencvTest, Imgproc) {
  cv::Mat img = cv::imread(kFilename, CV_LOAD_IMAGE_COLOR);
  cv::Mat img2;
  cv::bilateralFilter(img, img2, 20, 20.0, 20.0);
  EXPECT_TRUE(cv::imwrite("filter.tiff", img2));
}

TEST(OpencvTest, Features2d) {
  cv::Mat img = cv::imread(kFilename, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::KeyPoint> kps;
  FAST(img, kps, 5, true);
}

TEST(OpencvTest, Objdetect) {
  cv::CascadeClassifier cc(kCascadeClassifierFilename);
  EXPECT_FALSE(cc.empty());
}

TEST(OpencvTest, Video) {
  cv::KalmanFilter kf;
}

TEST(OpencvTest, Calib3d) {
  cv::StereoBM bm;
}

TEST(OpencvTest, Ml) {
  CvKNearest knn;
}
