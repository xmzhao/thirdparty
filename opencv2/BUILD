# Author: Xuemin Zhao <xmzhao1986@gmail.com>

cc_library(
  name = "opencv_core",
  prebuilt = 1,
  deps = [
    "#rt",
  ]
)

cc_library(
  name = "opencv",
  deps = [
    ":opencv_core",
  ],
)

cc_test(
  name = "opencv_test",
  srcs = "opencv_test.cc",
  deps = [
    ":opencv",
  ],
  testdata = [
    "testdata",
  ],
  warning = "no",
)
