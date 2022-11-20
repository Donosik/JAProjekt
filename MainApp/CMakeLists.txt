cmake_minimum_required(VERSION 3.22)
project(MainApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(MainApp main.cpp Application.cpp Application.h WindowData.h RadioButton.cpp RadioButton.h GroupRadioButton.cpp GroupRadioButton.h IView.h LibraryWrapper.cpp LibraryWrapper.h IStatusObserver.h StatusObservable.cpp StatusObservable.h Button.cpp Button.h Status.h ImageButton.cpp ImageButton.h ImageLoader.cpp ImageLoader.h ResultImage.cpp ResultImage.h ImageObservable.cpp ImageObservable.h IImageObserver.h ShowTime.cpp ShowTime.h ITimeObserver.h TimeObservable.cpp TimeObservable.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(MainApp sfml-system sfml-window sfml-graphics sfml-audio sfml-network)