
cc_library(
  name = "gtest",
  srcs = [
    "src/gtest-all.cc",
  ],
  incs = [
    ".",
    'include',
  ],
  deps = '#pthread',
  warning = 'no'
)

cc_library(
  name = "gtest_main",
  srcs = [
    "src/gtest_main.cc",
  ],
  incs = "include",
  deps = [
    ":gtest",
  ],
)
