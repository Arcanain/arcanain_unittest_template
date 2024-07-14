# arcanain unittest

## 1.カバレッジツールの導入
gcovのインストール

```bash
sudo apt update
sudo apt install gcc g++
```

インストールが完了したら、gcovのバージョンを確認して、正しくインストールされていることを確認

```bash
gcov --version
```

lcovのインストール

```bash
sudo apt update
sudo apt install lcov
```

インストールが完了したら、lcovのバージョンを確認して、正しくインストールされていることを確認

```bash
lcov --version
```

## 2. 単体テスト(unit test)の手順

### 2.1 nodeの作成

### 2.2 nodeのbuild

### 2.3 テストコードの作成

次に、Google Testを使用してテストコードを作成します。

#### test_simple_node.cpp

まず、`test`ディレクトリを作成し、その中にテストファイルを作成します。

```bash
mkdir -p ~/ros2_ws/src/simple_node/test
```

#### test/test_simple_node.cpp

### 2.4 CMakeLists.txtの設定

CMakeLists.txtファイルを編集して、カバレッジ測定用の設定を追加します。

```cmake
cmake_minimum_required(VERSION 3.5)
project(simple_node)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

# Add executable
add_executable(simple_node src/simple_node.cpp)
ament_target_dependencies(simple_node rclcpp)

# Add gtest
ament_add_gtest(test_simple_node test/test_simple_node.cpp)
if(TARGET test_simple_node)
  ament_target_dependencies(test_simple_node rclcpp)
endif()

# Enable code coverage
if(COVERAGE)
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message("Build with coverage information")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  endif()
endif()

install(TARGETS
  simple_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
```

### 2.5 ビルドとテストの実行

次に、ビルドディレクトリを作成し、ビルドとテストを実行します。

```bash
cd ~/ros2_ws
colcon build --cmake-args -DCOVERAGE=ON
colcon test
```

### 2.6 カバレッジレポートの生成

最後に、`lcov`を使用してカバレッジ情報を収集し、HTMLレポートを生成します。

```bash
# カバレッジ情報の収集
lcov --capture --directory . --output-file coverage.info

# システムヘッダファイルを除外
lcov --remove coverage.info '/usr/*' --output-file coverage.info

# HTMLレポートの生成
genhtml coverage.info --output-directory coverage_report
```

### 2.7 カバレッジレポートの確認

生成されたHTMLレポートをブラウザで確認します。`coverage_report/index.html`を開くことで、カバレッジレポートを確認できます。
