# Author       : Xuemin Zhao <xmzhao1986@gmail.com>
# Created Time : 2013-03-24
# Description  :

cc_library(
  name = "opencv",
  deps = [
    "//thirdparty/opencv2:opencv"
  ],
)

cc_test(
  name = "opencv_test",
  srcs = "opencv_test.cc",
  deps = [
    ":opencv",
  ],
  testdata = [
    ("//thirdparty/opencv2/testdata", "testdata")
  ],
  warning = "no",
)
