#!/usr/bin/env bash
#
# Author: Xuemin Zhao <xmzhao1986@gmail.com>

src=~/tmp/opencv2
cv2=~/github/thirdparty/opencv2
cv=~/github/thirdparty/opencv

mkdir -p $cv2
cp -r $src/include/opencv2/* $cv2
cp -r $src/lib $cv2
cp -r $src/bin $cv2
cp -r $src/share $cv2

mkdir -p $cv
cp -r $src/include/opencv/* $cv
