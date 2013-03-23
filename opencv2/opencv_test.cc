// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#include "thirdparty/opencv2/opencv.hpp"

#include <stdio.h>

#include "gtest/gtest.h"

namespace cv {

template<>
inline void Ptr<FILE>::delete_obj() {
  fclose(obj);
  printf("file closed\n");
}

}  // namespace cv

TEST(OpencvTest, Ptr) {
  cv::Ptr<FILE> f(fopen("myfile.txt", "w"));
  EXPECT_FALSE(f.empty());
  fprintf(f, "HAHA\n");
}
