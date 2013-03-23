# Author: Xuemin Zhao <xmzhao1986@gmail.com>

cc_library(
  name = "opencv_core",
  prebuilt = 1,
  deps = [
    "#rt",
  ]
)

cc_library(
  name = "opencv_highgui",
  prebuilt = 1,
  deps = [
    ":opencv_core",
    "#png",
    "#jpeg",
    "#tiff",
    "#jasper",
    "//thirdparty/opencv2/share/OpenCV/3rdparty:IlmImf",
    "//thirdparty/opencv2/share/OpenCV/3rdparty:libwebp",
  ],
)

cc_library(
  name = "opencv_imgproc",
  prebuilt = 1,
  deps = [
    ":opencv_core",
  ],
)

cc_library(
  name = "opencv_flann",
  prebuilt = 1,
  deps = [
    ":opencv_core",
  ],
)

cc_library(
  name = "opencv_features2d",
  prebuilt = 1,
  deps = [
    ":opencv_flann",
    ":opencv_imgproc",
  ],
)

cc_library(
  name = "opencv_objdetect",
  prebuilt = 1,
  deps = [
    ":opencv_imgproc",
  ],
)

cc_library(
  name = "opencv_video",
  prebuilt = 1,
  deps = [
    ":opencv_core",
  ],
)

cc_library(
  name = "opencv_calib3d",
  prebuilt = 1,
  deps = [
    ":opencv_core",
  ],
)

cc_library(
  name = "opencv_ml",
  prebuilt = 1,
  deps = [
    ":opencv_core",
  ],
)

cc_library(
  name = "opencv",
  deps = [
    ":opencv_core",
    ":opencv_highgui",
    ":opencv_imgproc",
    ":opencv_features2d",
    ":opencv_objdetect",
    ":opencv_video",
    ":opencv_calib3d",
    ":opencv_ml",
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
    "share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml",
  ],
  warning = "no",
)
